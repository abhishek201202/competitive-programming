#include <bits/stdc++.h>
using namespace std;

struct Mint{
    int64_t x;
    static const int64_t mod = 1e9 + 7;
    Mint(int64_t x = 0) : x((x%mod + mod)%mod){}
    // a % b = (a — b * (a / b))
    // % operator is costly 
    Mint& operator+=(const Mint a){ 
        x = (x + a.x) - mod * (int)((long double)(x + a.x) / mod);
        x = x + (x < 0 ? mod : 0);
        return *this; 
    }
    Mint& operator-=(const Mint a){ 
        x = (x - a.x) - mod * (int)((long double)(x - a.x) / mod);
        x = x + (x < 0 ? mod : 0);
        return *this;
    }
    Mint& operator*=(const Mint a){ 
        x = x * a.x - mod * (int)((long double)x * a.x / mod);
        x = x + (x < 0 ? mod : 0);
        return *this;
    }

    Mint pow(int64_t b) const{ if(!b) return Mint(1); Mint a = pow(b >> 1); a *= a; if(b&1) a *= *this;return a; }
    Mint inv() const{ return pow(mod - 2); }
    
    Mint& operator/=(const Mint a){ return (*this) *= a.inv(); }
    Mint operator+(const Mint a) const{ return Mint(*this) += a; }
    Mint operator-(const Mint a) const{ return Mint(*this) -= a; }
    Mint operator*(const Mint a) const{ return Mint(*this) *= a; }
    Mint operator/(const Mint a) const{ return Mint(*this) /= a; }
    
    friend bool operator==(const Mint a, const Mint b){ return a.x == b.x; }
    friend bool operator!=(const Mint a, const Mint b){ return a.x != b.x; }
    friend ostream& operator<<(ostream& os, Mint const& a){ return os << a.x; }
};



int32_t main(){
    Mint a = 5; 
    a += 5;
    cout << a << endl;
    a = a + 7;
    cout << a << endl;
    a = a * 10;
    cout << a << endl;
    a *= 2;
    cout << a << endl;
    a = a / 2;
    cout << a << endl;
    a /= 10;
    cout << a << endl;
    a-= 7;
    cout << a << endl;
    a = a - 5;
    cout << a << endl;
}