#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Recursion + Pick / Not Pick

 Intuition:
 - At every index, there are two choices for the current element:
   either exclude it or include it in the current subset.
 - First, make the recursive call without adding nums[ind].
 - Then, add nums[ind] to ds and make the recursive call again.
 - After the recursive call, remove the element using backtracking so that
   ds is restored for the next choice.
 - When ind reaches the end of the array, the current ds represents one
   complete subset, so add it to ans.

 Time Complexity:
 - O(2^n * n), where 2^n subsets are generated and each subset can take
   O(n) time to copy into the answer.

 Space Complexity:
 - O(n), for the recursion stack and the temporary subset ds.
 - O(2^n * n) is additionally required for storing the final answer.

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

    solve(ind + 1, nums, ds, ans);

    ds.push_back(nums[ind]);
    solve(ind + 1, nums, ds, ans);
    ds.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;

    solve(0, nums, ds, ans);

    return ans;
}

// https://leetcode.com/problems/subsets/