#include <bits/stdc++.h>
using namespace std;

/*
=========================================
Approach 1 : Hashing (Frequency Count)
=========================================

Approach:
Store the frequency of each element using an unordered_map.
Any element whose frequency becomes greater than n/3
is added to the answer.

Time Complexity: O(N)
Space Complexity: O(N)
*/

vector<int> majorityElement1(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int> mpp;
    vector<int>ls;
    int mm = n/3;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mm){
            ls.push_back(arr[i]);
        }
    }
    return ls;
}

/*
=========================================
Approach 2 : Boyer-Moore Voting Algorithm
=========================================

Approach:
Since at most two elements can appear more than n/3 times,
maintain two candidates and their respective counts.

First Pass:
- Find the two potential majority candidates.

Second Pass:
- Count their actual frequencies.
- Add candidates whose frequency is greater than n/3.

Time Complexity: O(N)
Space Complexity: O(1)
*/

vector<int> majorityElement2(vector<int>& arr) {
    int el1 = INT_MIN,el2 = INT_MIN;
    int cnt1 = 0,cnt2 = 0;

    int n = arr.size();

    for(int i=0;i<n;i++){

        if(cnt1==0 && arr[i]!=el2){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1){
            cnt2 = 1;
            el2 = arr[i];
        }

        else if(el1 == arr[i]){
            cnt1++;
        }
        else if(el2 == arr[i]){
            cnt2++;
        }

        else{
            cnt1--,cnt2--;
        }
    }

    vector<int>ans; 
    cnt1 = 0 ,cnt2 = 0;
    int comp = (int)(n/3)+1;

    for(int i=0;i<n;i++){
        if(arr[i]==el1) cnt1++;
        if(arr[i]==el2) cnt2++;
    }
    if(cnt1 >= comp){
        ans.push_back(el1);
    }
    if(cnt2 >= comp){
        ans.push_back(el2);
    }

    return ans;
}

// https://leetcode.com/problems/majority-element-ii/