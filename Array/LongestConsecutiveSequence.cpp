#include <bits/stdc++.h>
using namespace std;

// -------------------- length1 --------------------
// Approach:
// 1. Sort the array.
// 2. Traverse the sorted array and count consecutive elements.
// 3. Ignore duplicates.
// 4. If the current element is not consecutive, start a new count.
// 5. Store the maximum length found.
//
// Time Complexity: O(n log n)
// - Sorting takes O(n log n).
// - Single traversal takes O(n).
//
// Space Complexity: O(1)
// - No extra data structure is used (excluding sorting overhead).


int length1(vector<int> &arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int num = INT_MIN;
    int cnt = 0;
    int val = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == num+1){
            cnt++;
            num = arr[i];
        }
        else if(arr[i]!=num){
            cnt = 1;
            num = arr[i];
        }
        val = max(val,cnt);
    }
    return val;
    
}

// -------------------- length2 --------------------
// Approach:
// 1. Insert all elements into an unordered_set for fast lookups.
// 2. Treat an element as the start of a sequence only if its
//    previous element (num - 1) is not present in the set.
// 3. From each starting element, keep checking consecutive numbers
//    and count the sequence length.
// 4. Update the maximum sequence length found.
//
// Time Complexity: O(n) average
// - Insertion into unordered_set takes O(n).
// - Each element is processed at most once while forming sequences.
//
// Space Complexity: O(n)
// - Extra space is used to store elements in the unordered_set.

int length2(vector<int> &arr){
    int n = arr.size();
    if(n==0)return 0;
    int longest = 1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

// https://leetcode.com/problems/longest-consecutive-sequence/description/