#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Two Hash Maps

 Intuition:
 - Maintain two hash maps:
     - One maps characters from s to t.
     - The other maps characters from t to s.
 - For each pair of characters:
     - If either character has been mapped previously, ensure the existing
       mapping is consistent.
     - If an inconsistency is found, the strings are not isomorphic.
 - Otherwise, record the new mappings.
 - If the entire traversal completes without conflicts, the strings are
   isomorphic.

 Time Complexity:
 - Single traversal of the strings: O(n)
 - Average hash map operations: O(1)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space, since the character set is bounded (at most 256 ASCII characters).
 - More generally: O(k), where k is the number of distinct characters.

 Edge Cases:
 - Handles empty strings.
 - Handles repeated characters mapping to the same character.
 - Prevents two different characters from mapping to a single character.
 - Correctly handles identical strings.
*/

bool isIsomorphic(string s, string t) {
    unordered_map<char,char>mpp1;
    unordered_map<char,char>mpp2;
    int i = 0,j = 0;

    for(int i=0; i<s.size(); i++){

        if(mpp1.find(s[i]) != mpp1.end() && mpp1[s[i]] != t[i]){
            return false;
        }
        if(mpp2.find(t[i]) != mpp2.end() && mpp2[t[i]] != s[i]){
            return false;
        }
        
        mpp1[s[i]] = t[i];
        mpp2[t[i]] = s[i];
    }
    return true;
}

// https://leetcode.com/problems/isomorphic-strings/