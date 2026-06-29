#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& arr) {
    int xor1 = 0;
    for(int i=0;i<arr.size();i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

// https://leetcode.com/problems/single-number/