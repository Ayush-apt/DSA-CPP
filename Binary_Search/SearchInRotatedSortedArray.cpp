#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Rotated Sorted Array

 Intuition:
 - In a rotated sorted array, at least one half (left or right) is always sorted.
 - Find the middle element.
 - If it matches the target, return its index.
 - Otherwise, determine which half is sorted:
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
 - O(log n)
   - The search space is halved in every iteration.

 Space Complexity:
 - O(1)
   - No extra space is used.
*/


int search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;

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
            if(target >= arr[mid] && arr[high] >= target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return ans;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/