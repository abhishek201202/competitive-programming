// https://codeforces.com/contest/628/problem/D
// A basic template for Digit Dp Problems

#include <bits/stdc++.h>
using namespace std;
#define vt vector

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;


// dp(i, num%m, bounded)
// time => 2000 * 2000 * 2
vt<int> digits;
void g(string num){
    digits.clear();
    for(char c : num){
        digits.push_back(c - '0');
    }
} 

int dp[2005][2005][2];
int ff(int idx, int rem, int isBounded, int m, int D){
    if(idx == digits.size()){
        return rem == 0 ? 1 : 0;
    }
    if(dp[idx][rem][isBounded] != -1) return dp[idx][rem][isBounded];
    int res = 0;
    int mxDigit = isBounded ? digits[idx] : 9;
    for(int d = 0; d <= mxDigit; d++){
        if(idx%2 != 0 && d != D) continue;
        if(idx%2 == 0 && d == D) continue;
        if(isBounded && d == digits[idx]){
            res += ff(idx + 1, (rem*10 + d)%m, 1, m, D);
        }else{
            res += ff(idx + 1, (rem*10 + d)%m, 0, m, D);
        }
        res %= mod;
    }
    return dp[idx][rem][isBounded] = res;
}

int f(string num, int m, int d){
    g(num);
    memset(dp, -1, sizeof dp);
    return ff(0, 0, 1, m, d);
}

int Iterative(string num, int m, int D){
    g(num);
    int n = digits.size();
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;
    for(int i = 0; i < n; i++){
        for(int isBounded : {0, 1}){
            int mxDigit = isBounded ? digits[i] : 9;
            for(int d = 0; d <= mxDigit; d++){
                if(i%2 != 0 && d != D) continue;
                if(i%2 == 0 && d == D) continue;
                for(int rem = 0; rem < m; rem++){
                    if(isBounded && d == mxDigit){
                        dp[i + 1][(rem*10 + d)%m][1] += dp[i][rem][isBounded];
                        dp[i + 1][(rem*10 + d)%m][1] %= mod;
                    }else{
                        dp[i + 1][(rem*10 + d)%m][0] += dp[i][rem][isBounded];
                        dp[i + 1][(rem*10 + d)%m][0] %= mod;
                    }
                }
            }
        }
    }
    return (dp[n][0][0] + dp[n][0][1])%mod;
}

bool okk(string s, int m, int d){
    int n = s.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        if((s[i] - '0') == d && i%2 == 0) return false;
        if((s[i] - '0') != d && i%2 != 0) return false;
        res = (res * 10 + (s[i] - '0'))%m;
    }
    return res == 0;
}


void test_cases(){
    int m, d; cin >> m >> d;
    string a, b; cin >> a >> b;
    int res = Iterative(b, m, d);
    res -= Iterative(a, m, d);
    if(okk(a, m, d)){
        res ++;
    }
    res = (res + mod)%mod;
    cout << res << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    // cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}


