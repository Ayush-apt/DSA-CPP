#include <bits/stdc++.h>
using namespace std;

void printSubsequencesWithSumK(int index, vector<int>& arr, vector<int>& current, int currentSum, int k) {
    // Base Case: Reached the end of the array
    if (index == arr.size()) {
        if (currentSum == k) {
            cout << "[ ";
            for (int num : current) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        return;
    }

    // Choice 1: PICK the current element
    current.push_back(arr[index]);
    printSubsequencesWithSumK(index + 1, arr, current, currentSum + arr[index], k);

    // Backtrack: Remove the element before exploring the next choice
    current.pop_back();

    // Choice 2: NOT PICK the current element
    printSubsequencesWithSumK(index + 1, arr, current, currentSum, k);
}

int main() {
    vector<int> arr = {1, 2, 1};
    int k = 2;
    vector<int> current;

    cout << "Subsequences with sum " << k << ":" << endl;
    printSubsequencesWithSumK(0, arr, current, 0, k);

    return 0;
}
