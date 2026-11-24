include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void subWithK(int idx ,vector<int>&arr ,vector<int>ds, int sum, int target){
    
    if(idx == arr.size()){
        if(sum == target){
            cnt++;
        }
        return;
    }

    ds.push_back(arr[idx]);
    subWithK(idx+1, arr, ds, sum + arr[idx], target);

    ds.pop_back();
    subWithK(idx+1, arr, ds, sum, target);

}

int numSubseq(vector<int>&arr ,int target) {
    vector<int>ds;
    subWithK(0, arr, ds, 0, target);

    return cnt;
}
