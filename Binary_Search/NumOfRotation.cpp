#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search to Find the Rotation Count

 Intuition:
 - The number of rotations is equal to the index of the minimum element.
 - In a rotated sorted array, at least one half (left or right) is always sorted.
 - Maintain:
    - 'ans' to store the smallest element found so far.
    - 'idx' to store the index of the smallest element.
 - If the current search range is already sorted:
    - The first element (arr[low]) is the minimum of that range.
    - Update 'ans' and 'idx' if needed.
    - Break, as no smaller element can exist in this sorted range.
 - Otherwise:
    1. If the left half is sorted:
       - The smallest element in this half is arr[low].
       - Update 'ans' and 'idx' if it is smaller.
       - Search in the right half.
    2. If the right half contains the rotation point:
       - arr[mid] can be the minimum candidate.
       - Update 'ans' and 'idx' if it is smaller.
       - Search in the left half.
 - Return 'idx', which represents the number of rotations.

 Time Complexity:
 - O(log n)
   - The search space is halved in every iteration.

 Space Complexity:
 - O(1)
   - No extra space is used.
*/

int findKRotation(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;
    int idx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                idx = low;
                ans = arr[low];
            }
            break;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                idx = low;
                ans = arr[low];
            }
            low = mid+1;
        }
        else{
            if(arr[mid] < ans){
                idx = mid;
                ans = arr[mid];
            }
            high = mid-1;
        }
    }
    return idx;
}

// https://www.naukri.com/code360/problems/rotation_7449070?leftPanelTabValue=PROBLEM