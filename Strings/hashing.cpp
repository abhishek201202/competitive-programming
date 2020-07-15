// vector was giving TLE even without use of push_back
// so always try to use arr instead of vector
// https://codeforces.com/problemset/problem/559/B
// todo(important) : https://www.codechef.com/viewsolution/33286612
#include <bits/stdc++.h>
#define int long long
using namespace std;


const int mod = 1e9 + 7;
const int N = 200010;
const int p = 163; // any prime number
int powP[N] , h1[N] , h2[N];
string a , b;
int n;
// precomputation == >> O(n)
void pre(){
    powP[0] = 1ll;
    int p_pow = p;
    for(int i = 1; i < N ; i ++){
        powP[i] = p_pow;
        p_pow = (p_pow * p) % mod;
    }
}
void hashing(int h[N] , string s){
    h[n - 1] = s[n - 1] % mod;
    for(int i = n - 2 ; i >= 0 ; i--){
        h[i] = (h[i + 1] * p + s[i]) % mod;
    }
}

// O(logn) === >>> O(1)
int hashF(int h[N] , int l , int r){
    int res = h[l];
    if(r + 1 < n){
        res = (res - (h[r + 1]*powP[r - l + 1])%mod + mod) % mod;
    }
    res = (res + mod) % mod;
    return res;
}
bool equal(int l1 , int r1 , int l2 , int r2){
    return hashF(h1 , l1 , r1) == hashF(h2 , l2 , r2) ;
}
bool fun(int l1 , int r1 , int l2 , int r2){
    if((((r1 - l1 + 1) & 1) && ((r2 - l2 + 1) & 1))){
        return equal(l1 , r1 , l2 , r2);
    }
    if(equal(l1 , r1 , l2 , r2)) return true;

    int mid1 = (l1 + r1) / 2;
    int mid2 = (l2 + r2) / 2;
    bool ans1 = (fun(l1 , mid1 , mid2 + 1 , r2)) && 
        fun(mid1 + 1 , r1 , l2 , mid2);
    if(ans1) return true;

    bool ans2 = (fun(l1 , mid1 , l2 , mid2)) &&
        fun(mid1 + 1 , r1 , mid2 + 1 , r2);
    if(ans2) return true;
    
    return false; 
}
void solve(){
    cin >> a >> b;
    n = a.size();
    hashing(h1 , a);
    hashing(h2 , b);
    if(fun(0 , n - 1 , 0 , n - 1)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    pre();
    for(int T = 1 ; T <= t ; T++){
        // cout << "Case #" << T << ": " << endl;
        solve();
    }
    return 0;
}
/*
abc
acb
*/
/*
baaaaa
abaaaa
*/