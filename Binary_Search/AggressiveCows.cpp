#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - Sort the basket positions so that distances can be evaluated in order.
 - The maximum possible minimum distance lies between 1 and the distance
   between the first and last basket.
 - Use binary search to find the largest minimum distance that allows
   placing all m balls.
 - For each candidate distance, greedily place balls in the leftmost
   possible baskets while maintaining at least the required minimum distance.
 - If all m balls can be placed, try a larger minimum distance.
 - Otherwise, reduce the candidate distance.
 - When the search ends, 'high' stores the maximum feasible minimum distance.

 Time Complexity:
 - Sorting: O(n log n)
 - Binary Search: O(log(maxDistance))
 - Feasibility check for each iteration: O(n)
 - Overall: O(n log n + n log(maxDistance))

 Space Complexity:
 - O(1) extra space (excluding the sorting algorithm's internal space)

 Edge Cases:
 - Handles baskets that are already sorted or unsorted.
 - Handles the minimum possible distance (1).
 - Handles placing balls at the extreme basket positions.
 - Greedily verifies whether all m balls can be placed for a given distance.
*/

bool mxPos(vector<int>& arr, int mid, int m){
    int cnt = 1;
    int last = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(mid <= (arr[i] - last)){
            cnt++;
            last = arr[i];
        }
        if(m <= cnt) return true;
    }
    return false;
}

int maxDistance(vector<int>& arr, int m) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n-1] - arr[0];

    while(low <= high){
        int mid = low + (high - low)/2;
        bool val = mxPos(arr, mid, m);
        if(val == true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

// https://leetcode.com/problems/magnetic-force-between-two-balls/