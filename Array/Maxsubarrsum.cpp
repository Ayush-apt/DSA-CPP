#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Generate all subarrays starting from each index.
// Keep track of the maximum subarray sum.
//
// Time Complexity: O(n²)
// Space Complexity: O(1)
int maxSubArray1(vector<int>& arr) {
    int n = arr.size();
    int ans = arr[0]; 
    for(int i=0;i<n;i++){
        int sub = arr[i];
        int sum = arr[i];
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            if(sum>sub){
                sub = sum;
            }
        }
        if(sub>ans){
            ans = sub;
        }
    }
    return ans;
}

// Kadane's Algorithm (Optimal)
// Maintain a running sum.
// If sum becomes negative, reset it to 0.
// Store the maximum sum seen so far.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArray2(vector<int>& arr) {
    int max = LONG_MIN;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}

// https://leetcode.com/problems/maximum-subarray/


// To Print the subarray

int maxSubarraySum(vector<int>& arr) {
    int max = LONG_MIN;
    int sum = 0;
    int ans_st =0;
    int ans_end=0;
    for(int i=0;i<arr.size();i++){
        int st = 0;
        if(sum==0){
            st = i;
        }  
        sum += arr[i];
        if(sum>max){
            max = sum;
            ans_st = st, ans_end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=ans_st;i<=ans_end;i++){
        cout << arr[i] << " " ;
    }
    return max;
}
