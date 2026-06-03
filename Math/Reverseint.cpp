#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int rev = 0;

    // Process each digit until the number becomes 0
    while (x != 0) {

        // Overflow check:
        // If rev is already beyond INT_MAX/10 or INT_MIN/10,
        // multiplying it by 10 in the next step will definitely
        // exceed the 32-bit integer range.
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;
        }

        // Extract the last digit
        int ld = x % 10;

        // Append the digit to the reversed number
        rev = (rev * 10) + ld;

        // Remove the last digit from x
        x /= 10;
    }

    return rev;
}

// Time Complexity O(n)
// Spcae Complexity O(1)
// https://leetcode.com/problems/reverse-integer/