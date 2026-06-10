#include <bits/stdc++.h>
using namespace std;


/*
Approach:
1. Traverse from right to left and find the first index (pivot)
   such that arr[i] < arr[i + 1].
2. If no such index exists, the array is in descending order,
   so reverse the entire array to get the smallest permutation.
3. Otherwise, find the first element from the right that is
   greater than arr[pivot] and swap them.
4. Reverse the suffix after the pivot to obtain the next
   lexicographically greater permutation.

Time Complexity: O(N)
- Finding the pivot: O(N)
- Finding the next greater element: O(N)
- Reversing the suffix: O(N)

Space Complexity: O(1)
- No extra space is used; all operations are performed in-place.

*/

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1 , arr.end());
}