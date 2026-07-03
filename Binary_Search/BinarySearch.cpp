#include <bits/stdc++.h>
using namespace std;


// Iterative Code

int search(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

// Recursive Code

int binarysearch(vector<int>& arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high)/2;

    if(arr[mid] == target) return mid;
    else if(target > arr[mid]){
        binarysearch(arr, mid+1, high, target);
    }
    else{
        binarysearch(arr, low, mid-1, target);
    }
}

int search(vector<int>& arr, int target){
    int n = arr.size();
    return binarysearch(arr, 0, n-1, target);
}

