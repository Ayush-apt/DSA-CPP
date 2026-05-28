#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int k = x;
    long long num = 0;
    while(x>0){
        int ld = x%10;
        num = (num*10)+ld;
        x = x/10;
    }
    return k == num;
}

// https://leetcode.com/problems/palindrome-number/description/