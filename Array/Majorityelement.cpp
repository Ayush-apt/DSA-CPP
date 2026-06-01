#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------
// Approach 1: Hashing (unordered_map)
// Count frequency of every element.
// Traverse the map and find the element whose
// frequency is greater than n/2.
//
// Time Complexity:
// O(n) -> building frequency map
// O(n) -> traversing map (at most n unique elements)
// Total = O(n)
//
// Space Complexity:
// O(n) -> unordered_map stores frequencies
// -----------------------------------------
int majorityElement1(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]] +=1;
    }
    int num = nums[0];
    int mx = 0;
    for(auto it: mpp){
        if(it.second>mx && it.second>(n/2)){  
            num = it.first;
            mx=it.second;
        }
    }
    return num;
}

// -----------------------------------------
// Approach 2: Moore's Voting Algorithm
//
// Idea:
// If an element appears more than n/2 times,
// it can never be completely cancelled out by
// all other elements.
//
// Step 1:
// Find a candidate using voting:
// - If count becomes 0, choose current element
//   as new candidate.
// - Same element -> count++
// - Different element -> count--
//
// Step 2:
// Verify that candidate actually appears
// more than n/2 times.
//
// Time Complexity:
// O(n) -> find candidate
// O(n) -> verification
// Total = O(n)
//
// Space Complexity:
// O(1)
// -----------------------------------------
int majorityElement2(vector<int>& nums){
    int n = nums.size();
    int el=0;
    int cnt=0;
    int el_cnt=0;

    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt = 1;
            el = nums[i];   // <- fix
        }
        else if(el==nums[i]){
            cnt++;
        }
        else cnt--;
    }

    for(int i=0;i<n;i++){
        if(nums[i]==el) el_cnt++;
    }

    return el_cnt;
}

// https://leetcode.com/problems/majority-element/description/