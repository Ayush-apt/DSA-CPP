#include <bits/stdc++.h>
using namespace std;

/*
Better Solution (Running XOR)

TC: O(N²)
SC: O(1)

- Generate all possible subarrays using two loops.
- Fix the starting index and maintain a running XOR while
  extending the subarray.
- If the current subarray XOR equals the target XOR,
  increment the count.
- Avoid recomputing XOR for every subarray from scratch.
*/

int subarraysXor1(vector<int> &arr, int x){
    int n = arr.size();
    int cnt = 0;

    for(int i=0;i<n;i++){
        int xr = 0;

        for(int j=i;j<n;j++){
            
            xr ^= arr[j];
            if(xr == x){
                cnt++;
            }
        }
    }
    return cnt;

}

/*
Optimal Solution (Prefix XOR + HashMap)

Time Complexity: O(N log N)
Space Complexity: O(N)

1. Maintain the Prefix XOR while traversing the array.
2. For each index, compute the required XOR:
      required = prefixXOR ^ targetXOR
3. If the required XOR has appeared before, all its occurrences
   form valid subarrays ending at the current index.
4. Store the frequency of each Prefix XOR in the hashmap.
5. Initialize mpp[0] = 1 to account for subarrays starting from index 0.
*/

int subarraysXor2(vector<int> &arr, int x){

    int xr = 0;
    map<int,int>mpp;
    int n = arr.size();
    
    mpp[xr]++;
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        xr ^= arr[i];
        int k = xr^x;

        cnt += mpp[k];
        mpp[xr]++;
    }
    return cnt;

}

// https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652?interviewProblemRedirection=true&search=count%20sub&leftPanelTabValue=PROBLEM