#include <bits/stdc++.h>
using namespace std;

bool splitCheck(vector<int>& arr, int mid, int k){
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] + sum <= mid){
            sum += arr[i];
        }
        else{
            cnt++;
            sum = arr[i];
        }
    }
    if(cnt <= k) return true;
    else return false;
}


int findLargestMinDistance(vector<int> &arr, int k)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){
        int mid = low + (high-low)/2;
        bool val = splitCheck(arr, mid, k);

        if(val == true){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://leetcode.com/problems/split-array-largest-sum/
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM
