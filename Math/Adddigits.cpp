#include <bits/stdc++.h>
using namespace std;

int addDigits(int num) {
    if(num%9==0){
        return 9;
    }
    int sum = num%9;
    return num;  
}

// https://leetcode.com/problems/add-digits/