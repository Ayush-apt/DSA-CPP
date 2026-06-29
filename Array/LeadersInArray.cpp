#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int>arr, int n) {
    vector<int>str;
    int maxi = INT_MIN;

    for(int i = n-1;i>=0;i--){
        if(arr[i]>maxi){
            str.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }

    reverse(str.begin(),str.end());
    return str;
}

// https://www.naukri.com/code360/problems/leaders-in-an-array_873144?interviewProblemRedirection=true&search=leader&leftPanelTabValue=PROBLEM