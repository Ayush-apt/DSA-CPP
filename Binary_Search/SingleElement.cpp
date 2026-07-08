#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search Using Index Parity

 Intuition:
 - In the sorted array, every element appears exactly twice except one.
 - Before the single element:
    - Pairs start at even indices.
    - (even, odd) -> (0,1), (2,3), (4,5), ...
 - After the single element:
    - The pairing pattern shifts by one index.
    - Pairs start at odd indices.
 - Find the middle element.
 - If it is different from both its neighbours, it is the required single element.
 - Otherwise:
    1. If the pairing at 'mid' follows the expected pattern
       (odd index matches previous or even index matches next),
       the single element lies in the right half.
    2. Otherwise, the pairing has already shifted,
       so the single element lies in the left half.
 - Continue narrowing the search space until the unique element is found.

 Time Complexity:
 - O(log n)
   - The search space is halved in every iteration.

 Space Complexity:
 - O(1)
   - No extra space is used.
*/

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    int low = 1, high = n-2;

    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
        
        // We are in left
        if((mid%2 != 0 && arr[mid-1] == arr[mid]) ||
            (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }
        // We are in right
        else {
            high = mid-1;
        }
    }
    return -1;
}

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/