#include <bits/stdc++.h>
using namespace std;

/*
Better Approach - Hashing in map
TC -> O(n*logn)[Avg Case],O(n^2)[Worst Case]
SC -> O(n)
https://leetcode.com/problems/two-sum/description/         
*/

vector<int> twoSum(vector<int>& arr, int t) {
    int n = size(arr);
    unordered_map<int,int>mpp;
    for(int i=0; i<n; i++){
        int m = t-arr[i];
        if(mpp.find(m) != mpp.end()){
            return {i,mpp[m]};
        }
        mpp[arr[i]] = i;
    }
    return {};
}

/*
Optimal Approach - Two Pointer
TC -> O(n) + O(nlogn)
SC -> O(1)
https://www.naukri.com/code360/problems/two-sum_13863418?interviewProblemRedirection=true&search=two%20su&leftPanelTabValue=PROBLEM
*/

string read(int n, vector<int> arr, int t)
{
    int i=0;
    int j=n-1;
    sort(arr.begin(), arr.end());
    while(j>i){
        if(arr[i]+arr[j]>t){
            j--;
        }
        else if(arr[i]+arr[j]<t){
            i++;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}