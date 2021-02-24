#include<bits/stdc++.h>
using namespace std;


class Treap{
public:
	int data, priority;
	Treap *Left, *Right;
	Treap(){}
	Treap(int data, int priority){
		this -> data = data;
		this -> priority = priority;
		Left = Right = NULL;
	}
};



int32_t main(){

}