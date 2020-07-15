#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long 
#define ff first
#define ss second
#define pb push_back
using namespace __gnu_pbds;
using namespace std;


typedef pair<int,int> pii;
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag ,
tree_order_statistics_node_update>; 
// find_by_order() === >>> return iterator to the kth largest element(counting from 0)
// order_of_key() === >>> return no of items in a set that are strictly smaller than our item
// insert() === >>> insert our element into the data structure 

// For Practise : problem 1028.stars.....[timus online judge]

int32_t main(){
	// ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	pbds<int> p;
	vector<int> v;
	for(int i = 0 ;i < 25 ; i += 3){
		if(i == 0) continue;
		v.pb(i);
		v.pb(i);
		p.insert(i);
		p.insert(i);
	}
	
	reverse(v.begin() , v.end());
	for(int i = 0 ;i < v.size() ; i++){
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "3rd largest element(counting from 0) is : " <<  *p.find_by_order(3) << endl;
	cout << "index of num. 6 " << p.order_of_key(6) << endl;
	cout << "index of num. 7 " << p.order_of_key(7) << endl;
	cout << "is 7 actually present : " << (end(p) == p.find_by_order(7)) << endl;
}