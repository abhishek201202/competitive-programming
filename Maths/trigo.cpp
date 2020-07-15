#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
#define PI 3.141592653589793238
using namespace std;

// all the angles in trigonometric function are in radian 
int32_t main(){
	cout << fixed << setprecision(10) ;
	cout << "cos function ::::" << endl;
	for(int i = 0 ; i <= 360 ; i += 45){
		double theta = (i * PI) / 180.0;
		cout << "cos(" << i << ") :: " << cos(theta) << endl;
	}

	cout << endl << "sin function :::: " << endl;
	for(int i = 0 ; i <= 360 ; i += 45){
		double theta = (i * PI) / 180.0;
		cout << "sin(" << i << ") :: " << sin(theta) << endl;
	}

	cout << endl << "tan function :::: " << endl;
	for(int i = 0 ; i <= 360 ; i += 45){
		double theta = (i * PI) / 180.0;
		cout << "tan(" << i << ") :: " << tan(theta) << endl;
	}
}
/*
cos function ::::
cos(0) :: 1.0000000000
cos(45) :: 0.7071067812
cos(90) :: 0.0000000000
cos(135) :: -0.7071067812
cos(180) :: -1.0000000000
cos(225) :: -0.7071067812
cos(270) :: -0.0000000000
cos(315) :: 0.7071067812
cos(360) :: 1.0000000000

sin function ::::
sin(0) :: 0.0000000000
sin(45) :: 0.7071067812
sin(90) :: 1.0000000000
sin(135) :: 0.7071067812
sin(180) :: 0.0000000000
sin(225) :: -0.7071067812
sin(270) :: -1.0000000000
sin(315) :: -0.7071067812
sin(360) :: -0.0000000000

tan function ::::
tan(0) :: 0.0000000000
tan(45) :: 1.0000000000
tan(90) :: 16331239353195370.0000000000
tan(135) :: -1.0000000000
tan(180) :: -0.0000000000
tan(225) :: 1.0000000000
tan(270) :: 5443746451065123.0000000000
tan(315) :: -1.0000000000
tan(360) :: -0.0000000000
*/