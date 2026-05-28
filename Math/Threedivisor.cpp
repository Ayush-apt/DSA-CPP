#include <bits/stdc++.h>
using namespace std;

bool isThree(int n) {
    int num = n;
    int cnt = 0;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            cnt++;
            if((n/i)!=i){
                cnt++;
            }
        }
    }
    if(cnt==3) return true;
    else return false;
}

// https://leetcode.com/problems/three-divisors/