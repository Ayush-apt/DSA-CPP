#include <bits/stdc++.h>
using namespace std;

int commonFactors(int a, int b) {
    int k = 0;
    int cnt = 0;
    if(a>b) k = k + b;
    else k = k + a;
    for(int i = 1; i<=k ; i++){
        if(a%i==0 && b%i==0){
            cnt++;
        }
    }
    return cnt;
}

// https://leetcode.com/problems/number-of-common-factors/