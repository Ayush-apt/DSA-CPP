#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int l = arr[0];
    for(int i=0; i<n ; i++){
        if(arr[i]>l){
            l = arr[i];
        }
    }
    return l;
}

int secondlargest(vector<int> arr, int n){
    int l = arr[0];
    int sl = -1;
    for(int i=0; i<n; i++){
        if(arr[i]>l){
            sl = l;
            l = arr[i];
        }
        else if(arr[i]>sl){
            sl = arr[i];
        }
    }
    return sl;
}

int secondsmallest(vector<int> arr, int n){
    int s = arr[0];
    int ss = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<s){
            ss = s;
            s = arr[i];
        }
        else if(arr[i]!=s && arr[i]<ss){
            ss = arr[i];
        }
    }
    return ss;
}

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int slargest = secondlargest(arr, n);
    int ssmallest = secondsmallest(arr, n);
    return {slargest, ssmallest};

}

// https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

// https://www.naukri.com/code360/problems/second-largest-number_13762781