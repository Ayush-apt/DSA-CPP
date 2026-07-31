#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Reverse Traversal

 Intuition:
 - An odd number must end with an odd digit.
 - Traverse the string from right to left to find the last odd digit.
 - Once found, return the substring from the beginning up to that digit.
 - If no odd digit exists, return an empty string.

 Time Complexity:
 - Single traversal of the string: O(n)
 - Creating the substring: O(n) in the worst case
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space (excluding the returned string)

 Edge Cases:
 - Handles a single-digit number.
 - Handles numbers containing only even digits.
 - Handles numbers already ending with an odd digit.
 - Returns the largest possible odd-valued prefix.
*/

string largestOddNumber(string num) {
    int n = num.size();

    for(int i = n-1; i>=0; i--){
        if((num[i] - '0') %2 != 0){
            return num.substr(0,i+1);
        }
    }

    return "";
}

// https://leetcode.com/problems/largest-odd-number-in-string