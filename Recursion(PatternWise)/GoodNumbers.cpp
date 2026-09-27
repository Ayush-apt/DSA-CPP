#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Recursion + Pick / Not Pick

 Intuition:
 - At every index, there are two choices for the current element:
   either include it in the subset or exclude it.
 - First, include nums[ind] in ds and recursively process the next index.
 - After returning, remove the element using backtracking.
 - Then, exclude nums[ind] and recursively process the next index.
 - When ind reaches the end of the array, the current ds represents one
   complete subset, so add it to ans.

 Time Complexity:
 - O(2^n * n), where 2^n subsets are generated and copying each subset
   into ans can take O(n).

 Space Complexity:
 - O(n), for the recursion stack and temporary subset ds.
 - O(2^n * n) additionally for storing all subsets in ans.

 Edge Cases:
 - Empty array gives one subset: {}.
 - Single-element array gives two subsets: {}, {element}.
 - All elements are included in a subset.
 - No elements are included in a subset.
*/

const long long MOD = 1000000007;

long long myPow(long long x, long long n){
    
    if(n == 0) return 1;

    long long half = myPow(x, n/2);

    if(n%2 == 0){
        return half*half % MOD;
    }
    else{
        return x * half * half % MOD;
    }

}

int countGoodNumbers(long long n) {

    long long even = (n+1)/2;
    long long odd = n/2;

    return myPow(5, even) * myPow(4, odd) % MOD;
}

// https://leetcode.com/problems/count-good-numbers/