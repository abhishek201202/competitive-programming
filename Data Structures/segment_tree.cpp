#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


const int N = 1e5 + 5;
int n , q;
int arr[N] ,tree[4 * N];

// max range query

void build(int node = 1 , int si = 0 ,int ei = n - 1){
	if(si == ei){
		tree[node] = arr[si];
		return;
	}
	int mid = (si + ei)/2;
	build(2 * node , si , mid);
	build(2 * node + 1 , mid + 1 , ei);
	tree[node] = max(tree[2*node] , tree[2*node + 1]);
}

int query(int l , int r , int node = 1 , int si = 0 , int ei = n - 1){
	if(l > ei || r < si){
		return -1; 
	}
	if(l <= si && r >= ei){
		return tree[node];
	}
	int mid = (si + ei)/2;
	int left = query( l , r , 2 * node , si , mid);
	int right = query( l , r , 2 * node + 1 , mid + 1 , ei);
	return max(left , right);
}

void update(int index , int val , int node = 1 , int si = 0, int ei = n - 1){
	if(si == ei){
		tree[node] = val;
		arr[index] = val;
		return;
	}
	int mid = (si + ei)/2;
	if(index <= mid){
		update(index , val , 2 * node , si , mid);
	}else{
		update(index , val , 2 * node + 1 , mid + 1 , ei);
	}
	tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
}



int32_t main(){
	cin >> n >> q;
	for(int i = 0 ; i  <  n ;i++){
		cin >> arr[i];
	}
	build();
	for(int i = 0 ;i  < 4 * n ; i++){
		cout << tree[i] << " ";
	}
	cout << endl;
	cout << query(0 , 0) << endl;
}