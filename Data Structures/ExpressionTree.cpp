// checked on :: https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/
struct ExpressionTree{
    struct Node{
        char op; int val;
        Node *Left = NULL, *Right = NULL;
        Node(int val, char op){
            this -> val = val;
            this -> op = op;
        }
    };

    string s;
    Node* root;
    int idx = -1;
    ExpressionTree(string s){
        this -> s = s;
    }

    void build(stack<Node*> &st){
        if(idx == s.size()) return;
        if(s[idx] == '0' || s[idx] == '1'){
            Node *cur = new Node(s[idx] - '0', ' ');
            if(st.size() == 0){
                st.push(cur);
            }else{
                st.top() -> Right = cur;
            }
            idx++;
        }else if(s[idx] == '('){
            idx++;
            stack<Node*> Newst;
            build(Newst);
            if(st.size() == 0){
                st.push(Newst.top());
                Newst.pop();
            }else{
                st.top() -> Right = Newst.top();
                Newst.pop();
            }
            idx++;
        }else if(s[idx] == ')'){
            return;
        }else{
            Node* cur = new Node(-1, s[idx]);
            cur -> Left = st.top();
            st.pop();
            st.push(cur);
            idx++;
        }
        build(st);
    }
    void build(){
        stack<Node*> st;
        idx = 0;
        build(st);
        root = st.top();
        st.pop();
    }


    vector<int> dfs(Node *root){
        if(root -> val != -1){
            return {root -> val, 1 ^ (root -> val)};
        }
        vector<int> L = dfs(root -> Left);
        vector<int> R = dfs(root -> Right);
        if(root -> op == '&'){
            int zero = min(L[0], R[0]);
            int one = min(L[1] + R[1], 1 + min(L[1], R[1]));
            return {zero, one};
        }else{
            int zero = min(L[0] + R[0], 1 + min(L[0], R[0]));
            int one = min(L[1], R[1]);
            return {zero, one};
        }
    }

    int find(){
        vector<int> res = dfs(root);
        return abs(res[0] - res[1]);
    }
};