#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Binary Search (Iterative / Recursive)

 Intuition:
 - Since the array is sorted, compare the target with the middle element.
 - If the middle element matches the target, return its index.
 - If the target is greater, search the right half.
 - Otherwise, search the left half.
 - Repeat until the element is found or the search space becomes empty.

 Time Complexity:
 - O(log n) in both iterative and recursive approaches.

 Space Complexity:
 - Iterative: O(1)
 - Recursive: O(log n) due to recursion stack.

 Edge Cases:
 - Returns -1 if the target is not present.
 - Works for single-element arrays.
 - Handles targets smaller than the first or larger than the last element.
*/

// Iterative Code

int search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

// Recursive Code

int binarysearch(vector<int>& arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high)/2;

    if(arr[mid] == target) return mid;
    else if(target > arr[mid]){
        return binarysearch(arr, mid+1, high, target);
    }
    else{
        return binarysearch(arr, low, mid-1, target);
    }
}

int search(vector<int>& arr, int target){
    int n = arr.size();
    return binarysearch(arr, 0, n-1, target);
}


// https://leetcode.com/problems/binary-search/