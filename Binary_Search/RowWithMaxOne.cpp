#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Binary Search on Each Row

 Intuition:
 - Since every row is sorted, use binary search to find the first occurrence
   of 1 in each row.
 - The number of 1s in a row is equal to:
     col - (index of the first 1).
 - Keep track of the row with the maximum number of 1s.
 - If no row contains a 1, return -1.

 Time Complexity:
 - Binary Search for each row: O(log col)
 - Total for all rows: O(row * log col)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles matrices containing all 0s.
 - Handles matrices containing all 1s.
 - Correctly identifies the first row in case of a tie.
*/

int rowWithMax1s(vector<vector<int>> &mat, int row, int col) {
        int ind = -1, num = 0;
        for(int r=0; r<row; r++){
            int low = 0, high = col - 1;
            int ans = 0;
            while(low <= high){
                int mid = (low+high)/2;
                if(mat[r][mid] == 1){
                    high = mid-1;
                }
                if(mat[r][mid] == 0){
                    low = mid+1;
                }
            }
            int val = col - low;
            if(val > num){
                num = val;
                ind = r;
            }
        }
        return ind;
}

/*
 Approach 2: Top-Right Corner Traversal

 Intuition:
 - Start from the top-right corner of the matrix.
 - If the current element is 1, update the answer and move left to search
   for more 1s in the same row.
 - If the current element is 0, move down to the next row.
 - The traversal guarantees that the last recorded row is the one with
   the maximum number of 1s.

 Time Complexity:
 - At most (row + col) moves.
 - Overall: O(row + col)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles matrices containing all 0s.
 - Handles matrices containing all 1s.
 - Correctly returns -1 when no 1s are present.
 - Correctly identifies the first row in case of a tie.
*/

int rowWithMax1s(vector<vector<int>> &mat, int row, int col) {
    int ind = -1;
    int c = col-1;

    int r = 0;
    while(0 <= c && r < row){
        if(mat[r][c] == 1){
            ind = r;
            c--;
        }
        else{
            r++;
        }   
    }
    return ind;
}

// https://www.naukri.com/code360/problems/row-with-maximum-1-s_1112656?leftPanelTabValue=PROBLEM