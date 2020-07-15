//https://www.bragitoff.com/2018/02/determinant-matrix-c-program/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5;
double mat[N][N];

int gaussElimination(int m, int n, double mat[][N]){
    int swapCount = 0;
    for(int i = 0 ; i < m - 1 ; i++){
        //Partial Pivoting
        for(int k = i + 1 ; k < m ; k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(mat[i][i]) < fabs(mat[k][i])){
                swapCount++; //Swap the rows
                for(int j = 0 ; j < n ; j++){                
                    swap(mat[i][j] , mat[k][j]);
                }
            }
        }
        //Begin Gauss Elimination
        for(int k = i + 1 ; k < m ; k++){
            double  term = mat[k][i] / mat[i][i];
            for(int j = 0 ; j < n ; j++){
                mat[k][j] = mat[k][j] - term * mat[i][j];
            }
        }
    }
    return swapCount;       
}

double determinant(int n , double mat[][N]){
    double det = 1;
    int swapCount = gaussElimination(n , n , mat);
    for(int i = 0 ; i < n ; i++){
        det = det * mat[i][i];
    }
    return det * pow(-1 , swapCount);
}

int32_t main(){
    int n , m; 
    cout << "dimension of matrix (Row / Col) :: " ; cin >> n >> m;
    cout << "enter elements :: " << endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> mat[i][j];
        }
    } 
    cout << "determinant is :: " << determinant(n , mat) << endl;
}
/*
3 3
1 1 1
1 2 3
1 4 9
*/