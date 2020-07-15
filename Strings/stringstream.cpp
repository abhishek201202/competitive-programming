#include<bits/stdc++.h>
using namespace std;

char c;
int num;
string t , s;

int32_t main(){
	stringstream io;
	// writing
	io << "codechef" << " and " << "codeforces";
	// reading complete io
	s = io.str();
	cout << s << endl << endl << endl;


	// reading each word of io
	s = " + 3 - 5 * 4343 / 23 + 2323 - 1323 * 324432";
	cout << s << endl;
	stringstream s1(s);
	while(s1 >> c >> num){
		cout << c << " :: " << sizeof(c) << " , " << num << " :: " << sizeof(num) << endl;
	}
	cout << endl << endl;



	s = "+3-5*4343/23 + 2323-1323*324432";
	cout << s << endl;
	stringstream s2(s);
	while(s2 >> c >> num){
		cout << c << " :: " << sizeof(c) << " , " << num << " :: " << sizeof(num) << endl;
	}
	cout << endl << endl;


	s = "212313 safef 3242 csfd dsfewf sdfref";
	cout << s << endl;
	stringstream s3(s);
	while(s3 >> num >> t){
		cout << num << " :: " << sizeof(num) << " , " << t << " :: " << sizeof(t) << endl;
	}
}
/*
codechef and codeforces


 + 3 - 5 * 4343 / 23 + 2323 - 1323 * 324432
+ :: 1 , 3 :: 4
- :: 1 , 5 :: 4
* :: 1 , 4343 :: 4
/ :: 1 , 23 :: 4
+ :: 1 , 2323 :: 4
- :: 1 , 1323 :: 4
* :: 1 , 324432 :: 4


+3-5*4343/23 + 2323-1323*324432
+ :: 1 , 3 :: 4
- :: 1 , 5 :: 4
* :: 1 , 4343 :: 4
/ :: 1 , 23 :: 4
+ :: 1 , 2323 :: 4
- :: 1 , 1323 :: 4
* :: 1 , 324432 :: 4


212313 safef 3242 csfd dsfewf sdfref
212313 :: 4 , safef :: 32
3242 :: 4 , csfd :: 32
*/