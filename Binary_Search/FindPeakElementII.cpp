#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Columns

 Intuition:
 - Perform binary search on the columns of the matrix.
 - For each middle column, find the row containing the maximum element
   in that column.
 - Compare this element with its left and right neighbors.
 - If it is greater than both neighbors, it is a peak.
 - If the left neighbor is greater, move to the left half.
 - Otherwise, move to the right half.
 - Continue until a peak element is found.

 Time Complexity:
 - Finding the maximum element in a column: O(n)
 - Binary Search on columns: O(log m)
 - Overall: O(n log m)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles single-row and single-column matrices.
 - Treats out-of-bound neighbors as -1.
 - Correctly finds any valid peak when multiple peaks exist.
*/

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
    int maxValue = -1;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }

    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int maxRowIndex = findMaxIndex(mat, n, m, mid);

        int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left &&
            mat[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

// https://leetcode.com/problems/find-a-peak-element-ii/