#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search

 Intuition:
 - Search for the nth root in the range [1, m] using binary search.
 - For each mid, calculate mid^n using a helper function.
 - If mid^n equals m, mid is the required nth root.
 - If mid^n exceeds m, search in the left half.
 - Otherwise, search in the right half.
 - The helper function terminates early if the value exceeds m to avoid unnecessary multiplications.

 Time Complexity:
 - O(n * log m)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns 1 when m = 1.
 - Returns -1 if no integer nth root exists.
 - Prevents unnecessary computation by stopping once mid^n > m.
*/

int func(int mid, int n, int m){
  long long ans = 1;
  for(int i=0; i<n; i++){
    ans *= mid;
    if(ans > m) return 1;
  }
  if(ans == m) return 0;
  else 2;
}

int NthRoot(int n, int m) {
  int low = 1, high = m;
  while(low <= high){
    int mid = low + (high - low)/2;
    int midN = func(mid,n,m);
    
    if(midN == 0) return mid;
    else if(midN == 1){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return -1;;
}

// https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM