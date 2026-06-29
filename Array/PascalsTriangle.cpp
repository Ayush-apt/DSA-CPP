#include <bits/stdc++.h>
using namespace std;

/*
=========================================
TYPE 1 : Find Element at (row, col)
=========================================

Problem:
Given a row and column, find the element present at that
position in Pascal's Triangle.

Approach:
Use the nCr formula:
Element = (row C col)

Instead of calculating factorials, compute nCr directly
using the multiplicative formula to avoid overflow and
reduce computations.

Time Complexity: O(col)
Space Complexity: O(1)
*/

int PascalTriangle_Type1(int row,int col){
    long long value = 1;
    for(int i=0;i<col;i++){
        value = value * (row-i);
        value = value / (i+1);
    }
    return value;
}

/*
=========================================
TYPE 2 : Generate a Particular Row
=========================================

Problem:
Given a row index, generate the entire row of Pascal's Triangle.

Approach:
The first element is always 1.
Each next element can be generated from the previous one using:

next = current * (rowIndex - currentPosition + 1) / currentPosition

This avoids repeatedly calculating nCr.

Time Complexity: O(rowIndex)
Space Complexity: O(rowIndex)
*/

vector<int> PascalTriangle_Type2(int rowIndex){
    vector<int> row;
    long long curr = 1;

    row.push_back(1);

    for (int i = 1; i <= rowIndex; i++) {
        curr = curr * (rowIndex - i + 1) / i;
        row.push_back(curr);
    }

    return row;
}

/*
=========================================
TYPE 3 : Generate Entire Pascal Triangle
=========================================

Problem:
Given number of rows, generate the complete Pascal Triangle.

Approach:
Generate each row independently using the optimized
row generation logic from Type 2.

For every row:
- First element is 1.
- Remaining elements are generated from the previous element.

Time Complexity: O(rows²)
Space Complexity: O(rows²)
*/

vector<vector<int>> PascalTriangle_Type3(int rows){
    vector<vector<int>>ans;

    for(int row=0;row<rows;row++){
        
        vector<int> temp;
        long long curr = 1;
        temp.push_back(1);
        for(int col=1;col<=row;col++){
            curr = curr * (row - col + 1) /col;
            temp.push_back(curr);
        }
        ans.push_back(temp);
    }
    return ans;
};

int main(){
    int n,row,col;
    cin >> n >> row >> col;
    vector<int>arr(n);

    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // cout << PascalTriangle_Type1(row,col);
    
    // vector<int>ans = PascalTriangle_Type2(row);

    vector<vector<int>>ans = PascalTriangle_Type3(row);

    // for(int i=0;i<ans.size();i++){
    //     cout << ans[i] << " ";
    // }
    cout << endl;
    return 0;
}
