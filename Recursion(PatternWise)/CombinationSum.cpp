#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Recursion + Pick / Not Pick

 Intuition:
 - At every index, make two choices: pick the current candidate or skip it.
 - If picked, add candidates[idx] to ds and recursively call the same
   index because the same element can be used multiple times.
 - Subtract the picked value from target.
 - If skipped, remove the last picked element using backtracking and
   move to the next index.
 - When target becomes 0, store the current combination in ans.
 - If target becomes negative, stop that recursive path.

 Time Complexity:
 - Exponential, as multiple combinations are explored through recursion.
 - The exact complexity depends on the candidates and target values.

 Space Complexity:
 - O(target / min(candidates)) for the recursion depth in the worst case,
   excluding the space used for storing the answer.

 Edge Cases:
 - Target is 0.
 - No combination produces the target.
 - A candidate can be used multiple times.
 - A candidate is greater than the remaining target.
 - Multiple valid combinations exist.
*/

vector<vector<int>> ans;

void fn(int idx, vector<int>& candidates, vector<int>ds, int target){
    if(idx == candidates.size()){
        return;
    }
    if(target <= 0){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }   

    ds.push_back(candidates[idx]);
    fn(idx, candidates, ds, target - candidates[idx]);

    ds.pop_back();
    fn(idx+1, candidates, ds, target);

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>ds;
    fn(0, candidates, ds, target);
    return ans;
}

// https://leetcode.com/problems/combination-sum/