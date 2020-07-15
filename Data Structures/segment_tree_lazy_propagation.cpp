#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


const int N  =  1e6 + 5;
int n , c ;
int arr[N] , tree[4*N] , lazy[4*N];

// horrible queries.....[coding ninjas]

void pushdown(int si , int ei , int index){
    if(lazy[index] != 0){
        tree[index] += (ei - si + 1) * lazy[index];
        if(si != ei){
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}


void update(int si , int ei , int index , int l , int r , int value){
    if(r < l) return;
    pushdown(si , ei , index); // previous updation
    if(l > ei || r < si) return; // no overlapping
    if(l <= si && r >= ei){ // complete overlapping
        tree[index] += (ei - si + 1)*value;
        if(si != ei){
            lazy[2*index] +=  value;
            lazy[2*index + 1] +=  value;
        }
        return;
    }
    // partial overlap
    int mid = (si + ei)/2;
    update(si , mid , 2*index  , l , r , value);
    update(mid+ 1 , ei , 2*index + 1 , l , r , value);
    tree[index] = tree[2*index] + tree[2*index + 1];
}


int query(int si , int ei , int index , int l , int r){
    if(l > ei || r < si) return 0;
    pushdown(si , ei , index);
    if(l <= si && r >= ei) return tree[index];
    int mid = (si + ei)/2;
    int ans1 = query(si , mid , 2 * index  , l , r);
    int ans2 = query(mid + 1 , ei , 2 * index + 1 , l , r);
    return ans1 + ans2;
}


void solve(){
    cin >> n >> c;
    while(c--){
        int d; cin >> d;
        if(d == 0){
            int si , ei , value; cin >> si >> ei >> value;
            update(0 , n-1 , 1 , si-1 , ei-1 , value);
        }else{
            int si , ei ; cin >> si >> ei;
            cout<<query(0 , n-1 , 1 , si-1 , ei-1)<<endl;
        }
    }
}

int32_t main(){
    int t = 1;
    cin >> t;
    for(int i  =  0 ;i  < t ; i++){
        memset(arr , 0 , sizeof(arr));
        memset(tree , 0 , sizeof(tree));
        memset(lazy , 0 , sizeof(lazy));
        solve();
    }
}