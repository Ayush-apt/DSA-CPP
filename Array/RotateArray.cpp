#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr, int l, int r){
    while(l<r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++, r--;
    }
}
void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    if(k>=n) k= k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}

// https://leetcode.com/problems/rotate-array/