// https://www.spoj.com/problems/RAONE/
#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define int long long int
#define ALL(x) x.begin(), x.end()


// dp(i, evenposSum, oddPosSum, isBounded)

int dp[15][140][140][2];

vt<int> g(int num){
    vt<int> res;
    while(num){
        res.push_back(num%10);
        num /= 10;
    }
    reverse(ALL(res));
    return res;
}


int rec(vt<int> &digits, int idx, int evenSum, int oddSum, int isBounded){
    if(idx == digits.size()){
        return ((evenSum - oddSum) == 1) ? 1 : 0;
    }
    int &DP = dp[idx][evenSum][oddSum][isBounded];
    if(DP != -1) return DP;
    int mxDigit = isBounded ? digits[idx] : 9;
    int res = 0;
    for(int d = 0; d <= mxDigit; d++){
        if(isBounded && d == mxDigit){
            res += rec(digits, idx + 1, oddSum, evenSum + d, 1);
        }else{
            res += rec(digits, idx + 1, oddSum, evenSum + d, 0);
        }
    }
    return DP = res;
}
int Recursive(int num){
    vt<int> digits = g(num);
    memset(dp, -1, sizeof dp);
    return rec(digits, 0, 0, 0, 1);
}

void test_cases(){
    int l, r; cin >> l >> r;
    int res = Recursive(r);
    res -= Recursive(l - 1);
    cout << res << endl;   
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}


