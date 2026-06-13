
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Use Prefix Sum + Hash Map.
- Let presum be the sum of elements from index 0 to i.
- For every index, we need a previous prefix sum equal to (presum - k).
- If such a prefix sum exists, then the subarray between them has sum k.
- Store the frequency of each prefix sum in a map.
- Initialize mpp[0] = 1 to handle subarrays starting from index 0.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

int subarraySum(vector<int>& arr, int k) {
    int cnt = 0,presum = 0;

    map<int,int>mpp;
    mpp[0] = 1;

    for(int i=0;i<arr.size();i++){
        presum += arr[i];
        int remove = presum - k;
        cnt += mpp[remove]; 
        mpp[presum]++;
    }
    return cnt;


// https://leetcode.com/problems/subarray-sum-equals-k/description/