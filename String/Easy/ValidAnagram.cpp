#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Frequency Array

 Intuition:
 - Since the strings contain lowercase English letters, use a frequency
   array of size 26 to keep track of each character.
 - Increment the frequency for every character in s.
 - Decrement the frequency for every character in t.
 - If s and t are anagrams, every character will occur the same number
   of times in both strings, so all frequencies will become 0.
 - If any frequency is non-zero, the strings are not anagrams.

 Time Complexity:
 - Traversing both strings: O(n)
 - Checking the frequency array: O(26), which is O(1)
 - Overall: O(n)

 Space Complexity:
 - O(1), since the frequency array always contains 26 elements.

 Edge Cases:
 - Handles strings of different lengths immediately.
 - Handles empty strings.
 - Handles repeated characters.
 - Correctly handles strings containing all lowercase English letters.
*/

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    int freq[26] = {};

    for(int i=0; i<s.size(); i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int i=0; i<26; i++){
        if(freq[i] !=0) return false;
    }

    return true;
}

// https://leetcode.com/problems/valid-anagram/