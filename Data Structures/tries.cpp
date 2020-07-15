#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int B = 32;
const int N = 1e7;
int arr[N];
int n ;
struct trieNode{
	trieNode *left , *right;
};

// maximum xor subarray

void insert(trieNode *head , int ele){
	trieNode *curr = head;
	for(int i = B - 1 ; i >= 0 ; i--){
		int bit = ele & (1ll << i);
		if(bit){
			if(curr->right != NULL){
				curr = curr->right;
			}else{
				curr->right = new trieNode();
				curr = curr->right;
			}
		}else{
			if(curr->left != NULL){
				curr = curr->left;
			}else{
				curr->left = new trieNode();
				curr = curr->left;
			}
		}
	}
}

int find_max_pair(trieNode *head , int ele){
	trieNode *curr = head;
	int ans = 0;
	for(int i = B - 1 ;i >= 0 ;i--){
		int bit = ele & (1ll << i);
		if(bit){
			if(curr->left != NULL){
				ans += (1ll << i);
				curr = curr->left;
			}else{
				curr = curr->right;
			}
		}else{
			if(curr->right != NULL){
				ans += (1ll << i);
				curr = curr->right;
			}else{
				curr = curr->left;
			}

		}
	}
	return ans;
}

int max_xor_subarray(){
	trieNode *head = new trieNode();
	int ans = arr[0];
	int curr_xor = ans;
	insert(head , ans);
	for(int i = 1; i < n ; i++){
		curr_xor ^= arr[i];
		int temp_ans = find_max_pair(head , curr_xor);
		ans = max(ans , temp_ans);
		insert(head , curr_xor);
	}
	return ans;
}


int32_t main(){
	cin >> n;
	for(int i = 0 ;i < n ;i++){
		cin >> arr[i];
	}
	cout << max_xor_subarray() << endl;

}