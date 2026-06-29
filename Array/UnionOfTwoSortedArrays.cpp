#include <bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    int s1 = a.size();
    int s2 = b.size();
    vector<int> uni;
    int i = 0;
    int j = 0;
    while(i<s1 && j<s2){
        if(a[i]<=b[j]){
            if(uni.size()==0 || uni.back()!=a[i]){
                uni.push_back(a[i]);
            }
            i++;
        }
        else{
            if(uni.size()==0 || uni.back()!=b[j]){
                    uni.push_back(b[j]);
                }
            j++;
        }
    }
    while(j<s2){
        if(uni.size()==0 || uni.back()!=b[j]){
            uni.push_back(b[j]);
            }
        j++;
    }
    while(i<s1){
        if(uni.size()==0 || uni.back()!=a[i]){
            uni.push_back(a[i]);
        }
        i++;
    }
    return uni;
}

// https://www.naukri.com/code360/problems/sorted-array_6613259