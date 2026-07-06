#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Binary Search

 Intuition:
 - Lower Bound:
   Find the first index whose value is greater than or equal to x.
 - Upper Bound:
   Find the first index whose value is strictly greater than x.
 - Keep updating the answer whenever a valid candidate is found
   and continue searching towards the left.

 Time Complexity:
 - O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns n if no valid bound exists.
 - Handles duplicate elements correctly.
 - Works for targets outside the array range.
*/


int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;   
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int lowerBoundcpp(vector<int> arr, int n, int x) {
    int ans = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}

int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;   
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int upperBoundcpp(vector<int> arr, int n, int x) {
    int ans = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}

// https://www.naukri.com/code360/problems/lower-bound_8165382?leftPanelTabValue=PROBLEM 
// https://www.naukri.com/code360/problems/implement-upper-bound_8165383