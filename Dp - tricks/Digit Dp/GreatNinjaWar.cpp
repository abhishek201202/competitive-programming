// https://www.hackerearth.com/problem/algorithm/sallu-bhai-and-ias-8838ac8d/
#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define int long long int
#define ALL(x) x.begin(), x.end()

// dp(idx, sum, mask, isBounded)
int dp[13][2525][515], val[10];
const int LCM = 2520; // LCM(1, 2, 3 ... 7, 8, 9)


int pow(int a , int b , int m){
    if(a == 0) return 0;
    a %= m;
    int res = 1;
    while(b > 0){
        if(b & 1ll){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1ll;
    }
    return res;
}

void pre(){
    val[0] = 0;
    for(int i = 1; i < 10; i++){
        val[i] = pow(i, i, LCM);
    }
}

vt<int> g(int num){
    vt<int> res;
    while(num){
        res.push_back(num%10);
        num /= 10;
    }
    reverse(ALL(res));
    return res;
}

int rec(vt<int> &digits, int idx, int sum, int mask, int isBounded){
    if(idx == digits.size()){
        for(int i = 1; i <= 9; i++){
            if(mask & (1ll << i)){
                if(sum%i != 0) return 0;
            }
        }
        return 1;
    }
    int &DP = dp[idx][sum][mask];
    if(!isBounded && DP != -1) return DP; 
    int mxDigit = isBounded ? digits[idx] : 9;
    int res = 0;
    for(int d = 0; d <= mxDigit; d++){
        int newSum = d ? (sum + val[d]) : sum;
        int newMask = d ? (mask|(1<<d)) : mask;
        if(isBounded && d == mxDigit){
            res += rec(digits, idx + 1, newSum%LCM, newMask, 1);
        }else{
            res += rec(digits, idx + 1, newSum%LCM, newMask, 0);
        }
    }
    if(!isBounded) DP = res;
    return res;
}


int f(int num){
    vt<int> digits = g(num);
    memset(dp, -1, sizeof dp);
    return rec(digits, 0, 0, 0, 1);
}

void test_cases(){
    int l, r; cin >> l >> r;
    int res = f(r);
    res -= f(l - 1);
    cout << res << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    pre();
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}


