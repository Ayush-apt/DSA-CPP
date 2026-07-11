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

int maxEl(vector<int>& arr, int n){
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        mx = max(mx, arr[i]);
    }
    return mx;
}

long long calcTotalHour(vector<int>& arr, int n, int hourly){
    long long totalH = 0;
    for(int i = 0; i < n; i++){
        totalH += (arr[i] + hourly - 1LL) / hourly;
    }
    return totalH;
}

int minEatingSpeed(vector<int>& arr, int h) {
    int n = arr.size();
    int low = 1, high = maxEl(arr, n);

    while(low <= high){
        int mid = low + (high - low) / 2;

        long long totalH = calcTotalHour(arr, n, mid);

        if(totalH <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

// https://leetcode.com/problems/koko-eating-bananas/description/