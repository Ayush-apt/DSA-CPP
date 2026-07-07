#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search to Find Minimum in a Rotated Sorted Array

 Intuition:
 - In a rotated sorted array, at least one half (left or right) is always sorted.
 - Maintain a variable 'min_num' to store the smallest element found so far.
 - Find the middle element.
 - If the left half is sorted:
    - The first element of the left half is its minimum.
    - Update 'min_num' with arr[low].
    - Search in the right half, where the rotation point (minimum) may exist.
 - Otherwise:
    - The rotation point lies in the left half.
    - Update 'min_num' with arr[mid].
    - Continue searching in the left half.
 - Repeat until the search space becomes empty.
 - Return the smallest value stored in 'min_num'.

 Time Complexity:
 - O(log n)
   - The search space is reduced by half in every iteration.

 Space Complexity:
 - O(1)
   - No extra space is used.
*/

int findMin(vector<int>& arr) {
    int n = arr.size();
    int low = 0, high = n-1;
    int min_num = INT_MAX;

    while(low <= high){
        int mid = low + (high - low)/2;

        // search space is already sorted 
        // then arr[low] will be always smaller in that space
        if(arr[low] <= arr[high]){
            min_num = min(min_num, arr[low]);
        }
        
        if(arr[low] <= arr[mid]){
            min_num = min(min_num,arr[low]);
            low = mid+1;
        }
        else{
            min_num = min(min_num,arr[mid]);
            high = mid-1;
        }
    }
    return min_num;
}

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/