#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Staircase Search

 Intuition:
 - Start from the top-right corner of the matrix.
 - If the current element equals the target, return true.
 - If the current element is greater than the target, move left.
 - Otherwise, move down to the next row.
 - This eliminates one row or one column in every step.

 Time Complexity:
 - At most (row + col) moves.
 - Overall: O(row + col)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles single-row and single-column matrices.
 - Returns false when the target is outside the matrix range.
 - Works because every row and every column is sorted.
*/

bool searchMatrix1(vector<vector<int>>& mat, int target) {
    int row = mat.size(), col = mat[0].size();
    int i = 0, j = col-1;

    while(i < row &&  j >= 0){
        if(mat[i][j] == target) return true;

        if(mat[i][j] < target){
            i++;
        }
        else j--;
    }
    return false;
}

/*
 Approach 2: Binary Search on Flattened Matrix

 Intuition:
 - Treat the matrix as a single sorted array of size (row × col).
 - Use binary search on the virtual array indices.
 - Convert each index back into its corresponding row and column:
     - row = mid / col
     - col = mid % col
 - Continue binary search until the target is found or the search space is exhausted.

 Time Complexity:
 - Binary Search: O(log(row × col))
 - Overall: O(log(row × col))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles single-row and single-column matrices.
 - Returns false when the target is absent.
 - Works because the entire matrix is globally sorted.
*/

bool searchMatrix2(vector<vector<int>>& mat, int target) {
    int row = mat.size(), col = mat[0].size();
    int low = 0, high = (row*col - 1);

    while(low <= high){
        int mid = low + (high - low)/2;
        int r = mid/col, c = mid%col;

        if(mat[r][c] == target) return true;
        if(mat[r][c] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}

// My method
/*
 Approach 3: Two Binary Searches

 Intuition:
 - First, use binary search on the rows to locate the first row whose
   last element is greater than or equal to the target.
 - If no such row exists, the target cannot be present.
 - Perform a second binary search on the identified row.
 - If the target is found, return true; otherwise, return false.

 Time Complexity:
 - Binary Search on rows: O(log row)
 - Binary Search on columns: O(log col)
 - Overall: O(log row + log col)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles single-row and single-column matrices.
 - Returns false when the target is smaller than the first element or
   larger than the last element of the matrix.
 - Correctly handles cases where the target is absent from the selected row.
*/

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = mat.size();
    int col = mat[0].size();
    int ans = -1;

    int low1 = 0, high1 = row-1;
    while(low1 <= high1){
        int mid = (low1 + high1)/2;

        if(target <= mat[mid][col-1]){
            ans = mid;
            high1 = mid - 1;
        }
        else{
            low1 = mid + 1;
        }
    }
    if(ans == -1) return false;

    int low2 = 0, high2 = col-1;
    while(low2 <= high2){
        int mid = (low2 + high2)/2;

        if(mat[ans][mid] == target) return true;
        if(mat[ans][mid] > target){
            high2 = mid-1;
        }
        else{
            low2 = mid+1;
        }
    }

    return false;
}

// https://leetcode.com/problems/search-a-2d-matrix/description/