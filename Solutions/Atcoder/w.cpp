#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1,T2> &p){ os << '{' << p.first << ", " << p.second << '}'; return os;}
template<typename C,typename T = decay_t<decltype(*begin(declval<C>()))>,typename enable_if<!is_same<C,string>::value>::type* = nullptr>
ostream &operator<<(ostream &os, const C &container){bool first = true; stringstream ss; ss << '[';for(const auto &x : container){ if(!first) ss << ", "; first = false; ss << x;} ss << ']';return os << ss.str();}
vector<string> split(const string& s, char c){ vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return v;}
inline void dbg_out(vector<string>::iterator it){ cerr << endl; }
template<typename T, typename... Args> inline void dbg_out(vector<string>::iterator it, T a, Args... args){ cerr << "[" << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "] "; dbg_out(++it, args...); }
#define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}

#define endl             "\n"
#define ff               first
#define ss               second
#define int              long long
#define dd               long double
#define pb               push_back
#define ALL(x)           x.begin(), x.end()
#define FOR(i, s, e)     for(int i = s; i <= e; i++)
#define FORR(i, s, e)    for(int i = s; i >= e; i--)
typedef pair<int, int>   pii;
typedef pair<int, pii>   piii;

template<typename T> using pbds = tree<T, null_type, less<T>, 
rb_tree_tag ,tree_order_statistics_node_update>; 

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;


struct SegmentTree{
    int n;
    vector<int> a, tree, lazy;
    SegmentTree(int n){
        this -> n = n; 
        a.resize(n, 0);
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void pushdown(int node, int si , int ei){
        if(lazy[node] != 0){
            tree[node] += lazy[node];
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
            tree[node] += val;
            if(si != ei){
                lazy[2 * node] +=  val;
                lazy[2 * node + 1] +=  val;
            }
            return;
        }
        // partial overlap
        int mid = si + (ei - si) / 2;
        update(l, r, val, 2 * node, si , mid);
        update(l, r, val, 2 * node + 1, mid + 1, ei);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int l, int r, int val){ update(l, r, val, 1, 0, n - 1);}


    int qry(int l, int r, int node, int si, int ei){
        pushdown(node, si, ei);
        if(l > ei || r < si) return -1e18;
        if(l <= si && r >= ei) return tree[node];
        int mid = si + (ei - si) / 2;
        int L = qry(l, r, 2 * node, si, mid);
        int R = qry(l, r, 2 * node + 1, mid + 1, ei);
        return max(L, R);
    }
    int qry(int l, int r){ return qry(l, r, 1, 0, n - 1);}
};

vector<vector<array<int, 2>>> ending;

void test_cases(){
    int n, m; cin >> n >> m;
    ending = vector<vector<array<int, 2>>>(n + 1, vector<array<int, 2>>());
    for(int i = 0; i < m; i++){
        int l, r, c; cin >> l >> r >> c;
        ending[r].push_back({l, c});
    }
    SegmentTree seg(n + 1);
    for(int r = 1; r <= n; r++){
        if(r > 1){
            int prev = max(0ll, seg.qry(1, r - 1));
            seg.update(r, r, prev);
        }
        for(auto &[l, c] : ending[r]){
            seg.update(l, r, c);
        }
    }
    cout << max(0ll, seg.qry(1, n)) << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}