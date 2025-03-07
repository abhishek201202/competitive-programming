// https://www.codechef.com/problems/ICPC16E
#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;


const int mod = 1e9 + 7;

int power(int a,int b,int m){
	int res = 1; 
	a %= m;
	while(b > 0){ 
		if(b&1) res = (res*a)%m;
		b >>= 1ll;
		a = (a*a)%m;
	}
	return res;
}

void solve(){
	int n,c; cin >> n >> c;
	if(n%2 == 0){
		// a
		int aa = n % (mod - 1);
		aa = (aa * aa) % (mod - 1);
		aa = (5 * aa) % (mod - 1);
		int a = power(c , aa , mod);
		// b
		int bb = (n/2) % (mod - 1);
		bb = (bb * bb) % (mod - 1);
		bb = (5 * bb) % (mod - 1);
		int b = (2 * power(c , bb , mod)) % mod;
		// c
		int cc = (n/2) % (mod - 1);
		cc=(cc * (n%(mod - 1))) % (mod - 1);
		cc=(cc * 5)%(mod - 1);
		cc = power(c , cc , mod);
		// ans 
		int ans=(a % mod + b % mod) % mod;
		ans=(ans % mod + cc % mod) % mod;
		ans=(ans % mod * power(4 , mod - 2, mod) % mod) % mod;
		cout << ans << endl;
	}else{
		// a
		int aa = n % (mod - 1);
		aa = (aa * aa) % (mod - 1);
		aa = (5 * aa) % (mod - 1);
		int a = power(c , aa , mod);
		// b
		int bb = (n + 1) / 2;
		bb %= (mod - 1);
		bb = (bb * bb) % (mod - 1);
		bb = (bb + 1) % (mod - 1);
		bb = (bb + ( (n%(mod-1)) * (n%(mod-1)) ) % (mod-1)) % (mod - 1);
		bb = (bb - (((n + 1) / 2) % (mod - 1)) + (mod - 1)) % (mod - 1);
		int b = (2 * power(c , bb , mod)) % mod;
		// c
		int cc = (n + 1) / 2;
		cc %= (mod - 1);
		cc = (3 * cc) % (mod - 1);
		cc = ((n%(mod-1)) * cc) % (mod - 1);
		cc = (cc + ( (n%(mod - 1)) * (n%(mod - 1)) ) % (mod - 1)) % (mod - 1);
		cc = (cc - (n % (mod - 1)) + (mod - 1)) % (mod - 1);
		cc = (cc + 1)%(mod - 1);
		cc = (cc - (((n + 1)/2)%(mod - 1)) + (mod - 1) )%(mod - 1);
		cc = power(c , cc , mod);
		// ans 
		int ans = (a + b) % mod;
		ans = (ans + cc) % mod;
		ans = (ans * power(4 , mod - 2 , mod)) % mod;
		cout << ans << endl;
	}
}
int32_t main(){
	int tt = 1; cin >> tt;
	for(int T = 1 ; T <= tt ; T++){
		solve();
	}
}