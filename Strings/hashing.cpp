// vector was giving TLE even without use of push_back
// so always try to use arr instead of vector
// https://codeforces.com/problemset/problem/559/B
// todo(important) : https://www.codechef.com/viewsolution/33286612
#include <bits/stdc++.h>
#define int long long
using namespace std;


struct Hashing{
public:
    int n;
    string s;
    vector<int> powP, h;
    const int p = 163; // any prime number
    Hashing(string s){
        this -> s = s;
        this -> n = s.size();
        powP.resize(n + 1);
        h.resize(n + 1);
    }

    void build(){
        powP[0] = 1ll;
        int p_pow = p;
        for(int i = 1; i <= n; i ++){
            powP[i] = p_pow;
            p_pow = p_pow * p;
        }

        h[n - 1] = s[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            h[i] = (h[i + 1] * p + s[i]);
        }
    }

    int hash(int l , int r){
        int res = h[l];
        if(r + 1 < n){
            res = (res - (h[r + 1]*powP[r - l + 1]));
        }
        return res;
    }
};


void test_cases(){

}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    for(int T = 1 ; T <= t ; T++){
        cout << "Case #" << T << ": " << endl;
        test_cases();
    }
    return 0;
}
