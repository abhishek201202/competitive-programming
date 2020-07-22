// abhishek soni.....[NSIT'22]

#include <bits/stdc++.h>
// ~~~~~~~~~~~~~~~~~~~~~> Debugging Zone <~~~~~~~~~~~~~~~~~~~~~~~ //
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> &p){
	os << '{' << p.first << ", " << p.second << '}';
	return os;
}
template<typename C, 
typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container){
	bool first = true;
	std::stringstream ss; ss << '[';
	for(const auto &x : container){
		if (!first) ss << ", ";
		first = false; ss << x;
	}
	ss << ']';
	return os << ss.str();
}
#define prnt "[Line " << __LINE__ << "] :: "
#define print(x) "[" << #x << " = " << x << "]"
#define debugg(x) cerr << prnt << print(x) << endl;
#define debugg2(x, y) cerr << prnt << print(x) << " " << print(y) << endl;
#define debugg3(x, y, z) cerr << prnt << print(x) << " " << print(y) << " " << print(z) << endl;
#define debugg4(x, y, z, w) cerr << prnt << print(x) << " " << print(y) << " " << print(z) << " " << print(w) << endl;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
#define endl "\n"
#define ff first
#define ss second
#define int long long
#define dd long double
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;


const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;


void test_cases(){
	

}

int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int tt = 1;
	cin >> tt;
	for(int T = 1; T <= tt; T++){
		cerr << endl << "Case #" << T << ": " << endl;
		test_cases();
	}
}