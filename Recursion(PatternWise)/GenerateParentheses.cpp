#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Generate All Possibilities + Validation

 Intuition:
 - Generate all possible strings of length 2*n using recursion.
 - At every position, make two choices: add '(' or add ')'.
 - Use backtracking to remove the previously added character.
 - Once the string reaches length 2*n, check whether it is valid using isValid().
 - If valid, add it to the result vector.

 Time Complexity:
 - O(2^(2n) * n), since all possible strings are generated and each
   string takes O(n) time to validate.

 Space Complexity:
 - O(n), for the recursion stack and the current string.
 - O(n * Cn) additionally for storing the valid combinations,
   where Cn is the nth Catalan number.

 Edge Cases:
 - n = 0, returns an empty string as the only valid combination.
 - Only opening or closing brackets are generated.
 - Invalid combinations are discarded.
*/

vector<string>result;

bool isValid(string &curr){

    int cnt = 0;

    for(char &ch : curr){
        if(ch == '(')
            cnt++;
        else
            cnt--;
        if(cnt < 0)
            return false;
    }

    if(cnt == 0) return true;
    return false;
}

void solve(string &curr, int n){
    if(curr.length() == 2*n){
        if(isValid(curr)){
            result.push_back(curr);
        }
        return;
    }

    curr.push_back('(');
    solve(curr,n);
    curr.pop_back();

    curr.push_back(')');
    solve(curr,n);
    curr.pop_back();
}

vector<string> generateParenthesis1(int n) {
    string curr = "";

    solve(curr,n);

    return result; 
}


/*
 Approach 2: Backtracking with Open and Close Counters

 Intuition:
 - Instead of generating every possible string, maintain the count of
   opening and closing brackets used so far.
 - Add an opening bracket only when open < n.
 - Add a closing bracket only when close < open, ensuring that the
   sequence never becomes invalid.
 - When the string reaches length 2*n, add it directly to the result.
 - This avoids generating invalid combinations altogether.

 Time Complexity:
 - O(n * Cn), where Cn is the nth Catalan number.
 - Only valid combinations are generated, and each takes O(n) time
   to copy into the result.

 Space Complexity:
 - O(n), for the recursion stack and the current string.
 - O(n * Cn) additionally for storing the valid combinations.

 Edge Cases:
 - n = 0, returns an empty string as the only valid combination.
 - Opening brackets cannot exceed n.
 - Closing brackets can never exceed opening brackets.
 - Every generated combination contains exactly n pairs.
*/

vector<string>result2;

void solve(string &curr, int n, int open, int close){

    if(curr.length() == 2*n){
        result.push_back(curr);
        return;
    }

    if(open < n) {
        curr.push_back('(');
        solve(curr, n, open+1, close);
        curr.pop_back();
    }

    if(close < open){
        curr.push_back(')');
        solve(curr, n, open, close+1);
        curr.pop_back();
    }
}

vector<string> generateParenthesis2(int n) {
    string curr = "";

    int open = 0, close = 0;
    solve(curr, n, open, close);

    return result2; 
}

// https://leetcode.com/problems/generate-parentheses/