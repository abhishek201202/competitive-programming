// https://www.spoj.com/problems/PR003004/
#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define ALL(x) x.begin(), x.end()
#define int long long int

vt<int> g(int num){
    vt<int> res;
    while(num){
        res.push_back(num%10);
        num /= 10;
    }
    reverse(ALL(res));
    return res;
}

// dp(i, sum, isBounded)
// total numbers till i such that sum of there digit is sum

int dp[18][200][2];
int f(int num){
    vt<int> digits = g(num);
    int n = digits.size();
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;
    for(int i = 0; i < n; i++){
        for(int isBounded : {0, 1}){
            int mxDigit = isBounded ? digits[i] : 9;
            for(int d = 0; d <= mxDigit; d++){
                for(int sum = 0; sum + d < 200; sum++){
                    if(isBounded && d == mxDigit){
                        dp[i + 1][sum + d][1] += dp[i][sum][isBounded];
                    }else{
                        dp[i + 1][sum + d][0] += dp[i][sum][isBounded];
                    }
                }
            }
        }
    }
    int res = 0;
    for(int sum = 0; sum < 200; sum++){
        res += sum * (dp[n][sum][0] + dp[n][sum][1]);
    }
    return res;
}

void test_cases(){
    int l, r; cin >> l >> r;
    int res = f(r);
    res -= f(l - 1);
    cout << res << endl;
}


int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        test_cases();
    }
}


