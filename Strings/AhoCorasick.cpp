// Tested on [https://www.codechef.com/MAY20A/problems/TWOSTRS]
#include <bits/stdc++.h>
#define int long long
using namespace std;

template<int ALPHABET_SIZE> struct AhoCorasick{
    vector<array<int, ALPHABET_SIZE>> T;
    vector<int> Leaf, suffixLink;
    AhoCorasick() : T(1), Leaf(1,0), suffixLink(1,0){ T[0].fill(-1); }

    int transition(int node, char c){
        return T[node][c - 'a'];
    }

    void insert(string& s, int val = 1){
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(T[node][c] == -1){
                T[node][c] = T.size();
                T.emplace_back();
                T.back().fill(-1);
                Leaf.push_back(0);
                suffixLink.push_back(-1);
            }
            node = T[node][c];
        }
        Leaf[node] += val;
    }

    void push_links(){
        for(int c = 0; c < ALPHABET_SIZE; c++){
            if(T[0][c] == -1) T[0][c] = 0;
        }
        queue<int> q;
        for(int c = 0; c < ALPHABET_SIZE; c++){
            if(T[0][c] != -1 && T[0][c] != 0){
                suffixLink[T[0][c]] = 0;
                q.push(T[0][c]);
            }
        }
        while(q.size()){
            int node = q.front(); q.pop();
            if(suffixLink[node] != -1){
                Leaf[node] += Leaf[suffixLink[node]];
            }
            for(int c = 0; c < ALPHABET_SIZE; c++){
                int child = T[node][c];
                if(child == -1){
                    T[node][c] = T[suffixLink[node]][c];
                }else{
                    suffixLink[child] = T[suffixLink[node]][c];
                    q.push(child);
                }
            }
        }
    }

    int count(int node){
        return Leaf[node];
    }
};

void test_cases(){
    string A, B; cin >> A >> B;
    int n; cin >> n;
    vector<string> a(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> v[i];
    }

    AhoCorasick<26> aho;
    for(int i = 0; i < n; i++){
        aho.insert(a[i], v[i]);
    }
    aho.push_links();

    vector<int> L(A.size(), 0);
    vector<int> Lstate(A.size(), 0);
    for(int i = 0, state = 0; i < A.size(); i++){
        state = aho.transition(state, A[i]);
        L[i] = aho.count(state);
        Lstate[i] = state;
        if(i) L[i] += L[i - 1];
    }
    vector<int> R(B.size(), 0);
    for(int i = 0, state = 0; i < B.size(); i++){
        state = aho.transition(state, B[i]);
        R[i] = aho.count(state);
    }   
    for(int i = B.size() - 2; i >= 0; i--){
        R[i] += R[i + 1];
    }

    int res = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            int ans = L[i];
            int state = Lstate[i];
            for(int k = j; k <= j + 24 && k < B.size(); k++){
                state = aho.transition(state, B[k]);
                ans += aho.count(state);
            }
            if(j + 25 < B.size()){
                ans += R[j + 25];
            }
            res = max(res, ans);
        }
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    for(int T = 1; T <= tt; T++){
        // cerr << endl << "Case #" << T << ": " << endl;
        test_cases();
    }
    

}
/*
1
hitech
codechef
3
chef 3
code 1
eche 5
*/
/*
13
*/