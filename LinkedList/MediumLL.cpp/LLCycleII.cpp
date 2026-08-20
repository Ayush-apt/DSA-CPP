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
 Approach 1: Hash Map

 Intuition:
 - Traverse the linked list while storing every visited node in a hash map.
 - Before processing a node, check whether it has already been visited.
 - If a node is found in the map, that node is the starting point of the cycle.
 - If traversal reaches NULL, no cycle exists.

 Time Complexity:
 - Traversing the linked list: O(n)
 - Average hash map lookup: O(1)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing visited nodes.

 Edge Cases:
 - Handles an empty list.
 - Handles a list without a cycle.
 - Handles a cycle starting from the head.
 - Handles a cycle starting at any node in the list.
*/

ListNode *detectCycle1(ListNode *head) {

    unordered_map<ListNode*, bool>mpp;
    ListNode* temp = head;

    while(temp){

        if(mpp[temp] == true){
            return temp;
        }

        mpp[temp] = true;
        temp = temp->next;
    }
    return NULL;
}


/*
 Approach 2: Floyd's Cycle Detection Algorithm

 Intuition:
 - Use two pointers: 'slow' moves one node at a time while 'fast' moves
   two nodes at a time.
 - If they meet, a cycle exists.
 - After the meeting point is found, reset 'slow' to the head.
 - Move both pointers one node at a time.
 - The point where they meet again is the starting node of the cycle.
 - If 'fast' reaches NULL, the linked list does not contain a cycle.

 Time Complexity:
 - Cycle detection: O(n)
 - Finding the cycle's starting point: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list without a cycle.
 - Handles a cycle starting at the head.
 - Handles a cycle containing only one node.
 - Handles cycles starting at different positions in the list.
*/

ListNode *detectCycle2(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return NULL;
}

// https://leetcode.com/problems/linked-list-cycle-ii/