// https://codeforces.com/contest/438/problem/D
// Not tested yet
#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define inf 1e9
using namespace std;

const int N = 4e5 + 5;
struct info{
	int mx, mn, sum = 0, lazyUpd = inf;
} Tree[N];
int n, a[N];

info merge(info& a, info& b){
	info res;
	vector<int> _mx = {a.mx , a.mn, b.mx, b.mn};
	sort(_mx.begin(), _mx.end());
	res.mx = _mx.back();
	res.mn = _mx[0];
	res.sum = a.sum + b.sum;
	return res;
}

void build(int node, int si, int ei){
	if(si == ei){
		Tree[node].mx = a[si]; 
		Tree[node].mn = a[si];
		Tree[node].sum = a[si];
		return;
	}
	int mid = (si + ei) / 2;
	build(2 * node, si, mid);
	build(2 * node + 1, mid + 1, ei);
	Tree[node] = merge(Tree[2 * node], Tree[2 * node + 1]);
}
void build(){ build(1, 0, n - 1);}


void RangeUpdate(int l, int r, int val, int node, int si, int ei){
	if(l > ei || r < si || Tree[node].mx < val) return;
	if(si == ei){
		Tree[node].sum %= val; 
		Tree[node].mx %= val;
		Tree[node].mn %= val; 
		return;
	}
	int mid = (si + ei) / 2;
	RangeUpdate(l, r, val, 2 * node, si, mid);
	RangeUpdate(l, r, val, 2 * node + 1, mid + 1, ei);
	Tree[node] = merge(Tree[2 * node], Tree[2 * node + 1]);
}
void RangeUpdate(int l, int r, int val){ RangeUpdate(l, r, val, 1, 0, n - 1);}

void PtUpdate(int idx, int val, int node, int si, int ei){
	if(idx < si || idx > ei || si > ei) return;
	if(si == ei){
		Tree[node].mx = Tree[node].mn = val;
		Tree[node].sum = val;
		return;
	}
	int mid = (si + ei) / 2;
	PtUpdate(idx, val, 2 * node, si, mid);
	PtUpdate(idx, val, 2 * node + 1, mid + 1, ei);
	Tree[node] = merge(Tree[2 * node], Tree[2 * node + 1]);
}
void PtUpdate(int idx, int val) { PtUpdate(idx, val, 1, 0, n - 1);}

int qry(int l, int r, int node, int si, int ei){
	if(r < si || l > ei || si > ei) return 0;
	if(l <= si && r >= ei) return Tree[node].sum;
	int mid = (si + ei) / 2;
	int L = qry(l, r, 2 * node, si, mid);
	int R = qry(l, r, 2 * node + 1, mid + 1, ei);
	return L + R;
}
int qry(int l, int r) {return qry(l, r, 1, 0, n - 1);}



int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int  m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build();
	while(m--){
		int c; cin >> c;
		if(c == 1){
			int l, r; cin >> l >> r;
			cout << qry(l - 1, r - 1) << endl;
		}else if(c == 2){
			int l, r, x; cin >> l >> r >> x;
			RangeUpdate(l - 1, r - 1, x);
		}else{
			int idx, x; cin >> idx >> x;
			PtUpdate(idx - 1, x);
		}
	}
}
/*
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
*/

/*
50 100000
8757112 1517031 381712 2025493 352436 7421902 5405984 7852992 7439966 6606048 6998216 7629581 5231435 4023156 516461 2998581 988048 3782470 3240183 9196696 4218377 1578743 3758293 319670 4054870 7630090 8489463 6411702 1828825 7533544 687826 4978787 4497209 901853 1790944 7496105 8748129 3012760 3734557 305309 9963265 2525743 5559435 6570483 2553484 3069593 8729263 4268549 2186297 6564914
3 16 301992
1 2 3
3 22 9435918
1 5 25
2 28 36 5573578
3 25 7322630
1 20 26
2 7 38 9552336
*/