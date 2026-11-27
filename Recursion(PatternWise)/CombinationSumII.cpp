#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    backtrack(candidates, target, 0, path, res);
    return res;
  }

 private:
  void backtrack(const vector<int>& candidates, int remaining, int start,
                 vector<int>& path, vector<vector<int>>& res) {
    if (remaining == 0) {
      res.push_back(path);
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      // Skip duplicate elements at the same recursion level
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      // Prune branches where the current number exceeds the remaining target
      if (candidates[i] > remaining) {
        break;
      }

      path.push_back(candidates[i]);
      backtrack(candidates, remaining - candidates[i], i + 1, path, res);
      path.pop_back();
    }
  }
};
