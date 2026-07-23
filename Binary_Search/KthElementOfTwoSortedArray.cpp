#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Two Pointers

 Intuition:
 - Traverse both sorted arrays simultaneously using two pointers.
 - At each step, pick the smaller element as it would appear in the merged order.
 - Keep a count of the merged elements processed.
 - When the count reaches (k - 1), return the current element as the kth smallest.

 Time Complexity:
 - Traversing both arrays: O(n1 + n2)
 - Overall: O(n1 + n2)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles arrays of different sizes.
 - Handles one empty array.
 - Correctly returns the kth element regardless of which array it belongs to.
*/

int kthElement1(vector<int> &arr1, vector<int>& arr2, int n1, int n2, int k){
    int cnt = 0;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt == (k-1)) return arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == (k-1)) return arr2[j];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt == (k-1)) return arr1[i];
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt == (k-1)) return arr2[j];
        cnt++;
        j++;
    }
    return 0;
}

/*
 Approach 2: Binary Search on Partition

 Intuition:
 - Perform binary search on the smaller array to partition both arrays
   such that exactly k elements lie in the left half.
 - The correct partition satisfies:
     - Every element in the left half is less than or equal to every
       element in the right half.
 - Once the valid partition is found, the kth smallest element is the
   maximum element among the left partitions.
 - Sentinel values (INT_MIN and INT_MAX) handle partitions at the
   boundaries of the arrays.

 Time Complexity:
 - Binary Search on the smaller array: O(log(min(n1, n2)))
 - Overall: O(log(min(n1, n2)))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles arrays of different sizes.
 - Handles one empty array.
 - Correctly handles k = 1 and k = n1 + n2.
 - Correctly handles partitions at the beginning or end of either array.
*/

int kthElement2(vector<int> &arr1, vector<int>& arr2, int n1, int n2, int k){
    if(n1 > n2) return kthElement2(arr2,arr1,n2,n1,k);
    int low = max(k-n2, 0), high = min(k, n1);
    int left = k;
    int n = n1+n2;
    
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

// https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159?leftPanelTabValue=PROBLEM