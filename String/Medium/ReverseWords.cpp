#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Extract Words using Extra Space

 Intuition:
 - Traverse the string and extract each word while ignoring extra spaces.
 - Store every word in a vector.
 - Traverse the vector in reverse order and concatenate the words,
   inserting a single space between consecutive words.
 - This produces the reversed sentence without leading, trailing,
   or multiple spaces.

 Time Complexity:
 - Extracting words: O(n)
 - Reconstructing the answer: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing the extracted words.

 Edge Cases:
 - Handles leading and trailing spaces.
 - Handles multiple consecutive spaces.
 - Handles a single word.
 - Returns an empty string for an input containing only spaces.
*/

string reverseWords(string s) {
    bool inWord = false;
    vector<string> ans;
    string wrd = ""; 

    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            if(inWord == true){
                ans.push_back(wrd);
                wrd = "";
                inWord = false;
            }
        }
        else{
            wrd += s[i];
            inWord = true;
        }
    }
    if(inWord == true){
        ans.push_back(wrd);
    }
        
    wrd = "";
    int n = ans.size();
    for(int i = n-1; i>=0; i--){
        wrd += ans[i];

        if(i != 0){
            wrd += ' ';
        }
    }
    return wrd;
}

/*
 Approach 2: Reverse Traversal

 Intuition:
 - Traverse the string from right to left.
 - Count the length of each word while remembering its starting index.
 - Whenever a space is encountered after a word, append that word to
   the answer using substr().
 - Insert a single space between consecutive words.
 - This directly constructs the reversed sentence without storing
   all words separately.

 Time Complexity:
 - Single traversal of the string: O(n)
 - Extracting substrings: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing the resulting string.

 Edge Cases:
 - Handles leading and trailing spaces.
 - Handles multiple consecutive spaces.
 - Handles a single word.
 - Returns an empty string for an input containing only spaces.
*/

string reverseWords(string s) {
    s = " " + s;
    int n = s.size();
    string ans = "";
    int cnt = 0;
    int ind = -1;

    for(int i = n-1; i>=0; i--){
        if(s[i] == ' '){
            if(cnt > 0){
                if(!ans.empty()) ans += " ";
                ans += s.substr(ind,cnt);
                cnt = 0;
            }
        }

        else{
            ind = i;
            cnt++;
        }
    }

    return ans;
}

// https://leetcode.com/problems/reverse-words-in-a-string/