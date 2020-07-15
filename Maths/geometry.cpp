#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const double EPS = 1e-12;

typedef double T;
struct PT{
	T x , y;
	PT(){}
	PT(T x , T y) : x(x) , y(y){}
	PT operator + (const PT &p) const { return PT(x + p.x , y + p.y);}
	PT operator - (const PT &p) const { return PT(x - p.x , y - p.y);}
};


double dot(PT p , PT q){ return p.x * q.x + p.y * q.y ;}
double cross(PT p , PT q){ return p.x*q.y - p.y*q.x ;}
double dis(PT p , PT q) {return dot(p - q , p - q);}

// to check point c is in CW or in CCW or collinear with respect to a and b 
bool CC(PT a , PT b , PT c) { return (c.x-b.x)*(b.y-a.y)>(c.y-b.y)*(b.x-a.x); }
bool CCW(PT a , PT b , PT c) { return (c.x-b.x)*(b.y-a.y)<(c.y-b.y)*(b.x-a.x); }
bool IsCollinear(PT a , PT b , PT c){ return (c.x-b.x)*(b.y-a.y)<(c.y-b.y)*(b.x-a.x); }

// given a,b,c are 3 collinear points check if c lies on segment ab or not
bool onSegment(PT a, PT b, PT c){
	if(c.x <= max(a.x,b.x) && c.x >= min(a.x,b.x)
		&& c.y <= max(a.y,b.y) && c.y >= min(a.y,b.y)) return true;
	else return false;
}

// rotate a point CCW about the origin
PT RotateCCW(PT p , double t){
	return PT(p.x*cos(t) - p.y*sin(t) , p.y*cos(t) + p.x*sin(t));
}

// determine if line from a to b is parallel and collinear to line from c to d
bool LinesParallel(PT a , PT b , PT c , PT d){
	return fabs(cross(b - a , c - d)) < EPS;
}
bool LinesCollinear(PT a , PT b , PT c , PT d){
	return LinesParallel(a, b, c, d)
		&& fabs(cross(a - b , a - c)) < EPS
		&& fabs(cross(c - d , c - a)) < EPS;
}


// determine if line segment from a to b intersect with 
// line segment from c ton d
bool SegmentsIntersects(PT a , PT b , PT c , PT d){
	if(CC(a, b, c) != CC(a, b, d) && CC(c, d, a) != CC(c, d, b)) return true;
	if(IsCollinear(a,b,c) && onSegment(a,b,c)) return true;
	if(IsCollinear(a,b,d) && onSegment(a,b,d)) return true;
	if(IsCollinear(c,d,a) && onSegment(c,d,a)) return true;
	if(IsCollinear(c,d,b) && onSegment(c,d,b)) return true;
	return false;
}


// calculate the area of polygon by traingulation method
double PolygonArea(vector<PT> points){
	double area = 0;
	for(int i = 1; i < points.size() - 1 ; i++){
		area += cross(points[i] - points[0] , points[i + 1] - points[0]);
	}
	return fabs(area/2.0);
}

int32_t main(){
	int n; cin >> n;
	vector<PT> v(n);
	for(int i =0 ; i < n ;i++){
		cin >> v[i].x;
	}
	for(int i =0 ; i < n ;i++){
		cin >> v[i].y;
	}
	cout << PolygonArea(v) << endl;
}