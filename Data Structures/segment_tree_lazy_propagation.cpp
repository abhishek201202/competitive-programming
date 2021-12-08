#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;




struct Node{
    int s;
    Node(){
        s = 0;
    }
    void update(int val){ // node update
        s += val;
    }
    Node operator+(const Node &v) const{ // node merge 
        Node res;
        res.s = s + v.s;
        return res;
    }
};

struct Lazy{
    int val;
    Lazy(){
        val = 0;
    }
    void update(int val){
        this -> val += val;
    }
};

struct SegmentTree{
    int n;
    vector<int> a;
    vector<Node> T;
    vector<Lazy> L;

    SegmentTree(vector<int> &a){
        this -> a = a;
        n = a.size();
        T.resize(4 * n);
        L.resize(4 * n);
    }

    void pushdown(int root, int si, int ei){
        if(L[root].val != 0){
            T[root].update((ei - si + 1) * L[root].val);
            if(si != ei){
                L[2 * root].update(L[root].val);
                L[2 * root + 1].update(L[root].val);
            }
            L[root].val = 0;
        }
    }
    
    void build(int root, int si, int ei){
        if(si == ei){ T[root].update(a[si]); return; }
        int mid = (si + ei)/2;
        build(2 * root, si, mid);
        build(2 * root + 1, mid + 1, ei);
        T[root] = T[2 * root] + T[2 * root + 1];
    }
    void build() { build(1, 0, n - 1); }

    Node qry(int l, int r, int root, int si, int ei){
        if(l > ei || r < si) return Node();
        pushdown(root, si, ei);
        if(l <= si && r >= ei) return T[root];
        int mid = (si + ei)/2;
        Node L = qry(l, r, 2 * root, si, mid);
        Node R = qry(l, r, 2 * root + 1, mid + 1, ei);
        return L + R;
    }
    int qry(int l, int r) { return qry(l, r, 1, 0, n - 1).s;}

    void update(int l, int r, int val, int root, int si, int ei){
        pushdown(root, si, ei);
        if(l > ei || r < si) return;
        if(l <= si && r >= ei){
            T[root].update((ei - si + 1) * val); // change acc. to Qns
            if(si != ei){
                L[2 * root].update(val);
                L[2 * root + 1].update(val);
            }
            return;
        }
        int mid = (si + ei) / 2;
        update(l, r, val, 2 * root, si, mid);
        update(l, r, val, 2 * root + 1, mid + 1 , ei);
        T[root] = T[2 * root] + T[2 * root + 1];
    }
    void update(int l, int r, int val){ update(l, r, val, 1, 0, n - 1);}
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