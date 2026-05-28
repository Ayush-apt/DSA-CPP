#include <bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int n) {
    int num = n;
    int cnt = 0;
    for(int i = 1; i*i<n; i++){
        if(n%i==0){
            cnt = cnt+i;
            if(i!=1){
                if((n/i)!=i){
                    cnt = cnt+(n/i);
                }
            }
        }
    }
    if(num==cnt) return true;
    else return false;
}

// https://leetcode.com/problems/perfect-number/description/