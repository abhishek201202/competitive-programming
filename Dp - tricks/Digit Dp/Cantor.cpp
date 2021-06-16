// https://www.spoj.com/problems/TAP2012C/en/

#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define int long long int
#define ALL(x) x.begin(), x.end()

const int N = 1e5 + 5;
int L, R, Base, vis[N];
int dp[110][2][2];
string s;



vt<int> g(int num){
    vt<int> res;
    while(num){
        res.push_back(num%Base);
        num /= Base;
    }
    reverse(ALL(res));
    return res;
}

// dp(idx, leading zeros, isBounded)

int rec(vt<int> &digits, int idx, int isBounded, int leadingZeros){
    if(idx == digits.size()){
        return leadingZeros == 0;
    }
    int &cache = dp[idx][isBounded][leadingZeros];
    if(cache != -1) return cache;
    int res = 0;
    int mxDigit = isBounded ? digits[idx] : Base - 1;
    if(leadingZeros){
        res += rec(digits, idx + 1, 0, 1);
        for(int d = 1; d <= mxDigit; d++){
            if(!vis[d]) continue;
            if(isBounded && d == mxDigit){
                res += rec(digits, idx + 1, 1, 0);
            }else{
                res += rec(digits, idx + 1, 0, 0);
            }
        }
    }else{
        for(int d = 0; d <= mxDigit; d++){
            if(!vis[d]) continue;
            if(isBounded && d == mxDigit){
                res += rec(digits, idx + 1, 1, 0);
            }else{
                res += rec(digits, idx + 1, 0, 0);
            }
        }
    }
    return cache = res;
}

int RecursiveSolution(int num){
    vt<int> digits = g(num);
    memset(dp, -1, sizeof dp);
    return rec(digits, 0, 1, 1);
}






// dp(idx, leading zeros, isBounded)
// total number ended at idx position 
// contain leading zeros till idx position if if bit is set or 1
// bounded number till idx position if isBounded is set or 1

int iterativeMethod(int num){
    vt<int> digits = g(num);
    memset(dp, 0, sizeof dp);
    int n = digits.size();
    // _ _ _ _ _ _
    // we will convert above number into 
    // 0 _ _ _ _ _ _
    dp[0][1][1] = 1; // we have put 0 in front of our number 
    // thats why leadingZeros and isBounded bits are set

    // isBounded and leadingZeros represent isBounded and leadingZeros
    // for all the numbers till last positions
    for(int i = 0; i < n; i++){
        for(int isBounded : {0, 1}){
            int mxDigit = isBounded ? digits[i] : Base - 1;
            for(int leadingZeros : {0, 1}){
                if(leadingZeros){
                    dp[i + 1][1][0] += dp[i][leadingZeros][isBounded];
                    for(int d = 1; d <= mxDigit; d++){
                        if(!vis[d]) continue;
                        if(isBounded && d == mxDigit){
                            dp[i + 1][0][1] += dp[i][leadingZeros][isBounded];
                        }else{
                            dp[i + 1][0][0] += dp[i][leadingZeros][isBounded];
                        }
                    }
                }else{
                    for(int d = 0; d <= mxDigit; d++){
                        if(!vis[d]) continue;
                        if(isBounded && d == mxDigit){
                            dp[i + 1][0][1] += dp[i][leadingZeros][isBounded];
                        }else{
                            dp[i + 1][0][0] += dp[i][leadingZeros][isBounded];
                        }
                    }
                }
                
            }
        }
    }
    return dp[n][0][0] + dp[n][0][1];
}

void test_cases(){
    while(1){
        cin >> L >> R >> Base >> s;
        if(L == R && L == Base && L == -1) return;
        for(int i = 0; i < s.size(); i++){
            vis[i] = (s[i] == 'S' ? 1 : 0);
        }    
        int res = iterativeMethod(R);
        res -= iterativeMethod(L - 1);
        cout << res << endl;
    }
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


