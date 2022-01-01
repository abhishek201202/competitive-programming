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
vector<int> EulerianForDirected(vector<array<int, 2>> &edges, int n){
    vector<vector<int>> adj(n, vector<int>());
    vector<int> in(n, 0), out(n, 0);
    for(auto &[u, v] : edges){
        adj[u].push_back(v);
        in[v]++, out[u]++;
    }

    // this condition is only for euler path if circuit needed then comment this for loop
    int sv = -1, ev = -1;
    for(int i = 0; i < n; i++){
        if(out[i] - in[i] == 1){
            if(sv == -1) sv = i;
            else return {};
        }
        if(in[i] - out[i] == 1){
            if(ev == -1) ev = i;
            else return {};
        }
    }
    for(int i = 0; i < n; i++){
        if(i == sv || i == ev) continue;
        if(in[i] != out[i]) return {};
    }

    if(sv == -1) sv = 0;
    vector<int> path;
    stack<int> st; st.push(sv);
    while(st.size()){
        int u = st.top();
        if(adj[u].empty()){
            path.push_back(u);
            st.pop();
        }else{
            int v = adj[u].back(); adj[u].pop_back();
            st.push(v);
        }
    }
    if(path.size() != edges.size() + 1) return {};
    reverse(path.begin() , path.end());
    return path;
}




// For Undirected Graph
// Eulerian Path    :: either every vertex has even degree 
//                     or exactly 2 vertices have odd degree 
// Eulerian Circuit :: every vertex has an even degree
vector<int> EulerianForUnDirected(vector<array<int, 2>> &edges, int n){
    vector<vector<array<int, 2>>> adj(n, vector<array<int, 2>>());
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> deg(n, 0);
    int cntOdd = 0, V = 0;
    for(int u = 0; u < n; u++){
        deg[u] = adj[u].size();
        if(deg[u]&1) {cntOdd++, V = u;}
    }
    if(cntOdd != 0) return {}; // for circuit
    // if(cntOdd != 0 && cntOdd != 2) return {}; // for path
    
    vector<int> path, vis(edges.size(), 0);
    function<void(int)> dfs = [&](int u){
        while(adj[u].size()){
            auto &[v, i] = adj[u].back(); adj[u].pop_back();
            if(vis[i]) continue;
            vis[i] = 1;
            dfs(v);
            path.push_back(u);
        }
    };
    path.push_back(V);
    dfs(V);
    if(path.size() != edges.size() + 1) return {};
    return path;
}



int32_t main(){
    int n, m; cin >> n >> m;
    vector<array<int, 2>> edges(m);
    for(int i = 0; i < m; i++){
    	cin >> edges[i][0] >> edges[i][1], edges[i][0]--, edges[i][1]--;
    }

    vector<int> P = EulerianForDirected(edges, n);
    for(int i = 0; i < P.size() ; i++){
        cout << P[i] + 1 << " ";
    }
    cout << endl;
}