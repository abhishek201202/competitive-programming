// Calculate the Grundy Number for the given 'n' in the game.
// The game starts with a number- ‘n’ and the player to move 
// divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. 
// If the integer becomes 0, it is removed. The last player to move wins. 
// Which player wins the game?
#include<bits/stdc++.h>
using namespace std;
int32_t GrundyNo(int n){
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
int main() {
    int n; cin >> n;
    cout << GrundyNo(n) << endl;
}