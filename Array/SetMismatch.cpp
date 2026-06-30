#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: My Method (Sorting)

 Intuition:
 - Sort the array so duplicate elements become adjacent.
 - Traverse the sorted array:
   - If two consecutive elements are equal, that is the repeating number.
   - Maintain a variable `missing` starting from 1 and increment it whenever
     the expected number is found.
 - After traversal, `missing` stores the missing element.

 Time Complexity:
 - Sorting: O(n log n)
 - Single traversal: O(n)
 - Overall: O(n log n)

 Space Complexity:
 - O(1) extra space (ignoring the sorting stack).

 Edge Cases:
 - Handles duplicate at the beginning, middle, or end.
 - Correctly identifies the missing number even when it is n.
 - Assumes exactly one missing and one repeating element.
*/

vector<int> findTwoElement(vector<int>& arr){
    int n = arr.size();

    int missing = 1;
    int repeating = -1;

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        if(i<n-1){
            if(arr[i]==arr[i+1]){
                repeating = arr[i];
            }
        }
        if(arr[i]==missing){
            missing++;
        }

    }
    return {repeating,missing};
}


/*
 Approach 2: Brute Force (Frequency Counting)

 Intuition:
 - For every element, count its occurrences by traversing the entire array.
 - If an element appears twice, it is the repeating number.
 - If an element never appears, it is the missing number.

 Time Complexity:
 - Outer loop: O(n)
 - Inner loop: O(n)
 - Overall: O(n²)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Works for all valid inputs with one missing and one repeating element.
 - Does not require sorting or additional data structures.
*/

vector<int> findErrorNums1(vector<int>& arr){
    int n = arr.size();

    int missing = -1,repeating = -1;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]) cnt++;
        }
        if(cnt == 2) repeating = arr[i];
        else if(cnt == 0) missing = arr[i];
    }
    return {repeating,missing};
}


/*
 Approach 3: Better (Hashing)

 Intuition:
 - Create a frequency array of size n+1.
 - Count the occurrence of every number.
 - Traverse the frequency array:
   - Frequency 2 → Repeating number.
   - Frequency 0 → Missing number.

 Time Complexity:
 - Building frequency array: O(n)
 - Traversing frequency array: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for the frequency array.

 Edge Cases:
 - Handles missing or repeating element anywhere in the range.
 - Early break once both numbers are found.
 - Assumes values lie in the range [1, n].
*/

vector<int> findErrorNums2(vector<int>& arr){
    int n = arr.size();
    int hash[n+1] = {0};

    int missing  = -1,repeating = -1;

    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }

    for(int i=1;i<=n;i++){
        if(hash[i] == 0) missing = i;
        else if(hash[i] == 2) repeating = i;

        if(missing != -1 && repeating != -1){
            break;
        }
    }

    return {repeating,missing};
}


/*
 Approach 4: Optimal (Mathematics)

 Intuition:
 - Compute the expected sum (SN) and sum of squares (S2N) for numbers 1 to n.
 - Compute the actual sum (S) and sum of squares (S2) from the array.
 - Derive:
     x - y = S - SN
     x² - y² = S2 - S2N
 - Use the identity:
     x² - y² = (x - y)(x + y)
   to obtain x + y.
 - Solve the two equations to find:
     x = Repeating number
     y = Missing number

 Time Complexity:
 - Single traversal: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Uses long long to prevent integer overflow while computing sums.
 - Assumes exactly one missing and one repeating element.
 - Works without modifying the original array.
*/

vector<int> findErrorNums3(vector<int>& arr){
    long long n = arr.size();

    //S - SN = x-y
    long long SN = (n * (n+1)) / 2;
    //S2 - S2N = (x-y)^2
    long long S2N = (n * (n+1) * (2*n+1)) / 6;
    
    long long S = 0,S2 = 0;

    for(int i=0;i<n;i++){
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    int val1 = S - SN; // x-y
    int val2 = S2 - S2N;
    val2 = val2 / val1; // x+y 

    long long x = (val1 + val2)/2;
    long long y = x - val1;

    return{(int)x , (int)y};
}

// Will Approach XOR after learning concept of bit

// https://leetcode.com/problems/set-mismatch/description/