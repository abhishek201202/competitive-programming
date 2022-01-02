// https://cses.fi/problemset/task/1691
// https://cses.fi/problemset/task/1693
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first 
#define ss second
using namespace std;


// For Directed Graph
// Eulerian Path    :: at most 1 vertex has (out - in == 1)
//                     at most 1 vertex has (in - out == 1)
//                     all other vertices have equal in and out degree
// ((sv = out - in == 1) && (ev == in - out == 1)) when exactly 2 vertex are odd
// Eulerian Circuit :: every vertex has equal in and out degree
// For Undirected Graph
// Eulerian Path    :: either every vertex has even degree 
//                     or exactly 2 vertices have odd degree 
// Eulerian Circuit :: every vertex has an even degree


template<bool isDirected>struct Euler{
    int n, m, sv, ev;
    vector<array<int, 2>> Edges;
    vector<vector<int>> adj;
    vector<int> U, V, in, out, Path;

    Euler(vector<array<int, 2>> _Edges, int _n){
        n = _n, m = _Edges.size(), sv = ev = -1;
        Edges = _Edges;
        adj.resize(n, vector<int>());
        U.resize(m), V.resize(m);
        in.resize(n, 0);
        out.resize(n, 0);
    }

    void add_edge(int u, int v, int e){
        in[v]++, out[u]++;
        U[e] = u, V[e] = v;
        adj[u].push_back(e);
        if(!isDirected) adj[v].push_back(e);
    }
    bool okkDirected(){
        // this condition is only for euler path if circuit needed then comment this for loop
        for(int i = 0; i < n; i++){
            if(out[i] - in[i] == 1){ // for starting vertex
                if(sv == -1) sv = i;
                else return false;
            }else if(in[i] - out[i] == 1){ // for ending vertex
                if(ev == -1) ev = i;
                else return false;
            }
        }
        // for both path and circuit
        for(int i = 0; i < n; i++){
            if(i != sv && i != ev && in[i] != out[i]) return false;
        }
        if(sv == -1) sv = ev = 0;
        return true;
    }
    bool okkUnDirected(){
        int cntOdd = 0;
        for(int i = 0; i < n; i++){
            if((in[i] + out[i])&1) {cntOdd++, sv = i;}
        }
        if(cntOdd != 0) return false; // for circuit
        // if(cntOdd != 0 && cntOdd != 2) return false; // for path
        if(sv == -1) sv = 0;
        return true;
    }

    void build(){
        for(int i = 0; i < m; i++){
            add_edge(Edges[i][0], Edges[i][1], i);
        }
        if(isDirected) {if(!okkDirected()) return;}
        else {if(!okkUnDirected()) return;}
        vector<int> vis(m, 0);
        function<void(int)> dfs = [&](int u){
            while(adj[u].size()){
                int e = adj[u].back(); adj[u].pop_back();
                if(vis[e]) continue;
                vis[e] = 1;
                dfs(U[e] ^ V[e] ^ u);
                Path.push_back(u);
            }
        };
        if(!isDirected) Path.push_back(sv);
        dfs(sv);
        if(isDirected) {
            reverse(Path.begin(), Path.end());
            Path.push_back(ev);
        };
        if(Path.size() != m + 1) Path = vector<int>();
    }
};


int32_t main(){
    int n, m; cin >> n >> m;
    vector<array<int, 2>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1], edges[i][0]--, edges[i][1]--;
    }
    Euler<false> solver(edges, n);
    solver.build();
    vector<int> P = solver.Path;
    if(!P.size()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < P.size() ; i++){
        cout << P[i] + 1 << " ";
    }
    cout << endl;
}