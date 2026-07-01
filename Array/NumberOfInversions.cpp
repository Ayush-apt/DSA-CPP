#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Brute Force

 Intuition:
 - Check every possible pair (i, j) such that i < j.
 - If arr[i] > arr[j], then the pair forms an inversion.
 - Count all such inversion pairs.

 Time Complexity:
 - Outer loop: O(n)
 - Inner loop: O(n)
 - Overall: O(n²)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Returns 0 for an already sorted array.
 - Returns n*(n-1)/2 for a reverse sorted array (maximum inversions).
 - Works correctly for arrays with duplicate elements since only arr[i] > arr[j]
   is considered an inversion.
*/

long long getInversions(long long *arr, int n){

    long long cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}


/*
 Approach 2: Optimal (Merge Sort with Inversion Counting)

 Intuition:
 - Use Merge Sort to recursively divide the array into two halves.
 - Count inversions in the left half and right half separately.
 - During the merge step:
   - If the left element is smaller, place it into the temporary array.
   - Otherwise, the right element is smaller than all remaining elements in the
     left half (from left to mid), so each of them forms an inversion.
   - Add (mid - left + 1) to the inversion count.
 - The total inversions are the sum of:
     - Left half inversions
     - Right half inversions
     - Cross inversions counted during merging

 Time Complexity:
 - Merge Sort: O(n log n)
 - Overall: O(n log n)

 Space Complexity:
 - O(n) for the temporary array used during merging.
 - O(log n) recursion stack.

 Edge Cases:
 - Returns 0 for an already sorted array.
 - Correctly counts the maximum number of inversions for a reverse sorted array.
 - Handles duplicate elements correctly since equal elements are not counted as
   inversions.
*/


int merge(vector<int>& arr,int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt = 0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1); //To count using merge sort
            right++;
        }
    }
    while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i<=high ; i++){
        arr[i]= temp[i-low];
    }
    return cnt;
}
int ms(vector<int>& arr, int n, int low, int high){
    int cnt = 0;
    if(low>=high)return cnt;
    int mid = (low+high)/2;
    cnt += ms(arr,n,low,mid);
    cnt += ms(arr,n,mid+1,high);
    cnt += merge(arr,low,mid,high); 
    return cnt;
}

int numberOfInversions(vector<int>&arr, int n) {
    return ms(arr,n,0,n-1);
}

// https://www.naukri.com/code360/problems/number-of-inversions_6840276?leftPanelTabValue=PROBLEM