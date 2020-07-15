// nim game with a restriction that we can only remove 
// 1,2 or 3 stones at a time
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb puhs_back
using namespace std;

int GrundyNo(int n){
    if(n <= 2) return n;
    int a = GrundyNo((floor)(n/2));
    int b = GrundyNo((floor)(n/3));
    int c = GrundyNo((floor)(n/6));
    int minni = min(a,min(b,c));
    int maxxi = max(a,max(b,c));
    int mid = a + b + c - minni - maxxi;
    if(minni != 0){
        return 0;
    }else if(mid != minni + 1){
        return minni+1;
    }else if(maxxi != mid + 1){
        return mid + 1;
    }else{
        return maxxi + 1;
    }
}


int32_t main(){
    int n; cin >> n; // total no of piles
    vector<int> v(n);
    for(int i = 0; i < n ;i++){
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; i++){
        v[i] = GrundyNo(v[i]);
    }
    int cummulative_xor = 0;
    for(int i = 0 ; i < n ;i++){
        cummulative_xor ^= v[i];
    }
    if(!cummulative_xor){
        cout << "1st player loss" << endl;
    }else{
        cout << "1st player wins" << endl;
    }

}