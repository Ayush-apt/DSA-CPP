#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Exponentiation (Recursive)

 Intuition:
 - Convert n to long long so that the value -INT_MIN can be handled safely.
 - If n is negative, take the reciprocal of x and make n positive.
 - Recursively calculate x^(n/2) and store it in half.
 - If n is even, the answer is half * half.
 - If n is odd, multiply one extra x with half * half.
 - This reduces the exponent by half at every recursive call.

 Time Complexity:
 - O(log n), since the exponent is divided by 2 at every step.

 Space Complexity:
 - O(log n), due to the recursive call stack.

 Edge Cases:
 - n = 0, answer is 1.
 - n = 1, answer is x.
 - Negative exponent.
 - n = INT_MIN.
 - x = 0 or x = 1.
*/

double myPow(double x, int n) {

    long long N = n;
    if(N < 0) {
        x = 1 / x;
        N = -N;
    }

    if(N == 0) return 1;

    double half = myPow(x, N/2);

    if(N % 2 == 0){
        return half * half;
    }
    else{
        return x * half * half;
    }
}

// https://leetcode.com/problems/powx-n/