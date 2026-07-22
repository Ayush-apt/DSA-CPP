#include <bits/stdc++.h>
using namespace std;

/*
 Approach 1: Greedy Simulation

 Intuition:
 - Keep track of how many additional gas stations are placed in each section.
 - In every iteration, identify the section with the largest current distance.
 - Place one gas station in that section to reduce its maximum segment length.
 - After placing all k gas stations, compute the largest remaining section length.

 Time Complexity:
 - For each of the k gas stations, scan all (n - 1) sections: O(k * n)
 - Final traversal to compute the answer: O(n)
 - Overall: O(k * n)

 Space Complexity:
 - O(n) for storing the number of gas stations added in each section.

 Edge Cases:
 - Handles uneven gaps between gas stations.
 - Greedily reduces the largest section at every step.
 - Works for any value of k.
*/

double minimiseMaxDistance1(vector<int> &arr, int k){
	int n = arr.size();
    vector<int> howMany(n-1,0);
    for(int gasStations = 1; gasStations<=k; gasStations++){
        double maxSection = -1;
        int maxInd = -1;
        for(int i=0; i<n-1; i++){
            double diff = arr[i+1] - arr[i];
            double sectionLength = diff/(long)(howMany[i]+1);
            if(maxSection < sectionLength){
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    double maxAns = -1;
    for(int i=0; i<n-1; i++){
        double diff = arr[i+1] - arr[i];
        double sectionLength = diff/(long)(howMany[i]+1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

/*
 Approach 2: Greedy + Priority Queue

 Intuition:
 - Store every section in a max-heap based on its current maximum segment length.
 - Repeatedly extract the section with the largest distance.
 - Place one additional gas station in that section and update its new segment length.
 - Push the updated section back into the heap.
 - After placing all k gas stations, the heap's top represents the minimized maximum distance.

 Time Complexity:
 - Building the priority queue: O(n log n)
 - Each of the k insertions/removals: O(log n)
 - Overall: O((n + k) log n)

 Space Complexity:
 - O(n) for the priority queue and auxiliary array.

 Edge Cases:
 - Efficiently handles large values of k.
 - Always chooses the section with the current maximum distance.
 - Maintains updated section lengths after every insertion.
*/

double minimiseMaxDistance2(vector<int> &arr, int k){
	int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<double, int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations = 1; gasStations<=k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        double initDiff = arr[secInd + 1] - arr[secInd];
        double newSecLen = initDiff / (double)(howMany[secInd] + 1);
        pq.push({newSecLen,secInd});
    }

    return pq.top().first;
}

/*
 Approach 3: Binary Search on Answer

 Intuition:
 - The answer lies between 0 and the maximum distance between adjacent gas stations.
 - Use binary search to determine the minimum possible maximum distance.
 - For each candidate distance, calculate the minimum number of gas stations
   required so that every adjacent gap is at most the candidate distance.
 - If more than k stations are required, increase the candidate distance.
 - Otherwise, try a smaller distance.
 - Continue until the desired precision is reached.

 Time Complexity:
 - Finding the maximum gap: O(n)
 - Binary Search: O(log(maxGap / 1e-6))
 - Feasibility check in each iteration: O(n)
 - Overall: O(n log(maxGap / 1e-6))

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles varying distances between gas stations.
 - Uses a precision of 1e-6 for the final answer.
 - Correctly handles gaps that are exact multiples of the candidate distance.
*/

int numberOfGasStationsRequired(double dist, vector<int> &arr){
    int cnt = 0;
    for(int i=1;i<arr.size();i++){
        int numberInBetween = ((arr[i] - arr[i-1]) /dist);
        if((arr[i] - arr[i-1]) / dist == numberInBetween * dist){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

double minimiseMaxDistance3(vector<int> &arr, int k){
	int n = arr.size();
    double low = 0;
    double high = 0;
    for(int i=0; i<n-1; i++){
        high = max(high, (double)(arr[i+1] - arr[i]));
    }

    double diff = 1e-6;
    while(high - low > diff){
        double mid = (low+high)/2.0;
        int cnt = numberOfGasStationsRequired(mid,arr);
        if(cnt > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=PROBLEM