#include <bits/stdc++.h>
using namespace std;

int findGCD(vector<int>& v) {
        int k = 0;
        int mn = *min_element(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        if(mx==mn){
            k = mn;
        }
        else{
            for(int i = 1; i<= mn; i++){
            if(mn%i==0 && mx%i==0){
                k = i;
            }
        }
        }
        return k;
}

// https://leetcode.com/problems/find-greatest-common-divisor-of-array/