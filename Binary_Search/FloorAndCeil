#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Binary Search

 Intuition:
 - Traverse the sorted array using binary search.
 - If the current element equals the target, both floor and ceil are the target.
 - If the current element is greater, update the ceil candidate and search left.
 - Otherwise, update the floor candidate and search right.

 Time Complexity:
 - O(log n)

 Space Complexity:
 - O(1)

 Edge Cases:
 - Returns {-1, -1} if the array is empty.
 - Returns {-1, ceil} if no floor exists.
 - Returns {floor, -1} if no ceil exists.
*/


pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int low = 0, high = n-1;
    int ans_floor = -1, ans_ceil = -1;

    while(low <= high){
        int mid = (low + high)/2;
        if (arr[mid]==x) return {x,x};
        else if (arr[mid] > x){
            ans_ceil = arr[mid];
            high = mid-1;
        }
		
        else{
			ans_floor = arr[mid];
			low = mid+1;
		} 
    }
    return {ans_floor,ans_ceil};
}

// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM