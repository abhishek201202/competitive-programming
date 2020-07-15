#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Trie{
    T val;
    bool end;
    vector<Trie*> child;
    Trie(){
        this -> end = false;
        this -> val = 0;
        child.resize(26 , NULL);
    }

    /* insert string into trie */
    void insert(string s){
        Trie *root = this;
        for(int i = 0; i < s.size(); i ++){
            int ind = s[i] - 'a';
            if(root -> child[ind] == NULL){
                root -> child[ind] = new Trie();
            }
            root = root -> child[ind];
        }
        root -> end = true;
    }

    /* string is present in the trie or not */
    int search(string s){
        Trie *root = this;
        for(int i = 0; i < s.size(); i++){
            int ind = s[i] - 'a';
            if(root -> child[ind] != NULL){
                root = root -> child[ind];
            }else{
                return false;
            }
        }
        return root -> end;
    }

    /* prefix or not */
    bool is_prefix(string s) {
        Trie *root = this;
        for(int i = 0; i < s.size(); i ++){
            int ind = s[i] - 'a';
            if(root -> child[ind] != NULL){
                root = root -> child[ind];
            }else{
                return false;
            }
        }
        return true;
    }
};


int32_t main(){
    cout << "-1 :: to exit" << endl;
    cout << "1  :: to insert string" << endl;
    cout << "2  :: to search string" << endl;
    while(1){
        cout << endl << endl << "new test case .........." << endl;
        Trie<char> *root = new Trie<char>();
        while(1){
            int num; cin >> num;
            string s; cin >> s;
            if(num == -1) break;
            if(num == 1){
                root->insert(s);
            }else if(num == 2){
                if(root->search(s)){
                    cout << s << " is present !!! " << endl; 
                }else{
                    cout << s << " is not present !!!!" << endl;
                }
            }
        }
    }
}
