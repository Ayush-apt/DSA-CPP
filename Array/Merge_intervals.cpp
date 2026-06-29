#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Brute Force + Sorting

 Intuition:
 - Sort the intervals by starting time.
 - For every interval, try to merge it with all subsequent overlapping intervals.
 - Skip intervals that are already covered by the previously merged interval.

 Time Complexity:
 - Sorting: O(n log n)
 - Nested traversal: O(n^2) in the worst case
 - Overall: O(n^2)

 Space Complexity:
 - O(1) extra space (excluding the output vector)
 - O(n) for storing the merged intervals in the answer.

 Edge Cases:
 - Handles completely overlapping intervals.
 - Handles partially overlapping intervals.
 - Handles non-overlapping intervals.
 - No explicit empty-array check required since the loop won't execute.
*/

vector<vector<int>> merge1(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i = 0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i+1;j<n;j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }

    return ans;
}

/*
  Approach 2: Optimal Greedy + Sorting
 
  Intuition:
  - Sort the intervals by starting time.
  - Maintain the current merged interval using (fstart, fend).
  - If the next interval overlaps, extend the current interval.
  - Otherwise, store the current interval and begin a new one.
  - Push the final merged interval after the traversal.
 
  Time Complexity:
  - Sorting: O(n log n)
  - Single traversal: O(n)
  - Overall: O(n log n)
 
  Space Complexity:
  - O(1) extra space (excluding the output vector)
  - O(n) for storing the merged intervals in the answer.
 
  Edge Cases:
  - Empty input vector (handled explicitly).
  - Single interval.
  - Completely overlapping intervals.
  - Partially overlapping intervals.
  - Non-overlapping intervals.
  - Adjacent intervals (e.g., [1,4] and [4,5]) merge correctly.
*/

vector<vector<int>> merge2(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    if(n==0){
        return {};
    }

    int fstart = arr[0][0], fend = arr[0][1];
    for(int i = 0;i<n;i++){
        
        int start = arr[i][0];
        int end = arr[i][1];

        if(start <= fend){
            fend = max(fend,end);
        }
        else{
            ans.push_back({fstart,fend});
            fstart = start;
            fend = end;
        }
    }
    ans.push_back({fstart,fend});
    return ans;
}

/*
  Approach 2: Optimal Greedy + Sorting

  Intuition:
  - Sort the intervals by their starting time.
  - Traverse the sorted intervals one by one.
  - If the answer is empty or the current interval does not overlap
    with the last merged interval, add it directly to the answer.
  - Otherwise, merge the intervals by extending the end of the last
    interval stored in the answer.
  - The answer vector itself maintains the merged intervals, eliminating
    the need for separate start/end variables.
*/

vector<vector<int>> merge2(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}



// https://leetcode.com/problems/merge-intervals/