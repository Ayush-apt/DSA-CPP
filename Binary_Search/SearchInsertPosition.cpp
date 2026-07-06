#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Binary Search

 Intuition:
 - Search for the target using binary search.
 - If found, return its index.
 - Otherwise, keep track of the first element greater than the target.
 - That position is where the target should be inserted.

 Time Complexity:
 - O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns 0 if the target is smaller than all elements.
 - Returns n if the target is greater than all elements.
 - Returns the existing index if the target is already present.
*/


int searchInsert(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;
        if (arr[mid]==target) return mid;
        else if (arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

// https://leetcode.com/problems/search-insert-position/