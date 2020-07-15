#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;

typedef double T;
struct PT{
	T x , y;
	PT(){}
	PT(T x , T y) : x(x) , y(y){} 
};

bool ccw(PT a , PT b , PT c) { 
	return (c.x-b.x)*(b.y-a.y)<(c.y-b.y)*(b.x-a.x); 
}

vector<PT> jarvis(vector<PT> P){
	vector<PT> hull;
	int l = 0 , n = P.size();
	for(int i = 1 ; i < n ; i++){
		if(P[i].x < P[l].x) l = i;
	}
	int ind = l;
	do{
		hull.pb(P[ind]);
		int curr = (ind + 1) % n;
		for(int i = 0 ;i < n ;i++){
			if(ccw(P[ind] , P[i] , P[curr])) curr = i;
		}
		ind = curr;
	}while(ind != l);
	return hull;
}

int32_t main(){
	int n; cin >> n;
	vector<PT> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].x ;
	}
	for(int i = 0 ;i < n ;i++){
		cin >> v[i].y;
	}
	vector<PT> hull = jarvis(v);
	for(int i = 0 ; i < hull.size() ; i++){
		cout << hull[i].x << " " << hull[i].y << endl;
	}
}