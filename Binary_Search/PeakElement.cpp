#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search

 Intuition:
 - A peak element is greater than both of its adjacent elements.
 - First, handle the edge cases where the peak lies at the beginning or the end of the array.
 - Perform binary search on the remaining portion of the array.
 - If the middle element is a peak, return its index.
 - Otherwise, move towards the side containing the larger adjacent element,
   since that side is guaranteed to contain at least one peak.

 Time Complexity:
 - Binary Search: O(log n)
 - Overall: O(log n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles a single-element array.
 - Handles the peak at the first element.
 - Handles the peak at the last element.
 - Works for strictly increasing and strictly decreasing arrays.
*/

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    int low = 1, high = n-2;

    if(n==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
        else if(arr[mid+1] > arr[mid]) low = mid+1;
        else if(arr[mid-1] > arr[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

// https://leetcode.com/problems/find-peak-element/