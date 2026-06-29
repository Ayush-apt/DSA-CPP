#include <bits/stdc++.h>
using namespace std;

/*
===================== Brute Force =====================

Idea:
Whenever a 0 is found, mark all non-zero elements
in its row and column as -1. After traversal,
convert all -1 values to 0.

Time Complexity:
O((rows * cols) * (rows + cols))

Space Complexity:
O(1)
*/

void markr(vector<vector<int>>& mat,int row,int cols){
    for(int c = 0; c < cols; c++) {
        if(mat[row][c] != 0) {
            mat[row][c] = -1;
        }
    }
}
void markc(vector<vector<int>>& mat,int col,int rows){
    for(int r = 0; r < rows; r++) {
        if(mat[r][col] != 0) {
            mat[r][col] = -1;
        }
    }
}
void setZeroesBrute(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {

            if(mat[row][col] == 0) {
                markr(mat,row,cols);
                markc(mat,col,rows);
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
}

/*
===================== Better Approach =====================

Idea:
Use two auxiliary arrays:
row[] -> marks rows containing a 0
col[] -> marks columns containing a 0

First traversal:
Store affected rows and columns.

Second traversal:
If row[r] or col[c] is marked,
set mat[r][c] = 0.

Time Complexity:
O(rows * cols)

Space Complexity:
O(rows + cols)

*/

void setZeroesBetter(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();

    int row[rows] = {0};
    int col[cols] = {0};

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if(mat[r][c] == 0) {
                row[r] = 1;
                col[c] = 1;
            }
        }
    }
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if(row[r]==1 || col[c]==1) {
                mat[r][c] = 0;
            }
        }
    }
}

/*
===================== Optimal Approach =====================

Idea:
Use the first row and first column of the matrix
as marker arrays instead of creating row[] and col[].

mat[r][0] -> row marker
mat[0][c] -> column marker

A separate variable (col0) is used to track
whether the first column should be zeroed.

First traversal:
Store markers in first row and first column.

Second traversal:
Use markers to set matrix elements to 0.

Finally:
Handle first row and first column separately.

Time Complexity:
O(rows * cols)

Space Complexity:
O(1)
*/

void setZeroesOptimal(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();

    int col0 = 1;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){

            if(mat[r][c]==0){

                mat[r][0] = 0;

                if(c!=0){
                    mat[0][c] = 0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for(int r=1;r<rows;r++){
        for(int c=1;c<cols;c++){
            if(mat[0][c] == 0  || mat[r][0] == 0){
                mat[r][c] = 0;
            }
        }
    }

    if(mat[0][0] == 0){
        for(int i=0;i<cols;i++){
            mat[0][i] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<rows;i++){
            mat[i][0] = 0;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    setZeroesOptimal(mat);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/set-matrix-zeroes/description/