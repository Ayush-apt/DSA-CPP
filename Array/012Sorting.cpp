#include <bits/stdc++.h>
using namespace std;

//My-Method for this question
void sortColors1(vector<int>& arr) {
    int n=arr.size();
    map<int,int> mpp = {{0,0},{1,0},{2,0}};
    for(int i=0;i<n;i++){
        mpp[arr[i]] += 1;
    }
    arr.clear();
    for(auto it:mpp){
        arr.insert(arr.end(),it.second,it.first);
    }
}

//Dutch National Flag Algo(3 pointer approach)

void sortColors2(vector<int>&arr){
    int n = arr.size();
    int low =0;
    int mid =0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

// https://leetcode.com/problems/sort-colors/description/
