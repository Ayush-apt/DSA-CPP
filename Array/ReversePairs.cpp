#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Optimal (Merge Sort + Two Pointers)

 Intuition:
 - Use Merge Sort to recursively divide the array into two sorted halves.
 - Before merging the two halves:
   - Count all reverse pairs (i, j) such that:
       i belongs to the left half,
       j belongs to the right half,
       and arr[i] > 2 * arr[j].
   - Since both halves are already sorted, use two pointers:
       - Traverse the left half.
       - Move the right pointer only forward while the condition holds.
       - For each left element, add the number of valid right elements.
 - After counting, merge the two sorted halves as in standard Merge Sort.

 Time Complexity:
 - Counting reverse pairs: O(n) per merge.
 - Merging: O(n) per merge.
 - Merge Sort levels: O(log n)
 - Overall: O(n log n)

 Space Complexity:
 - O(n) for the temporary array used during merging.
 - O(log n) recursion stack.

 Edge Cases:
 - Handles negative numbers by using long long while checking
   arr[i] > 2 * arr[j] to avoid integer overflow.
 - Correctly counts reverse pairs even with duplicate elements.
 - Works for already sorted and reverse sorted arrays.
*/

void merge(vector<int>& arr,int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
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
}

int countpairs(vector<int>& arr,int low, int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i] > (long long)arr[right]*2){
            right++;
        }
        cnt += (right - (mid+1));
    }
    return cnt;
}

int ms(vector<int>& arr, int n, int low, int high){
    int cnt = 0;
    if(low>=high)return cnt;
    int mid = (low+high)/2;

    cnt += ms(arr,n,low,mid); // left
    cnt += ms(arr,n,mid+1,high); //right
    cnt += countpairs(arr,low,mid,high); //counting
    merge(arr,low,mid,high); // merging

    return cnt;
}

int reversePairs(vector<int>& arr) {
    int n = arr.size();
    return ms(arr,n,0,n-1);
}

// https://leetcode.com/problems/reverse-pairs/description/