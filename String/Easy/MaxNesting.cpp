#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Traversal with Depth Counter

 Intuition:
 - Maintain a counter 'cur' to track the current nesting depth of parentheses.
 - Whenever an opening parenthesis '(' is encountered, increase the depth
   and update the maximum depth found so far.
 - Whenever a closing parenthesis ')' is encountered, decrease the depth.
 - The maximum value reached by 'cur' represents the maximum nesting depth.

 Time Complexity:
 - Single traversal of the string: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles strings with no parentheses.
 - Handles a single pair of parentheses.
 - Handles deeply nested parentheses.
 - Correctly ignores characters other than '(' and ')'.
*/

int maxDepth(string s) {
    int ans = 0;        
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            cur++;
            ans = max(ans,cur);
        }
        else if(s[i] == ')'){
            cur--;
        }
    }
    return ans;
}

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/