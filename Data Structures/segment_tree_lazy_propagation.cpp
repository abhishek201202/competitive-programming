#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


// horrible queries.....[coding ninjas]
struct SegmentTree{
    int n;
    vector<int> a, tree, lazy;
    SegmentTree(vector<int> &a){
        this -> a = a;
        n = a.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void pushdown(int node, int si , int ei){
        if(lazy[node] != 0){
            tree[node] += (ei - si + 1) * lazy[node];
            if(si != ei){
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int l, int r, int val, int node, int si , int ei){
        pushdown(node, si , ei);     // previous updation
        if(l > ei || r < si) return; // no overlapping
        if(l <= si && r >= ei){      // complete overlapping
            tree[node] += (ei - si + 1) * val;
            if(si != ei){
                lazy[2 * node] +=  val;
                lazy[2 * node + 1] +=  val;
            }
            return;
        }
        // partial overlap
        int mid = (si + ei)/2;
        update(l, r, val, 2 * node, si , mid);
        update(l, r, val, 2 * node + 1, mid + 1, ei);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int l, int r, int val){ update(l, r, val, 1, 0, n - 1);}


    int qry(int l, int r, int node, int si, int ei){
        if(l > ei || r < si) return 0;
        pushdown(node, si, ei);
        if(l <= si && r >= ei) return tree[node];
        int mid = (si + ei) / 2;
        int L = qry(l, r, 2 * node, si, mid);
        int R = qry(l, r, 2 * node + 1, mid + 1, ei);
        return L + R;
    }
    int qry(int l, int r){ return qry(l, r, 1, 0, n - 1);}
};

int32_t main(){
    int t = 1;
    cin >> t;
    for(int i  =  0 ;i  < t ; i++){
         int n, q; cin >> n >> q;
        vector<int> a(n, 0);
        SegmentTree seg(a);
        while(q--){
            int d; cin >> d;
            if(d == 0){
                int l, r, val; cin >> l >> r >> val;
                seg.update(l - 1, r - 1, val);
            }else{
                int l, r; cin >> l >> r;
                cout << seg.qry(l - 1, r - 1) << endl;
            }
        }
    }
}