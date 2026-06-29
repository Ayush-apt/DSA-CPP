#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- We need to find the maximum profit that can be earned by buying and selling a stock once.
- Keep track of the minimum stock price seen so far while traversing the array.
- For each day, calculate the profit if we sell on that day:
      profit = current_price - minimum_price_so_far
- Update the maximum profit whenever a larger profit is found.
- Also update the minimum price if a lower price is encountered.

Example:
prices = [7,1,5,3,6,4]

minPrice = 7
1 -> minPrice = 1
5 -> profit = 5-1 = 4
3 -> profit = 3-1 = 2
6 -> profit = 6-1 = 5 (maximum)
4 -> profit = 4-1 = 3

Answer = 5

Time Complexity: O(n)
- Single traversal of the array.

Space Complexity: O(1)
- Only two extra variables are used.
*/

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int mins = arr[0];
    int profit = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] - mins > profit) {
            profit = arr[i] - mins;
        }

        if(arr[i] < mins) {
            mins = arr[i];
        }
    }

    return profit;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/