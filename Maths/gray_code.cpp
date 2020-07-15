#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

// x = n ^ (n >> 1)
int gray_code(int n){
	return n ^ (n >> 1ll);
}

// find that above n
int rev_g(int x){
	int n = 0;
	while(x){
		n ^= x; x >>= 1ll;
	}
	return n;
}

int32_t main(){

}