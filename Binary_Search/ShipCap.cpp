#include <bits/stdc++.h>
using namespace std;

int arrSum(vector<int>weights){
    int sum = 0;
    for(int i=0; i<weights.size(); i++){
        sum += weights[i];

    }
    return sum;
}

int maxi(vector<int>weights){
    int maxi = INT_MIN;
    for(int i=0; i<weights.size(); i++){
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}

int dayCnt(vector<int>& weights, int cap) {
    int n = weights.size();
    int days = 1;
    int load = 0;
    for(int i=0; i<n; i++){
        if(load + weights[i] > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = maxi(weights), high = arrSum(weights);
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        int val = dayCnt(weights, mid);
        if(val <= days){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

