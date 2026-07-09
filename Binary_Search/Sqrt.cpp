#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search

 Intuition:
 - The integer square root is the largest number whose square is less than
   or equal to x.
 - Perform binary search over the possible answer range [1, x].
 - If mid² is less than or equal to x, store the possibility by moving to
   the right half to search for a larger valid answer.
 - Otherwise, move to the left half to find a smaller value.
 - When the search ends, 'high' points to the largest integer whose square
   does not exceed x.

 Time Complexity:
 - Binary Search: O(log x)
 - Overall: O(log x)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles x = 0 by returning 0 immediately.
 - Uses long long to prevent overflow while computing mid².
 - Correctly returns the floor of the square root for both perfect and
   non-perfect squares.
*/

int mySqrt(int x) {
    long long low = 1, high = x;
    if(x==0) return 0;
    while(low <= high){
        long long mid = low + (high - low)/2;
        if(mid*mid <= x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

// https://leetcode.com/problems/sqrtx/description/