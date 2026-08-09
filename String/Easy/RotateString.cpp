#include <bits/stdc++.h>
using namespace std;

/*
 Approach: String Concatenation

 Intuition:
 - If goal is a rotation of s, it must have the same length as s.
 - Concatenating s with itself creates a string containing every possible
   rotation of s as a substring.
 - Therefore, check whether goal exists inside (s + s).
 - If it does, s can be rotated to obtain goal.

 Time Complexity:
 - Creating s + s: O(n)
 - Searching for goal: O(n) average/implementation-dependent
 - Overall: O(n) for typical string search.

 Space Complexity:
 - O(n) for the concatenated string.

 Edge Cases:
 - Handles strings of different lengths.
 - Handles identical strings.
 - Handles strings with repeated characters.
 - Handles empty strings.
*/

bool rotateString(string s, string goal) {
    return s.size() == goal.size() &&
        (s + s).find(goal) != string::npos;
}

// https://leetcode.com/problems/rotate-string/