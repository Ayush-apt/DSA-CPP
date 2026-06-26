#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int j = 0;
    int i = 1;
    while(i<=n-1){
        if(arr[j]==0 && arr[i]!=0){
            int temp = arr[j];
            arr[j]= arr[i];
            arr[i]= temp;
            j++;
        }
        if(arr[j]!=0)j++;
        i++;
    }
}

// Standard Version


void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
    }
}

// https://leetcode.com/problems/move-zeroes/