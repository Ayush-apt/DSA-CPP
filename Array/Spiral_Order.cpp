#include <bits/stdc++.h>
using namespace std;

/*

Approach:
1. Initialize four boundaries: top, bottom, left, and right.
2. Traverse the top row from left -> right, then increment top.
3. Traverse the right column from top -> bottom, then decrement right.
4. If rows remain, traverse the bottom row from right -> left, then decrement bottom.
5. If columns remain, traverse the left column from bottom -> top, then increment left.
6. Repeat until all elements are visited.

Time Complexity:
- O(rows * cols)
- Each element is visited exactly once.

Space Complexity:
- O(rows * cols) for the answer vector.
- O(1) auxiliary space (excluding output).

Edge Cases:
- Single row matrix (1 x n)
- Single column matrix (n x 1)
- Square matrices (n x n)
- Rectangular matrices (n x m)
- Odd-sized matrices with a single center element

Note:
- The conditions (top <= bottom) and (left <= right)
  prevent duplicate traversal when only one row
  or one column remains.

*/

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int left = 0, right = cols-1;
    int top = 0, bottom = rows-1;

    vector<int> ans;

    while(top<=bottom && left<=right){

        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
    
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
    
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){          
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
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
    vector<int>ans = spiralOrder(mat);
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/spiral-matrix/description/