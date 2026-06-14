#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int i=0,j=0;
    vector<int> temp;
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i]>nums2[j]){
            temp.push_back(nums2[j]);
            j++;
        }
        else{
            temp.push_back(nums1[i]);
            temp.push_back(nums2[j]);
            i++,j++;
        }
    }
    while(i<n){
        temp.push_back(nums1[i]);
        i++;
    }
    while(j<m){
        temp.push_back(nums2[j]);
        j++;
    }
    int k = temp.size();
    if(k%2!=0){
        return temp[k/2];
    }
    else{
        double l = (temp[(k/2)-1]+temp[k/2])/2.0;
        return l;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++){
        cin >> nums1[i];  
    }
    for(int i=0;i<m;i++){
        cin >> nums2[i];  
    }
    cout << findMedianSortedArrays(nums1,nums2);
    return 0;
}