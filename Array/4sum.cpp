#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------------
Approach 1: Better Solution (Hashing + Set)
-------------------------------------------------------------
1. Fix the first two elements using nested loops (i, j).
2. For each pair (i, j), use a hash set to find the fourth
   element required to achieve the target sum.
3. Store every valid quadruplet in a set after sorting it to
   automatically remove duplicates.
4. Convert the set into the final answer vector.

Time Complexity:
- O(N^3 * log M)
  N^3 for choosing (i, j, k)
  log M for insertion/search in the set of quadruplets.

Space Complexity:
- O(M + N)
  M = number of unique quadruplets stored,
  N = hash set used for finding the fourth element.
*/

vector<vector<int>> fourSum1(vector<int>& arr, int target) {
    int n = arr.size();

    set<vector<int>>ansst;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>st;
            for(int k=j+1;k<n;k++){
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long forth = target - sum;
                if(st.find(forth) != st.end()){
                    vector<int>temp = {arr[i],arr[j],arr[k],int(forth)};
                    sort(temp.begin(),temp.end());
                    ansst.insert(temp);
                }
                st.insert(arr[k]);
            }
        }
    }
    vector<vector<int>>ans(ansst.begin(),ansst.end());
    return ans;
}

/*
-------------------------------------------------------------
Approach 2: Optimal Solution (Sorting + Two Pointers)
-------------------------------------------------------------
1. Sort the array.
2. Fix the first two elements using loops (i, j).
3. Use two pointers (k, l) on the remaining subarray.
4. Compare the current 4-element sum with the target:
   - If equal, store the quadruplet.
   - If smaller, move k forward.
   - If larger, move l backward.
5. Skip duplicate values at every level to avoid repeated
   quadruplets.

Time Complexity:
- O(N^3)
  Sorting: O(N log N)
  Nested loops + two pointers: O(N^3)

Space Complexity:
- O(1) (excluding the output array)
  No extra data structures are used.
-------------------------------------------------------------
*/

vector<vector<int>> fourSum2(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;

        for(int j=i+1;j<n;j++){
            if(j != i+1 && arr[j]==arr[j-1])continue;
            int k = j+1;
            int l = n-1;

            while(k<l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if(sum==target){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }
                else if(sum < target)k++;
                else l--;
            }
        }
    }
    return ans;
}

// https://leetcode.com/problems/4sum/