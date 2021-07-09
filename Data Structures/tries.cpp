struct BitTrie{
    const int B = 32;
    BitTrie *left, *right;
    int cnt;
    BitTrie(){
        left = right = NULL;
        cnt = 0;
    }

    // insert a number into the trie
    void insert(int n){
        BitTrie *root = this;
        for(int bit = B - 1; bit >= 0; bit--){
            int x = n & (1ll << bit);
            if(x){
                if(root -> right == NULL){
                    root -> right = new BitTrie();
                }
                root = root -> right;
            }else{
                if(root -> left == NULL){
                    root -> left = new BitTrie();
                }
                root = root -> left;
            }
            root -> cnt += 1;
        }
    }

    // count of element whose xor with n < k
    int countSmallerPairs(int k, int n){
        BitTrie *root = this;
        int res = 0;
        for(int bit = B - 1; bit >= 0 && root; bit--){
            int x = n & (1ll << bit);
            int y = k & (1ll << bit);
            if(y == 0){
                if(x){
                    root = root -> right;
                }else{
                    root = root -> left;
                }
            }else{
                if(x){
                    if(root -> right != NULL){
                        res += root -> right -> cnt;
                    }
                    root = root -> left;
                }else{
                    if(root -> left != NULL){
                        res += root -> left -> cnt;
                    }
                    root = root -> right;
                }
            }
        }
        return res;
    }



    // find max xor pair
    int find_max_pair(int ele){
        BitTrie *root = this;
        int res = 0;
        for(int bit = B - 1; bit >= 0; bit--){
            int x = ele & (1ll << bit);
            if(x){
                if(root->left != NULL){
                    res += (1ll << bit);
                    root = root->left;
                }else{
                    root = root->right;
                }
            }else{
                if(root->right != NULL){
                    res += (1ll << bit);
                    root = root->right;
                }else{
                    root = root->left;
                }
            }
        }
        return res;
    }



    // find max xor pair
    int max_xor_subarray(vector<int> &a){
        BitTrie *root = new BitTrie();
        int ans = a[0];
        int curr_xor = ans;
        insert(ans);
        for(int i = 1; i < a.size(); i++){
            curr_xor ^= a[i];
            int temp_ans = find_max_pair(curr_xor);
            ans = max(ans , temp_ans);
            insert(curr_xor);
        }
        return ans;
    }
};