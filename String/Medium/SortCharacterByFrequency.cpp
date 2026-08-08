#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Hash Map + Max Heap

 Intuition:
 - Use a hash map to count the frequency of every character in the string.
 - Store each character and its frequency in a max heap so that the character
   with the highest frequency is always at the top.
 - Repeatedly extract the top element and append that character to the answer
   according to its frequency.
 - Continue until the heap is empty.

 Time Complexity:
 - Counting frequencies: O(n)
 - Building the max heap: O(k log k), where k is the number of distinct characters
 - Constructing the answer: O(n log k) in the heap operations
 - Overall: O(n log k), where k is the number of distinct characters.

 Space Complexity:
 - O(k) for the frequency map and priority queue.
 - O(n) for the resulting string.
 - Overall: O(n)

 Edge Cases:
 - Handles strings containing a single character.
 - Handles characters with equal frequencies.
 - Handles repeated characters correctly.
 - Works for strings containing spaces or other characters as well.
*/

string frequencySort(string s) {
    unordered_map<char,int>mpp;
    priority_queue<pair<int,char>>pq;
    string ans = "";

    for(int i=0; i<s.size(); i++){
        mpp[s[i]]++;
    }

    for(auto it:mpp){
        pq.push({it.second, it.first});
    }

    while(!pq.empty()){
        ans.append(pq.top().first, pq.top().second);
        pq.pop();
    }

    return ans;
}

// https://leetcode.com/problems/sort-characters-by-frequency/