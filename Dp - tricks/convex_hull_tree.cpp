// https://codeforces.com/contest/1083/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
typedef pair<int,int> pii;

struct line{
    int m , c;
    int eval(int x){ return m*x + c; }
    long double intersectX(line l){ return ((long double)(c - l.c)) / (l.m - m); }
};

struct CHT{
    deque<line> dq;
    // maintaining a upper convex hull for maximizing problem 
    void add(line l){
        while(dq.size() >= 2 && l.intersectX(dq[0]) >= dq[0].intersectX(dq[1])){
            dq.pop_front();
        }
        dq.push_front(l);
    }
    int query(int x){
        while(dq.size() >= 2 && dq.back().intersectX(dq[dq.size() - 2]) >= x /*dq.back().eval(x) <= dq[dq.size() - 2].eval(x)*/){
            dq.pop_back();
        }
        return dq.back().eval(x);
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int,pii>> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i].ff >> v[i].ss.ff >> v[i].ss.ss;
    }
    sort(v.begin() , v.end() , [&](pair<int,pii>&a , pair<int,pii>&b){
        if(a.ff == b.ff){
            return a.ss.ff > b.ss.ff;
        }else{
            return a.ff < b.ff;
        }
    });
    CHT hull;
    hull.add({0 , 0});
    int res = 0;
    for(int i = 0 ;i < n ; i++){
        int c = v[i].ff * v[i].ss.ff - v[i].ss.ss + hull.query(v[i].ss.ff);
        res = max(res , c);
        hull.add({-v[i].ff , c});
    }
    cout << res << endl;
}