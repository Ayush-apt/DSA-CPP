#include<bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
Approach 1: Prefix Sum + Hash Map
------------------------------------------------------------

Works for:
- Positive numbers
- Negative numbers
- Zeroes

Idea:
1. Maintain a running prefix sum.
2. If prefixSum == k, then subarray [0...i] has sum k.
3. If (prefixSum - k) was seen before at index j,
   then subarray [j+1...i] has sum k.
4. Store the first occurrence of every prefix sum
   to maximize the subarray length.

Time Complexity:
O(N * log N) using map
(O(N) average if unordered_map is used)

Space Complexity:
O(N)
*/

int longestSubarrayWithsumK(vector<int> arr, int k) {
    int n = arr.size();
    map<int, int> mpp;

    long long sum = 0;
    int longest = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Subarray from index 0 to i
        if (sum == k) {
            longest = max(longest, i + 1);
        }

        long long rem = sum - k;

        // Check if a prefix sum of 'rem' exists
        if (mpp.find(rem) != mpp.end()) {
            int temp = i - mpp[rem];
            longest = max(longest, temp);
        }

        // Store first occurrence only
        if (mpp.find(sum) == mpp.end()) {
            mpp[sum] = i;
        }
    }

    return longest;
}


/*
------------------------------------------------------------
Approach 2: Sliding Window (Two Pointers)
------------------------------------------------------------

Works only for:
- Positive numbers
- Positive numbers + Zeroes

Does NOT work when negative numbers are present.

Idea:
1. Maintain a window [left, right].
2. Expand the window by moving 'right'.
3. If sum > k, shrink the window from the left.
4. Whenever sum == k, update the maximum length.

Reason it fails for negative numbers:
Removing an element can increase the sum if the
element is negative, which breaks the sliding
window logic.

Time Complexity:
O(N)

Space Complexity:
O(1)
*/

int longestSubarray(vector<int> arr, int k) {
    int left = 0, right = 0;
    int n = arr.size();

    int sum = arr[0];
    int longest = 0;

    while (right < n) {

        // Shrink window while sum exceeds k
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        // Valid subarray found
        if (sum == k) {
            longest = max(longest, (right - left) + 1);
        }

        // Expand window
        right++;
        if (right < n) {
            sum += arr[right];
        }
    }

    return longest;
}

// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505

// http://naukri.com/code360/problems/longest-subarray-with-sum-k_6682399