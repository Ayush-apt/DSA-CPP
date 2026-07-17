#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search

 Intuition:
 - For any index i, the number of missing positive integers before arr[i]
   is given by: arr[i] - (i + 1).
 - Use binary search to find the first index where the number of missing
   integers is greater than or equal to k.
 - If the missing count is less than k, move to the right half.
 - Otherwise, move to the left half.
 - After the search, 'low' represents the number of array elements before
   the kth missing positive number.
 - Therefore, the answer is obtained by adding k to 'low'.

 Time Complexity:
 - Binary Search: O(log n)
 - Overall: O(log n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles the case where the kth missing number appears before the first element.
 - Handles the case where the kth missing number appears after the last element.
 - Handles arrays with no missing numbers at the beginning.
*/

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int val = arr[mid] - (mid+1);
        if(val < k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low+k;
}

// https://leetcode.com/problems/kth-missing-positive-number/