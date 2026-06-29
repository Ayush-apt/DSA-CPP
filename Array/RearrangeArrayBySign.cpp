#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Traverse the array and store positive and negative elements
  in separate vectors.
- Place positive numbers at even indices and negative numbers
  at odd indices in the original array.
- Return the rearranged array.

Time Complexity: O(n)
- O(n) to separate elements + O(n/2) to rearrange.
- Simplifies to O(n).

Space Complexity: O(n)
- Extra space used for positive and negative vectors.
*/

vector<int> rearrangeArray1(vector<int>& arr) {
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    return arr;
}

/*
Approach:
- Create an answer array of size n.
- Maintain two pointers:
    l = 0 for even indices (positive numbers)
    r = 1 for odd indices (negative numbers)
- Traverse the array once:
    - Place positives at l and increment l by 2.
    - Place negatives at r and increment r by 2.
- Return the answer array.

Time Complexity: O(n)
- Single traversal of the array.

Space Complexity: O(n)
- Extra answer array of size n.
*/

vector<int> rearrangeArray2(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n,0);
    int l = 0;
    int r = 1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[r] = arr[i];
            r += 2;
        }
        else{
            ans[l] = arr[i];
            l += 2;
        }
    }
    return ans;
}

// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/