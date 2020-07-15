// https://www.codechef.com/MAY17/problems/SANDWICH
// https://www.youtube.com/watch?v=DBR6eW3MuiU
#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

/**********************************************/
// f(n)   = ( f(n)^(n/m) * (f(n%m)) )
// f(n)   = f(n-1)*g(n)
// E(n,p) = exponent of p in n!
// F(n)   = product( f(n/(p^r)) )
// F(n)   = n! / E(n,p)
// r      = highest power, such that (p^r)|i
// ncr    = F(n)/(F(r)*F(n-r))
// ncr   *= p^( E(n,p) - E(r,p) - E(n-r,p) ) 
/*********************************************/
const int N = 1e5 + 5;
int fact[N];
void pre(int m){
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++){
        fact[i] = (fact[i - 1] * i) % m;
    }
}


int Extended_euclid(int a , int b , int &x , int &y){
    if(a < b) swap(a , b);
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int res = Extended_euclid(b , a % b , x , y);
    int temp = y;
    y = x - ((a / b) * y);
    x = temp;
    return res;
}
int inv(int a , int b){
    int x ,y;
    int g = Extended_euclid(a , b , x , b);
    if(g != 1) return -1;
    return (y + b) % b;
}

int power(int a,int b,int m){
    if(a==0) return 0;
    if(b==0) return 1;
    int ans=power(a,b/2,m);
    ans = (ans * ans) % m;
    if(b%2!=0){
        ans = (ans * (a%m) ) % m;
    }
    return ans;
}
int E(int n,int m){
    int count=0;
    while(n%m==0){
        count++;
        n/=m;
    }
    return count;
}
int f(int n,int m){
    return ( 1ll * fact[n%m] * power(m,n/m,m) );
}
int F(int n,int m){
    int ans=1;
    while(n>0){
        ans = ( ans * f(n,m) ) % m ;
        n/=m;
    }
    return ans;
}
int ncrModp(int n,int r,int m,int pw){
    if(n < r) return 0;
    if(n == r) return 1;
    int exp_n = E(n , m);
    int exp_r = E(r , m);
    int exp_n_r = E(n - r , m);
    int total_exponent = exp_n - exp_r - exp_n_r ;
    if(total_exponent >= pw) return 0;
    int num = F(n,m) % m;
    int den = ( F(r,m) * F(n-r,m) ) % m;
    den = inv(den,m) % m;
    return ( ((num * den) % m) * (power(m , total_exponent , m) % m) ) % m; 
}
/***************************************************************/
int get_rem(int x,int y,int p,int m_inv_ki_power){
    int res = 1ll;     
    x = x % p;  
    while (y > 0){
        if (y & 1){ 
            res = (res*x) % p;
            if(m_inv_ki_power > 0 && res%p == 0){
                res /= p;
                m_inv_ki_power--;
            }
        }
        y = y >> 1ll;
        x = (x * x) % p;   
    }
    return res;
}
int ncrModpLucas(int p,int i,int m_inv_ki_power,int r,int m){
   if(r == 0) return 1;
   int ni = get_rem(p , i , m , m_inv_ki_power);
   int ri = r % m;
   if(ni == 0 || ri == 0) return 0;
   return ((ncrModpLucas(p , i , m_inv_ki_power + 1 , r/m , m) % m) * (ncrModp(ni , ri , m , 1) % m)) % m;
}
/*****************************************************************/


int32_t main(){

}