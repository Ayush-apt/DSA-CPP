#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> prime(n,true);
    int cnt = 0;
    for(int i=2; i*i<n; i++){
        if(prime[i] == true){
            for(int j=i*i; j<n; j=j+i){
                prime[j]=false;
            }
        }
    }
    for(int k = 2; k<n; k++){
        if(prime[k]==true){
            cnt++;
        }
    }
    return cnt;
}

// https://leetcode.com/problems/count-primes/