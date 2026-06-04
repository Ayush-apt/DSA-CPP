#include <bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {
    int sum = 0;
    for(int i=1;i*i<num;i++){
        if(num%i==0){
            sum+=i;
            if(i!=(num/i) && i!=1){
                sum += (num/i);
            }
        }
    }
    if(sum==num){
        return true;
    }
    else return false;
}

// https://leetcode.com/problems/perfect-number/description/