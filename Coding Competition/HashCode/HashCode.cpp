/**
 * author: abhishek soni ..... [NSIT'22]
 * created: 22/02/2022  19:35:33
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1,T2> &p){ os << '{' << p.first << ", " << p.second << '}'; return os;}
template<typename C,typename T = decay_t<decltype(*begin(declval<C>()))>,typename enable_if<!is_same<C,string>::value>::type* = nullptr>
ostream &operator<<(ostream &os, const C &container){bool first = true; stringstream ss; ss << '[';for(const auto &x : container){ if(!first) ss << ", "; first = false; ss << x;} ss << ']';return os << ss.str();}
vector<string> split(const string& s, char c){ vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return v;}
inline void dbg_out(vector<string>::iterator it){ cerr << endl;}template<typename T, typename... Args> inline void dbg_out(vector<string>::iterator it, T a, Args... args){ cerr << "[" << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "] "; dbg_out(++it, args...); }
inline void READ_OUT(vector<string>::iterator it){}template<typename T, typename... Args> inline void READ_OUT(vector<string>::iterator it, T& a, Args&... args){cin >> a;READ_OUT(++it, args...);}
template<typename T> inline void debugg2D(T a, int n, int m){for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout << a[i][j] << " ";}cout << endl;}}
#define debugg(...) {cerr << "[Line " << __LINE__ << "] :: "; dbg_out(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);}
#define READ(...) READ_OUT(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__);

#define endl             "\n"
#define ff               first
#define ss               second
#define vt               vector
#define ar               array
#define int              long long
#define dd               long double
#define ALL(x)           x.begin(), x.end()
#define FOR(i, s, e)     for(int i = s; i <= e; i++)
#define FORR(i, s, e)    for(int i = s; i >= e; i--)
#define getcurrtime      ((double)clock()/CLOCKS_PER_SEC)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag ,tree_order_statistics_node_update>; 

const array<int, 2> dir4[4] = {{0, -1}, {-1, 0}, {0, +1}, {+1, 0}};
const array<int, 2> dir8[8] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}};
const array<int, 2> dirD[4] = {{-1, -1}, {-1, +1}, {+1, +1}, {+1, -1}};
const array<int, 2> dirK[8] = {{-1, -2}, {-2, -1}, {-2, +1}, {-1, +2}, {+1, +2}, {+2, +1}, {+2, -1}, {+1, -2}};

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N   = 5e5 + 5;

/*=================================================================
Global Variables Start 
=================================================================*/


/*=================================================================
Global Variables End
=================================================================*/


// take all input here only
void takeInput(){

}


// print here whatever you have to print for final answer
void outputResult(int score = 0){ 
    
}

string createNewFile(int score = 0){
    fstream file;
    string fileName = "out" + to_string(score) + ".txt";
    file.open(fileName, ios::out);
    file.close();
    return fileName;
}

void outputInFile(int score = 0){
    string s = createNewFile(score);
    char *fileName = new char[s.size() + 1];
    strcpy(fileName, s.c_str());
    freopen(fileName, "w", stdout);
    outputResult(score);
}

// score given by hashcode system
int findScore(){

}


void test_cases(){
    takeInput();


    outputInFile(findScore());
}


int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("in1.txt", "r", stdin);
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
}





