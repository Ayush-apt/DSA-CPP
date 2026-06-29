#include <bits/stdc++.h>
using namespace std;

/*
Approach: Rotate the matrix 90° clockwise in-place
Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
Step 2: Reverse each row to complete the rotation
Time Complexity: O(n^2) (traversing all elements twice)
Space Complexity: O(1) (in-place modification, no extra matrix used)
*/

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}

// https://leetcode.com/problems/rotate-image/description/