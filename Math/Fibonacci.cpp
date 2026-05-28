#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n<=1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c = 0;
    for(int i = 2; i<=n; i++){
        int c = a+b;
        a=b;
        b=c;
    }
    return b;
}

// https://leetcode.com/problems/fibonacci-number/description/