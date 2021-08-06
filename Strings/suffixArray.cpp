// Tested on :: https://www.spoj.com/problems/DISUBSTR/
#include<bits/stdc++.h>
#define int long long int
using namespace std;

class SuffixArray{
public:
    string s;
    int n, gap;
    vector<int> SA, Rank, tmp, LCP;

    SuffixArray(string s){
        this -> s = s;
        n = s.size();
        SA = vector<int>(n);
        Rank = vector<int>(n);
        tmp = vector<int>(n);
        LCP = vector<int>(n);
    }


    void buildSA(){
        auto suffCmp = [&](int i, int j){
            if(Rank[i] != Rank[j]){
                return Rank[i] < Rank[j];
            }
            if(i + gap < n && j + gap < n){
                return Rank[i + gap] < Rank[j + gap];
            }
            return i > j;
        };

        for(int i = 0; i < n; i++){
            SA[i] = i;
            Rank[i] = s[i];
        }
        
        for(gap = 1; ; gap *= 2){
            sort(SA.begin(), SA.end(), suffCmp);
            for(int i = 0; i < n - 1; i++){
                tmp[i + 1] = tmp[i] + suffCmp(SA[i], SA[i + 1]);
            }
            for(int i = 0; i < n; i++){
                Rank[SA[i]] = tmp[i];
            }
            if (tmp[n - 1] == n - 1) break;
        }
    }

    void buildLCP(){
        for(int i = 0, k = 0; i < n; ++i){ 
            if(Rank[i] != n - 1){
                for(int j = SA[Rank[i] + 1]; s[i + k] == s[j + k];)
                ++k;
                LCP[Rank[i]] = k;
                if(k)--k;
            }
        }
    }

    void build(){
        buildSA();
        buildLCP();
    }

    vector<int> getSA(){ return SA; }
    vector<int> getLCP(){ return LCP; }
};


int32_t main(){
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        string s; cin >> s;
        int n = s.size();
        SuffixArray ss(s);
        ss.build();
        vector<int> LCP = ss.getLCP();
        int res = n * (n + 1) / 2;
        for(int i = 0; i < n; i++){
            res -= LCP[i];
        }
        cout << res << endl;
    }
}