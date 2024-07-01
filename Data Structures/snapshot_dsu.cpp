/*
https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/
*/

class SnapshotArray {
public:
    int snapId = 0;
    vector<vector<array<int, 2>>> snapshot;
    SnapshotArray(int length) {
        snapshot = vector<vector<array<int, 2>>>(length, {{0, 0}}); // idx -> [{snapId, val}]
    }
    
    void set(int index, int val) {
        if(snapshot[index].back()[0] == snapId) {
            snapshot[index].back()[1] = val;
        }else{
            snapshot[index].push_back({snapId, val});
        }
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        vector<array<int, 2>> &a = snapshot[index];
        auto it = upper_bound(a.begin(), a.end(), array<int, 2>({snap_id, (int)1e9}));
        it--;
        return (*it)[1];
    }
};

class SnapshotDSU: public SnapshotArray {
public:
    SnapshotDSU(int n): SnapshotArray(n) {
        for(int i = 0; i < n; i++) {
            set(i, -1);
        }
    }
    int find(int u, int snapId) {
        int pu = get(u, snapId);
        if(pu < 0) return u;
        return find(pu, snapId);
    }

    void merge(int u, int v) {
        int pu = find(u, snapId);
        int pv = find(v, snapId);
        if(pu != pv) {
            set(pv, pu);
        }
    }

    bool check(int u, int v, int snapId) {
        return find(u, snapId) == find(v, snapId);
    }
};