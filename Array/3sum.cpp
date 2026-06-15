#include <bits/stdc++.h>
using namespace std;

/*
=========================================
BRUTE FORCE APPROACH
=========================================

Approach:
Generate all possible triplets using three nested loops.
For every triplet, check if its sum equals 0.
Sort each valid triplet before inserting into a set
to automatically remove duplicate triplets.

Time Complexity: O(n³ * log m)
Space Complexity: O(m)

where m = number of unique triplets stored.
*/

vector<vector<int>> threesum1(vector<int> &arr){
    int n = arr.size();

    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int>temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

/*
=========================================
BETTER APPROACH : HASHING
=========================================

Approach:
Fix one element arr[i].
For every arr[j], calculate the third element required
to make the sum equal to 0:

    third = -(arr[i] + arr[j])

Store previously seen elements in a hash set.
If third already exists in the hash set, a valid
triplet is found.

Sort each triplet before inserting into a set to
avoid duplicate triplets.

Time Complexity: O(n²)
Space Complexity: O(n) + O(m)

where m = number of unique triplets stored.
*/

vector<vector<int>> threesum2(vector<int> &arr){
    int n = arr.size();

    set<vector<int>> ans_st;

    for(int i=0;i<n;i++){
        unordered_set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i]+arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                ans_st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(ans_st.begin(),ans_st.end());
    return ans;
}

/*
=========================================
OPTIMAL APPROACH : SORTING + TWO POINTERS
=========================================

Approach:
Sort the array first.

Fix one element arr[i] and use two pointers:
- j starts from i + 1
- k starts from n - 1

If the current sum is:
- less than 0, move j right to increase the sum.
- greater than 0, move k left to decrease the sum.
- equal to 0, store the triplet and skip duplicate
  values for j and k.

Also skip duplicate values of arr[i] to ensure
only unique triplets are generated.

Time Complexity: O(n²)
Space Complexity: O(1)

(excluding the output array)
*/

vector<vector<int>> threesum3(vector<int> &arr){

    sort(arr.begin(),arr.end());
    int n = arr.size();

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

// https://leetcode.com/problems/3sum/description/