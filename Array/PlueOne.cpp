#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Traversal from Right to Left

 Intuition:
 - Start from the last digit since adding one affects the least significant digit first.
 - If the current digit is not 9, increment it and return the updated array.
 - If the digit is 9, change it to 0 and propagate the carry to the previous digit.
 - If all digits are 9, insert 1 at the beginning to accommodate the extra carry.

 Time Complexity:
 - Worst Case: O(n)
 - Best Case: O(1) when the last digit is not 9

 Space Complexity:
 - O(1) extra space
 - O(n) in the worst case due to insertion at the beginning of the vector

 Edge Cases:
 - Handles numbers ending with one or more 9s.
 - Handles the case where all digits are 9 (e.g., 999 → 1000).
 - Handles single-digit inputs.
*/

vector<int> plusOne(vector<int>& arr) {
    int n = arr.size();
    for(int i = n-1; i>=0; i--){
        if(arr[i] != 9){
            arr[i]++;
            return arr;
        }
        arr[i] = 0;
    }
    arr.insert(arr.begin(),1);
    return arr;
}

// https://leetcode.com/problems/plus-one/description/
