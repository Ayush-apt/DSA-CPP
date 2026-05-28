#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int n = size(s);
    int val = 0;
    map<char,int> mpp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for(int i =0; i<n; i++){
        for(auto it : mpp){
            if(it.first == s[i]){
                if(i!=n-1 && mpp[it.first] < mpp[s[i+1]]){
                    val = val - mpp[it.first];      
                }
                else val = val + it.second;
            }
        }  
    }
    return val;
}

// https://leetcode.com/problems/roman-to-integer/description/