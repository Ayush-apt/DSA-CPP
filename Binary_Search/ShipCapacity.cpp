#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - The minimum ship capacity must be at least the maximum package weight
   and at most the sum of all package weights.
 - Use binary search within this range to find the smallest capacity that
   allows all packages to be shipped within the given number of days.
 - For each candidate capacity, simulate the shipping process and count
   the number of days required.
 - If the required days are within the limit, try a smaller capacity.
 - Otherwise, increase the capacity.
 - When the search ends, 'low' stores the minimum feasible ship capacity.

 Time Complexity:
 - Finding the maximum weight: O(n)
 - Calculating the total weight: O(n)
 - Binary Search: O(log(sum of weights))
 - Simulating shipping for each iteration: O(n)
 - Overall: O(n log(sum of weights))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles a single package.
 - Handles the case where all packages must be shipped in one day.
 - Handles the case where one package is shipped per day.
 - Ensures the capacity is never smaller than the heaviest package.
*/

int arrSum(vector<int>weights){
    int sum = 0;
    for(int i=0; i<weights.size(); i++){
        sum += weights[i];

    }
    return sum;
}

int maxi(vector<int>weights){
    int maxi = INT_MIN;
    for(int i=0; i<weights.size(); i++){
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}

int dayCnt(vector<int>& weights, int cap) {
    int n = weights.size();
    int days = 1;
    int load = 0;
    for(int i=0; i<n; i++){
        if(load + weights[i] > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = maxi(weights), high = arrSum(weights);
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        int val = dayCnt(weights, mid);
        if(val <= days){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/