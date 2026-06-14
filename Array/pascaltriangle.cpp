#include <bits/stdc++.h>
using namespace std;

// nCr

int PascalTriangle_Type1(int row,int col){
    long long value = 1;
    for(int i=0;i<col;i++){
        value = value * (row-i);
        value = value / (i+1);
    }
    return value;
}

vector<int> PascalTriangle_Type2(int rowIndex){
    vector<int> row;
    long long curr = 1;

    row.push_back(1);

    for (int i = 1; i <= rowIndex; i++) {
        curr = curr * (rowIndex - i + 1) / i;
        row.push_back(curr);
    }

    return row;
}

vector<vector<int>> PascalTriangle_Type3(int rows){
    vector<vector<int>>ans;

    for(int i=0;i<rows;i++){
        
        vector<int> temp;
        long long curr = 1;
        temp.push_back(1);
        for(int j=1;j<=i;j++){
            curr = curr * (i - j + 1) / j;
            temp.push_back(curr);
        }
        ans.push_back(temp);
    }
    return ans;
};

int main(){
    int n,row,col;
    cin >> n >> row >> col;
    vector<int>arr(n);

    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // cout << PascalTriangle_Type1(row,col);
    
    // vector<int>ans = PascalTriangle_Type2(row);

    vector<vector<int>>ans = PascalTriangle_Type3(row);

    // for(int i=0;i<ans.size();i++){
    //     cout << ans[i] << " ";
    // }
    cout << endl;
    return 0;
}
