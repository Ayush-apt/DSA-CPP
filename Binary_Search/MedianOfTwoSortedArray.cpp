#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Merge Two Sorted Arrays

 Intuition:
 - Merge both sorted arrays into a single sorted array using the
   two-pointer technique.
 - Once merged, the median is simply the middle element (for odd length)
   or the average of the two middle elements (for even length).

 Time Complexity:
 - Merging both arrays: O(n1 + n2)
 - Overall: O(n1 + n2)

 Space Complexity:
 - O(n1 + n2) for the merged array.

 Edge Cases:
 - Handles arrays of different sizes.
 - Handles one empty array.
 - Correctly computes the median for both odd and even total lengths.
*/

double findMedianSortedArrays1(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0;
    vector<int>arr3;
    while(i<n1 && j<n2){
    if(arr1[i] < arr2[j]){
        arr3.push_back(arr1[i]);
        i++;
    }
    else{
        arr3.push_back(arr2[j]);
        j++;
    }
    }
    while(i<n1){
        arr3.push_back(arr1[i]);
        i++;
    }    
    while(j<n2){
        arr3.push_back(arr2[j]);
        j++;
    }
    int n = n1+n2;
    if(n%2 == 1){
        return arr3[n/2];
    }    
    else{
        return ((double)(arr3[n/2]) + (double)(arr3[n/2 - 1])) / 2.0;
    }
}


/*
 Approach 2: Two Pointers without Extra Space

 Intuition:
 - Traverse both sorted arrays using two pointers without creating a
   merged array.
 - Keep track of the current merged index and record only the elements
   required to compute the median.
 - This avoids storing the entire merged array while preserving the
   sorted order.

 Time Complexity:
 - Traversing both arrays: O(n1 + n2)
 - Overall: O(n1 + n2)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles arrays of different sizes.
 - Handles one empty array.
 - Correctly computes the median for both odd and even total lengths.
*/

double findMedianSortedArrays2(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0;
    int n = n1+n2;
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            if(cnt == ind1) ind1el = arr1[i];
            if(cnt == ind2) ind2el = arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) ind1el = arr2[j];
            if(cnt == ind2) ind2el = arr2[j];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt == ind1) ind1el = arr1[i];
        if(cnt == ind2) ind2el = arr1[i];
        cnt++;
        i++;
    }    
    while(j<n2){
        if(cnt == ind1) ind1el = arr2[j];
        if(cnt == ind2) ind2el = arr2[j];
        cnt++;
        j++;
    }
    if(n%2 == 1){
        return ind2el;
    }    
    else{
        return ((double)(ind1el) + (double)(ind2el)) / 2.0;
    }
}

/*
 Approach 3: Binary Search on Partition

 Intuition:
 - Perform binary search on the smaller array to partition both arrays
   into left and right halves.
 - The correct partition satisfies:
     - Every element in the left half is less than or equal to every
       element in the right half.
 - Once the valid partition is found:
     - For an odd total length, the median is the maximum element of
       the left half.
     - For an even total length, the median is the average of the
       maximum left element and the minimum right element.
 - Sentinel values (INT_MIN and INT_MAX) handle partitions at the
   array boundaries.

 Time Complexity:
 - Binary Search on the smaller array: O(log(min(n1, n2)))
 - Overall: O(log(min(n1, n2)))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles arrays of different sizes.
 - Handles one empty array.
 - Correctly handles partitions at the beginning or end of either array.
 - Computes the median for both odd and even total lengths.
*/

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1+n2;
    if(n1 > n2) return findMedianSortedArrays(arr2,arr1);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1)/2;
    
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
            if(n % 2 == 1)return max(l1, l2);
            return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/