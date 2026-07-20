#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - The minimum possible largest subarray sum must be at least the maximum
   element and at most the sum of all elements.
 - Use binary search within this range to find the smallest feasible
   maximum subarray sum.
 - For each candidate value, greedily form subarrays without exceeding
   the candidate sum.
 - If the array can be split into at most k subarrays, try a smaller
   maximum sum.
 - Otherwise, increase the candidate sum.
 - When the search ends, 'low' stores the minimum possible largest
   subarray sum.

 Time Complexity:
 - Finding the maximum element: O(n)
 - Calculating the total sum: O(n)
 - Binary Search: O(log(sum of array))
 - Feasibility check for each iteration: O(n)
 - Overall: O(n log(sum of array))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles a single-element array.
 - Handles k = 1, where the answer is the total array sum.
 - Handles k = n, where the answer is the maximum element.
 - Ensures each subarray is non-empty and consists of contiguous elements.
*/

bool splitCheck(vector<int>& arr, int mid, int k){
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] + sum <= mid){
            sum += arr[i];
        }
        else{
            cnt++;
            sum = arr[i];
        }
    }
    if(cnt <= k) return true;
    else return false;
}


int splitArray(vector<int> &arr, int k)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){
        int mid = low + (high-low)/2;
        bool val = splitCheck(arr, mid, k);

        if(val == true){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://leetcode.com/problems/split-array-largest-sum/
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM


