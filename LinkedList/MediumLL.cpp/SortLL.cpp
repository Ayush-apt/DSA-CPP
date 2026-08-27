#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

/*
 Approach 1: Min Heap

 Intuition:
 - Traverse the linked list and insert every node value into a min heap.
 - The min heap always keeps the smallest value at the top.
 - Traverse the linked list again and replace each node's value with
   the smallest available value from the heap.

 Time Complexity:
 - Building the heap: O(n log n)
 - Updating the linked list: O(n log n)
 - Overall: O(n log n)

 Space Complexity:
 - O(n) for storing all values in the priority queue.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles duplicate values.
 - Handles an already sorted or reverse-sorted list.
*/

ListNode* sortList1(ListNode* head) {
    priority_queue<int, vector<int>, greater<int>> pq;

    ListNode* temp = head;
    while(temp != NULL){
        pq.push(temp->val);
        temp = temp->next;
    }
    temp = head;

    while(temp != NULL){
        temp->val = pq.top();
        pq.pop();
    
        temp = temp->next;
    }

    return head;
}


/*
 Approach 2: Array + Sorting

 Intuition:
 - Traverse the linked list and store all node values in a vector.
 - Sort the vector using the built-in sorting algorithm.
 - Traverse the linked list again and replace each node's value with
   the corresponding sorted value.

 Time Complexity:
 - Traversing the list: O(n)
 - Sorting the values: O(n log n)
 - Updating the list: O(n)
 - Overall: O(n log n)

 Space Complexity:
 - O(n) for storing the node values in the vector.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles duplicate values.
 - Handles an already sorted or reverse-sorted list.
*/

ListNode* sortList2(ListNode* head) {
    vector<int>arr;
    ListNode* temp = head;

    while(temp){
        arr.push_back(temp->val);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());
    temp = head;

    for(int i=0; i<arr.size(); i++){
        temp->val = arr[i];

        temp = temp->next;
    }

    return head;
}


/*
 Approach 3: Merge Sort

 Intuition:
 - Use slow and fast pointers to find the middle of the linked list.
 - Split the list into two halves by breaking the link at the middle.
 - Recursively sort both halves.
 - Merge the two sorted halves using the merge function.
 - Since the nodes themselves are rearranged, no extra array or heap
   is required.

 Time Complexity:
 - Splitting the list at each level: O(n)
 - There are O(log n) levels of recursion.
 - Overall: O(n log n)

 Space Complexity:
 - O(log n) for the recursive call stack.
 - O(1) auxiliary space apart from recursion.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles duplicate values.
 - Handles already sorted and reverse-sorted lists.
*/

ListNode* middle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummy->next;
}

ListNode* sortList3(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    ListNode* mid = middle(head);
    ListNode* righthead = mid->next;
    mid->next = nullptr;
    ListNode* lefthead = head;


    lefthead = sortList3(lefthead);
    righthead = sortList3(righthead);

    return merge(lefthead, righthead);
}

// https://leetcode.com/problems/sort-list/