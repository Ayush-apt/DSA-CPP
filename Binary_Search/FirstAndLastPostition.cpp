#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Using STL (lower_bound & upper_bound)

 Intuition:
 - Use lower_bound() to find the first occurrence of the target.
 - If the target is not present, return {-1, -1}.
 - Otherwise, use upper_bound() to find the first element greater than the target.
 - The last occurrence is one index before the upper bound.

 Time Complexity:
 - lower_bound(): O(log n)
 - upper_bound(): O(log n)
 - Overall: O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns {-1, -1} if the target is absent.
 - Handles duplicate elements correctly.
 - Works when the target is the first or last element.
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


/*
 Approach 2: Two Binary Searches

 Intuition:
 - Perform one binary search to find the first occurrence of the target.
 - Whenever the target is found, store the index and continue searching to the left.
 - Perform another binary search to find the last occurrence.
 - Whenever the target is found, store the index and continue searching to the right.
 - Return both indices as the required range.

 Time Complexity:
 - First Binary Search: O(log n)
 - Second Binary Search: O(log n)
 - Overall: O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns {-1, -1} if the target is absent.
 - Handles arrays with a single occurrence or multiple duplicates.
 - Works when the target is at the beginning or end of the array.
*/

int bs1(vector<int>& arr, int n, int x){
    int low = 0, high = n-1;
    int st = -1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            st = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid + 1;
    }
    return st;
}

int bs2(vector<int>& arr, int n, int x){
    int low = 0, high = n-1;
    int en = -1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            en = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid + 1;
    }
    return en;
}

vector<int> searchRange(vector<int>& arr, int target) {
    int n = arr.size();
    return {bs1(arr,n,target), bs2(arr,n,target)};
}


// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// To count Number of occurrences : End - Start + 1;
// https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456?leftPanelTabValue=PROBLEM