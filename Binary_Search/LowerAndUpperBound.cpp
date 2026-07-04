#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;   
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int lowerBoundcpp(vector<int> arr, int n, int x) {
    int ans = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}

int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;   
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int upperBoundcpp(vector<int> arr, int n, int x) {
    int ans = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
    return ans;
}