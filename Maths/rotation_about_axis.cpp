#include<bits/stdc++.h>
#define int long long
#define dd double
#define ff first
#define ss second
#define pb push_back
#define PI 3.141592653589793238
#define pii pair<int,int>
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
vector<vector<dd>> mat;

vector<vector<dd>> mul(vector<vector<dd>>& A , vector<vector<dd>>& B){
	vector<vector<dd>> res(A.size() , vector<dd>(B[0].size() , 0 ));
	for(int i = 0 ;i < A.size() ; i++){
		for(int j = 0 ;j < B[0].size() ; j++){
			res[i][j] = 0.0;
			for(int k = 0 ; k < B.size() ; k ++){
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return res;
}

// about == >> (0 , x_axis) , (1 , y_axis) , (2 , z_axis)
vector<dd> rotate(vector<dd> coordinate , double theta , int about){
	int dimension = coordinate.size();
	vector<vector<dd>> A(1 , vector<dd>(dimension + 1 , 0));
	A[0][dimension] = 1.0;
	for(int i = 0 ;i < coordinate.size() ; i++){
		A[0][i] = coordinate[i];
	}
	mat.resize(dimension + 1, vector<dd>(dimension + 1 , 0.0));
	about = (about + 1) % dimension;
	for(int i = 0 ; i < mat.size() ; i++){
		for(int j = 0 ; j < mat[0].size() ; j++){
			if(i == about && j == about){
				mat[i][j] = cos(theta);
			}else if(i == about && j == about + 1){
				mat[i][j] = -sin(theta);
			}else if(i == about + 1 && j == about){
				mat[i][j] = sin(theta);
			}else if(i == about + 1 && j == about + 1){
				mat[i][j] = cos(theta);
			}else if(i == j){
				mat[i][j] = 1;
			}
		}
	}

	vector<vector<dd>> output = mul(A , mat);
	vector<dd> res;
	for(int i = 0 ; i < output.size() ; i++){
		for(int j = 0; j < output[0].size() ; j++){
			res.pb(output[i][j]);
		}
	}
	return res;
}


int32_t main(){
	cout << fixed << setprecision(10) ;
	while(1){
		cout << endl << endl << "new test case ................." << endl;
		int dim; cin >> dim;
		vector<dd> coordinate;
		for(int i = 0; i < dim; i++){
			dd x; cin >> x;
			coordinate.pb(x);
		}
		double theta; cin >> theta;
		vector<dd> new_coordinate = rotate(coordinate , (theta * PI) / 180.0 , 1);
		for(int i = 0 ; i < new_coordinate.size() - 1 ;  i++){
			cout << new_coordinate[i] << " ";
		}
		cout << endl;
	}
}
/*
1 0 0
90
*/
/*
1 0 0
45
*/
/*
1 0 0
180
*/