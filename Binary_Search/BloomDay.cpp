#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - The minimum eating speed lies between 1 and the maximum pile size.
 - Use binary search to find the smallest speed that allows Koko to finish
   all bananas within h hours.
 - For each candidate speed, calculate the total hours required by summing
   the ceiling of (pile / speed) for every pile.
 - If the total hours are within the limit, try a smaller speed.
 - Otherwise, increase the speed.
 - When the search ends, 'low' represents the minimum feasible eating speed.

 Time Complexity:
 - Finding the maximum pile: O(n)
 - Binary Search: O(log(maxPile))
 - Calculating total hours for each iteration: O(n)
 - Overall: O(n log(maxPile))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles a single pile.
 - Handles cases where h equals the number of piles.
 - Handles very large pile sizes using long long while computing total hours.
 - Uses ceiling division to correctly account for partially eaten piles.
*/

int bouquet(vector<int>& arr, int k, int day){
    int n = arr.size();
    int cnt = 0;
    int bouq = 0;

    for(int i=0; i<n; i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            bouq += cnt/k;
            cnt = 0;
        }
    }
    bouq += (cnt/k);
    return bouq;
}

int minDays(vector<int>& arr, int m, int k) {
    int n = arr.size();
    int mini = INT_MAX, maxi = INT_MIN;

    for(int i=0; i<n; i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }

    int low = mini, high = maxi;
    long long val = 1LL * k * m;

    if(n < val) return -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        int bouq = bouquet(arr, k, mid);
        if(m <= bouq){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/