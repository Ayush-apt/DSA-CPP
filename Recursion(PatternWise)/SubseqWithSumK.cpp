#include <bits/stdc++.h>
using namespace std;

// Print Subsequences with Sum K 

void printSubsequences(int idx ,vector<int>&arr ,vector<int>ds, int sum, int target){
    
    if(idx == arr.size()){
        if(sum == target){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[idx]);
    printSubsequences(idx+1, arr, ds, sum + arr[idx], target);

    ds.pop_back();
    printSubsequences(idx+1, arr, ds, sum, target);

}


// Print only one subsequence with sum K 

bool printOneSubsequence(int idx ,vector<int>&arr, vector<int>ds, int sum, int target){
    
    if(idx == arr.size()){
        if(sum == target){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[idx]);
    if(printOneSubsequence(idx+1, arr, ds, sum + arr[idx], target) == true) return true;

    ds.pop_back();
    if(printOneSubsequence(idx+1, arr, ds, sum, target) == true) return true;

    return false;
}


// Count Subsequences with Sum K

int CountSubWithK(int idx, vector<int>&arr, int sum, int target){
    
    if(idx == arr.size()){
        if(sum == target){
            return 1;
        }

        else return 0;
    }

    int l = CountSubWithK(idx+1, arr, sum + arr[idx], target);

    int r = CountSubWithK(idx+1, arr, sum, target);

    return l + r;
}

// https://www.naukri.com/code360/problems/count-of-subsequences-with-given-sum_22685881

void numSubseq(vector<int>&arr ,int target) {
    vector<int>ds;
    printSubsequences(0, arr, ds, 0, target);
}

