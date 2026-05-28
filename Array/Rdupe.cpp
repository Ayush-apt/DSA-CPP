#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
//     int k = 1;
//     vector<int> temp;
//     temp.push_back(arr[0]);
//     int n = arr.size();
//     for(int i=0; i<n-1; i++){
//         if(arr[i] != arr[i+1]){
//             temp.push_back(arr[i+1]);
//             k++;
//         }
//     }
//     int m = temp.size();
//     arr.clear();
//     arr.insert(arr.begin(),m,0);
//     for(int j=0; j<m; j++){
//         arr[j] = temp[j];
//     }
//     return k;
// }

int i = 0;
int n = arr.size();
for(int j=0; j<n; j++){
    if(arr[j] != arr[i]){
        arr[i+1] = arr[j];
        i++;
    }
}
return i+1;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/