#include <bits/stdc++.h>
using namespace std;

// custom comparator for set
struct cmp{
    bool operator() (const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

int32_t main(){
    set<int, cmp> st;
    for(int i = 0; i < 10; i++){
        st.insert(i);
    }
    for(int x : st){
        cout << x << " ";
    }
    cout << endl;


    // ~~~~~~~ advance ~~~~~~~~~
    auto it = st.begin();
    advance(it, 3); // shift the pointer by 3 unit
    cout << *it << endl;
}