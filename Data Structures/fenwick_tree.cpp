#include<bits/stdc++.h>
#define int long long 
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
int n;
int arr[N] , bit[N];

// range sum query.....[1 based indexing]

int query(int index){
	int sum = 0;
	for( ; index > 0 ; index -= index & (-index)){
		sum += bit[index];
	}
	return sum;
}

void update(int index , int val){	
	for( ; index <= n ; index += index&(-index)){
		bit[index] += val;
	}
}

int32_t main(){
	cin >> n;
	for(int i = 1 ; i <=  n ;i++){
		cin >> arr[i];
		update(i , arr[i]);
	}
}