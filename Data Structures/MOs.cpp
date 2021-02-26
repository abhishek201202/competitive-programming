// Tested on :: https://www.spoj.com/problems/DQUERY/
// Tested on :: https://www.spoj.com/problems/XXXXXXXX/
#include <bits/stdc++.h>
#define int long long
#define ALL(x) x.begin(), x.end()
using namespace std;

const int N = 2e5 + 5;
const int Q = 2e5 + 5;
int n, block, ans;
int a[N], Last[N], cnt[N], vis[N], rev[N];

struct Query{
	int idx, l, r, lb, rb, t;
	Query(int idx, int t) : idx(idx), t(t){}
	void read(){
		cin >> l >> r;
		l--, r--;
		lb = l / block;
		rb = r / block;
	}
	bool operator<(Query& a){
		if(lb == a.lb){
			if(rb == a.rb){
				return t < a.t;
			}else{
				return rb < a.rb;
			}
		}else{
			return lb < a.lb;
		}
	}
};
struct Update{
	int idx, curr, prev;
	void read(){
		cin >> idx >> curr;
		idx--;
		prev = Last[idx];
		Last[idx] = curr;
	}
};

void add(int idx){
	vis[idx] = true;
	if(cnt[a[idx]] == 0){
		ans += rev[a[idx]];
	}
	cnt[a[idx]]++;
}

void remove(int idx){
	vis[idx] = false;
	cnt[a[idx]]--;
	if(cnt[a[idx]] == 0){
		ans -= rev[a[idx]];
	}
}

void upd(int idx, int val){
	if(!vis[idx]){
		a[idx] = val;
		return;
	}
	remove(idx);
	a[idx] = val;
	add(idx);
}

int qry(){
	return ans;
}


int32_t main(){
	int n; cin >> n;
	block = pow(n, 2.0 / 3);
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		Last[i] = a[i];
		mp[a[i]] = 1;
	}

	int m; cin >> m;
	vector<Query> q;
	vector<Update> up;
	for(int i = 0, idx = 0, t = 0; i < m; i++){
		char c; cin >> c;
		if(c == 'Q'){
			q.push_back(Query(idx++, t));
			q.back().read();
		}else{
			t++;
			up.push_back(Update());
			up.back().read();
			mp[up.back().curr] = 1;
		}
	}
	sort(ALL(q));


	int id = 0;
	for(auto& [val, _] : mp){
		_ = id;
		rev[id++] = val;
	}
	for(int i = 0; i < n; i++){
		a[i] = mp[a[i]];
	}
	for(int i = 0; i < up.size(); i++){
		up[i].curr = mp[up[i].curr];
		up[i].prev = mp[up[i].prev];
	}


	vector<int> res(q.size());
	int L = 0, R = -1, T = -1;
	for(int i = 0; i < q.size(); i++){
		while(T + 1 < q[i].t) {++T, upd(up[T].idx, up[T].curr);} // do
		while(T + 1 > q[i].t) {upd(up[T].idx, up[T].prev), T--;} // redo
		while(R < q[i].r) add(++R);
		while(L > q[i].l) add(--L);
		while(R > q[i].r) remove(R--);
		while(L < q[i].l) remove(L++);
		res[q[i].idx] = qry();
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
}
