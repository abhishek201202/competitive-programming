#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int mat[N][N] , A[N][N] , B[N][N];

void multiply(int n1 , int m1 , int n2 , int m2){
	// new matrix is of size n1 x m2  && m1 == n2
	for(int i = 0 ; i < n1 ; i++){
		for(int j = 0 ;j < m2 ; j++){
			mat[i][j] = 0;
			for(int k = 0 ; k < m1 ; k++){
				mat[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

int main(){
	int n1 , m1 , n2 , m2; cin >> n1 >> m1 >> n2 >> m2;
	for(int i = 0 ;i < n1 ; i++){
		for(int j = 0 ;j < m2 ; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0 ;i < n2 ; i++){
		for(int j = 0 ;j < m2 ; j++){
			cin >> B[i][j];
		}
	}
	multiply(n1, m1 , n2 ,m2);
	for(int i = 0 ;i < n1 ; i++){
		for(int j = 0 ;j < m2 ; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}