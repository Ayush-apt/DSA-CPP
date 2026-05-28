#include <bits/stdc++.h>
using namespace std;

int addDigits(int n) {
    while(n>=10){
        int s = 0;
        while(n>0){
            int m = n%10;
            s = s+m;
            n = n/10;
        }
        n = s;
    }
return n;
}

// https://leetcode.com/problems/add-digits/