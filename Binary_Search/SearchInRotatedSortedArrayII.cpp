#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Rotated Sorted Array with Duplicates

 Intuition:
 - In a rotated sorted array, one half is usually sorted.
 - However, when duplicates are present, it may become impossible to determine
   which half is sorted if arr[low] == arr[mid] == arr[high].
 - In such an ambiguous case:
    - Shrink the search space by moving both pointers inward
      (low++ and high--) and continue searching.
 - Otherwise:
    1. If the left half is sorted:
       - Check if the target lies within this range.
       - If yes, search the left half.
       - Otherwise, search the right half.
    2. If the right half is sorted:
       - Check if the target lies within this range.
       - If yes, search the right half.
       - Otherwise, search the left half.
 - Repeat until the target is found or the search space becomes empty.

 Time Complexity:
 - Average Case: O(log n)
   - The search space is roughly halved in each iteration.
 - Worst Case: O(n)
   - When many duplicate elements are present, the search space may only
     shrink by one element from each end in each iteration.

 Space Complexity:
 - O(1)
   - No extra space is used.
*/

bool search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return true;

        // Condition check
        if(arr[low] == arr[high] && arr[low] == arr[mid]){
            low++;
            high--;
            continue;
        }
        // left sorted
        if(arr[mid] >= arr[low]){
            if(arr[mid] >= target && target >= arr[low]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // right sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/