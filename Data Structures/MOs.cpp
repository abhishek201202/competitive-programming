// Tested on :: https://www.spoj.com/problems/DQUERY/
#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;

struct qry{
	int idx, l, r, lb, rb, block;
	void read(int idx, int block){
		this -> block = block;
		this -> idx = idx;
		cin >> l >> r;
		l--, r--;
		lb = l / block;
		rb = r / block;
	}
	bool operator<(qry& a){
		if(lb == a.lb){
			return r < a.r;
		}else{
			return lb < a.lb;
		}
	}
};

struct MOs{
	vector<int> a;
	int n, block;
	vector<int> cnt;
	int ans;
	MOs(vector<int>& a){
		this -> a = a;
		this -> n = a.size();
		this -> block = sqrt(n);
		this -> ans = 0;
		cnt = vector<int>(n + 1, 0);
	}

	void add(int idx){
		if(cnt[a[idx]] == 0){
			ans++;
		}
		cnt[a[idx]]++;
	}

	void remove(int idx){
		cnt[a[idx]]--;
		if(cnt[a[idx]] == 0){
			ans--;
		}
	}
	int qry(){
		return ans;
	}
};

int32_t main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m; cin >> m;
	vector<qry> q(m);
	for(int i = 0; i < m; i++){
		q[i].read(i, sqrt(n));
	}
	sort(ALL(q));

	map<int, int> mp;
	for(int i = 0, id = 0; i < n; i++){
		if(!mp.count(a[i])){
			mp[a[i]] = id++;
		}
		a[i] = mp[a[i]];
	}

	MOs DS(a);
	vector<int> res(m);
	int L = 0, R = -1;
	for(int i = 0; i < m; i++){
		while(R < q[i].r) DS.add(++R);
		while(L > q[i].l) DS.add(--L);
		while(R > q[i].r) DS.remove(R--);
		while(L < q[i].l) DS.remove(L++);
		res[q[i].idx] = DS.qry();
	}
	for(int i = 0; i < m; i++){
		cout << res[i] << endl;
	}
}