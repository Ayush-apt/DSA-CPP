#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Traversal with Parentheses Depth Counter

 Intuition:
 - Traverse the string while maintaining the current nesting depth.
 - For an opening parenthesis '(':
     - If the current depth is greater than 0, it is not an outer parenthesis,
       so include it in the answer.
     - Then increase the depth.
 - For a closing parenthesis ')':
     - First decrease the depth.
     - If the updated depth is greater than 0, it is not an outer parenthesis,
       so include it in the answer.
 - This removes only the outermost parentheses from every primitive substring.

 Time Complexity:
 - Single traversal of the string: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing the resulting string.

 Edge Cases:
 - Handles a single primitive (e.g., "()").
 - Handles multiple primitive substrings.
 - Handles deeply nested parentheses.
 - Preserves the order and structure of the inner parentheses.
*/

string removeOuterParentheses(string s) {
    string ans = "";
    int cnt = 0;
    int n = s.size();
 
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            if(cnt != 0) ans += s[i];
            cnt++;   
        } 
        else{
            cnt--;
            if(cnt != 0) ans += s[i];
        }
    }
    return ans;
}

// https://leetcode.com/problems/remove-outermost-parentheses/