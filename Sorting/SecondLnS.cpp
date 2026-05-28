#include <bits/stdc++.h>
using namespace std;

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
    cout << slargest << " " << ssmallest;
    return {slargest, ssmallest};

}

