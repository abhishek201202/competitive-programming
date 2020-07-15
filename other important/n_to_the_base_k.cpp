#include<bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back
using namespace std;

string n_to_base_k(int n,int r){
    string s = "";
    while(n != 0){
        int rem = n % r;
        if(rem <= 9){
             s = (char)('0' + rem) + s;
        }else{
            s = (char)('A' + rem - 10) + s;
        }
        n /= r;
    }
    while(s.size() != 32) s = '0' + s;
    return s;
}
void solve(){
    int n; cin >> n;
    cout << n_to_base_k(n , 2) << endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    for(int T = 1 ; T <= t ; T ++){
        cout << "Case #" << T << ": " << endl;
        solve();
    }
}