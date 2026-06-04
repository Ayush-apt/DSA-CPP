#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n*(n+1))/2;
    int comp = 0;
    for(int i=0;i<n;i++){
        comp += nums[i];
    }
    return sum-comp;
}