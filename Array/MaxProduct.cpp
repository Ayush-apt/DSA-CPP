#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Brute Force

 Intuition:
 - Consider every possible subarray.
 - For each starting index, keep extending the subarray one element at a time.
 - Maintain the running product instead of recomputing it for every subarray.
 - Update the maximum product encountered.

 Time Complexity:
 - Outer loop: O(n)
 - Inner loop: O(n)
 - Overall: O(n²)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles positive, negative, and zero values.
 - Works when the maximum product consists of a single element.
 - Correctly considers every possible subarray.
*/

int maxProduct1(vector<int>& arr){
    int n = arr.size();
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        int mxp = 1;
        for(int j=i;j<n;j++){
            mxp *= arr[j];
            ans = max(ans,mxp);
        }
    }
    return ans;
}


/*
 Approach 2: Prefix & Suffix Traversal (Optimal)

 Intuition:
 - Traverse the array simultaneously from both left and right.
 - Maintain prefix and suffix products.
 - Reset the running product to 1 whenever it becomes 0, since a zero splits the array into independent segments.
 - The maximum product subarray is captured by either the prefix or suffix traversal, especially when an odd number of negative values exists.
 - Update the answer using the maximum of the current prefix and suffix products.

 Time Complexity:
 - Single traversal: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles arrays containing zeros by restarting the product.
 - Handles both even and odd counts of negative numbers.
 - Works when the maximum product is a single element.
 - Correctly handles arrays consisting entirely of negative values.
*/

int maxProduct2(vector<int>& arr){
    int n = arr.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for(int i = 0;i<n;i++){
        if(pre==0) pre = 1;
        if(suff==0) suff = 1;

        pre *= arr[i];
        suff *= arr[n-1-i];
        ans = max(ans,max(pre,suff));
    }
    return ans;
}

// https://leetcode.com/problems/maximum-product-subarray/description/