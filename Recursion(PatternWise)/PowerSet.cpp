#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Recursion + Pick / Not Pick

 Intuition:
 - At every index, there are two choices for the current element:
   either include it in the subset or exclude it.
 - First, include nums[ind] in ds and recursively process the next index.
 - After returning, remove the element using backtracking.
 - Then, exclude nums[ind] and recursively process the next index.
 - When ind reaches the end of the array, the current ds represents one
   complete subset, so add it to ans.

 Time Complexity:
 - O(2^n * n), where 2^n subsets are generated and copying each subset
   into ans can take O(n).

 Space Complexity:
 - O(n), for the recursion stack and temporary subset ds.
 - O(2^n * n) additionally for storing all subsets in ans.

 Edge Cases:
 - Empty array gives one subset: {}.
 - Single-element array gives two subsets: {}, {element}.
 - All elements are included in a subset.
 - No elements are included in a subset.
*/

void solve(int ind, vector<int>& nums, vector<int>& ds,
    vector<vector<int>>& ans) {

    if(ind == nums.size()) {
        ans.push_back(ds);
        return;
    }

    ds.push_back(nums[ind]);
    solve(ind + 1, nums, ds, ans);

    ds.pop_back();
    solve(ind + 1, nums, ds, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;

    solve(0, nums, ds, ans);

    return ans;
}

// https://leetcode.com/problems/subsets/