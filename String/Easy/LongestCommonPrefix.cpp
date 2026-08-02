#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Character-by-Character Comparison

 Intuition:
 - The longest common prefix cannot be longer than the shortest string.
 - First, determine the length of the shortest string.
 - Compare characters at the same index across all strings.
 - If every string has the same character at the current index, append it
   to the answer.
 - Stop as soon as a mismatch is found, since no further characters can
   belong to the common prefix.

 Time Complexity:
 - Finding the shortest string length: O(n)
 - Comparing characters: O(n × minLength)
 - Overall: O(n × minLength)

 Space Complexity:
 - O(1) extra space (excluding the returned string)

 Edge Cases:
 - Handles a single string.
 - Handles strings with no common prefix.
 - Handles identical strings.
 - Handles cases where one string is a prefix of all others.
*/

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans = "";
    int min_str = INT_MAX;

    for(int i = 0; i < n; i++){
        min_str = min(min_str, (int)strs[i].size());
    }

    for(int i = 0; i < min_str; i++){

        char c = strs[0][i];
        for(int j=1; j<n; j++){
            if(strs[j][i] != c){
                return ans;
            }
        }
        ans += c;
    }
    return ans;
}

// https://leetcode.com/problems/longest-common-prefix/