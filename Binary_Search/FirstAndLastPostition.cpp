#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Using Lower Bound & Upper Bound

 Intuition:
 - Find the first occurrence of the target using lower_bound().
 - If the target doesn't exist, return {-1, -1}.
 - Otherwise, find the first element greater than the target using upper_bound().
 - The last occurrence is one index before the upper bound.

 Time Complexity:
 - lower_bound(): O(log n)
 - upper_bound(): O(log n)
 - Overall: O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns {-1, -1} if the target is absent.
 - Handles duplicate elements.
 - Handles targets smaller than all elements or larger than all elements.
*/


int lowerBound(vector<int> arr, int n, int x) {
    int ans = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}
int upperBound(vector<int> arr, int n, int x) {
    int ans = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}

vector<int> searchRange(vector<int>& arr, int target) {
    int n = arr.size();
    int lb = lowerBound(arr,n,target);
    if(lb == n || arr[lb]!= target) return {-1,-1};
    return{lb,upperBound(arr,n,target) - 1};
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/