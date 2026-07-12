#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - The smallest divisor must lie between 1 and the maximum element in the array.
 - Use binary search to find the minimum divisor such that the sum of
   ceil(nums[i] / divisor) for all elements does not exceed the threshold.
 - For each candidate divisor, calculate the required sum.
 - If the sum is within the threshold, try a smaller divisor.
 - Otherwise, increase the divisor.
 - When the search ends, 'low' stores the smallest valid divisor.

 Time Complexity:
 - Finding the maximum element: O(n)
 - Binary Search: O(log(maxElement))
 - Calculating the division sum in each iteration: O(n)
 - Overall: O(n log(maxElement))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles a single-element array.
 - Handles the minimum possible divisor (1).
 - Handles large array values correctly using ceiling division.
 - Works when the answer is equal to the maximum element.
*/

int maxEl(vector<int>& arr, int n){
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        mx = max(mx, arr[i]);
    }
    return mx;
}

int div(vector<int>& arr, int val){
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        cnt += ceil((double)arr[i]/val);
    }
    return cnt;
}

int smallestDivisor(vector<int>& arr, int th) {
    int n = arr.size();
    int low = 1, high = maxEl(arr,n);

    while(low <= high){
        int mid = low + (high-low)/2;
        int val = div(arr, mid);
        if(val <= th){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/