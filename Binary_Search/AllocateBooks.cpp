#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Binary Search on Answer

 Intuition:
 - The minimum possible pages assigned to a student must be at least the
   maximum number of pages in a single book and at most the total pages
   of all books.
 - Use binary search within this range to find the minimum feasible value.
 - For each candidate value, greedily assign consecutive books to the
   current student until the page limit is exceeded, then allocate the
   next student.
 - If all books can be allocated using at most m students, try a smaller
   maximum page limit.
 - Otherwise, increase the page limit.
 - When the search ends, 'low' stores the minimum possible maximum pages
   assigned to any student.

 Time Complexity:
 - Finding the maximum element: O(n)
 - Calculating the total sum: O(n)
 - Binary Search: O(log(sum of pages))
 - Feasibility check for each iteration: O(n)
 - Overall: O(n log(sum of pages))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Returns -1 when the number of students exceeds the number of books.
 - Ensures each student receives consecutive books.
 - Ensures every student gets at least one book.
 - Guarantees the page limit is never smaller than the largest book.
*/

bool allot(vector<int>& arr, int mid, int m){
    int pages = 0;
    int stu = 1;
    for(int i=0; i<arr.size(); i++){
        if(pages + arr[i] <= mid){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }
    if(stu <= m) return true;
    return false;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = low + (high-low)/2;
        bool val = allot(arr, mid, m);

        if(val == true){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

// https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM