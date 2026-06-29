#include <bits/stdc++.h>
using namespace std;

/*
  Approach 1: Brute Force (Using Extra Array)

  Intuition:
  - Traverse both sorted arrays simultaneously using two pointers.
  - Compare the current elements and insert the smaller one into a temporary array.
  - After one array is exhausted, append the remaining elements of the other array.
  - Copy the first n elements back to arr1 and the remaining m elements to arr2.

  Time Complexity:
  - Merging both arrays: O(n + m)
  - Copying back to original arrays: O(n + m)
  - Overall: O(n + m)

  Space Complexity:
  - O(n + m) for the temporary merged array.

  Edge Cases:
  - One of the arrays is empty.
  - Arrays of different sizes.
  - Duplicate elements.
  - Already merged arrays.
  - Completely non-overlapping arrays.
*/

void merge1(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    vector<int>ans;

    int left = 0, right = 0;

    while(left<n && right<m){

        if(arr1[left] <= arr2[right]){
            ans.push_back(arr1[left]);
            left++;
        }
        else{
            ans.push_back(arr2[right]);
            right++;
        }

    }
    while(left<n){
        ans.push_back(arr1[left]);
        left++;
    }
    while(right<m){
        ans.push_back(arr2[right]);
        right++;
    }
    for(int i=0;i<n+m;i++){
        arr1[i] = ans[i];
    }
}

/*
  Approach 2: Better (Swap + Sort)

  Intuition:
  - Compare the largest element of arr1 with the smallest element of arr2.
  - If they are out of order, swap them.
  - Continue moving inward until all misplaced elements are swapped.
  - Finally, sort both arrays individually to restore sorted order.

  Time Complexity:
  - Swapping misplaced elements: O(min(n, m))
  - Sorting arr1: O(n log n)
  - Sorting arr2: O(m log m)
  - Overall: O(min(n, m) + n log n + m log m)

  Space Complexity:
  - O(1) extra space.

  Edge Cases:
  - One of the arrays is empty.
  - Arrays already in correct order (no swaps required).
  - Completely overlapping ranges.
  - Duplicate elements.
  - Arrays of different sizes.
*/

void merge2(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int left = n-1;
    int right = 0;

    while(left>=0 && right<m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left],arr2[right]);
            left--,right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

/*
  Approach 3: Optimal (Gap Method / Shell Sort Technique)

  Intuition:
  - Treat both arrays as a single virtual sorted array.
  - Initialize a gap equal to ceil((n + m) / 2).
  - Compare elements that are 'gap' distance apart and swap if they are out of order.
  - Reduce the gap by half (ceiling value) after each pass.
  - Repeat until the gap becomes 1, resulting in both arrays being sorted without extra space.

  Time Complexity:
  - Each pass processes O(n + m) elements.
  - Number of gap reductions: O(log(n + m))
  - Overall: O((n + m) log(n + m))

  Space Complexity:
  - O(1) extra space.

  Edge Cases:
  - One of the arrays is empty.
  - Arrays already sorted relative to each other.
  - Completely overlapping ranges.
  - Duplicate elements.
  - Arrays of different sizes.
*/

void swapIfGreater(vector<int>& arr1,vector<int>& arr2, int idx1,  int idx2){
    if(arr1[idx1] > arr2[idx2]){
        swap(arr1[idx1],arr2[idx2]);
    }
}

void merge3(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int len = (n + m);
    int gap = (len/2) + (len%2);

    while(gap>0){
        int left = 0;
        int right = left + gap;

        while(right < len){

            // arr1 & arr2
            if(left < n && right >= n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            
            // arr2 & arr2
            else if(left >= n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            
            // arr1 & arr1 
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        else{
            gap = (gap/2) + (gap%2);
        }
    }
}

// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1