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
 - Traverse the linked list while keeping track of every visited node
   using a hash map.
 - Before processing a node, check whether it has already been visited.
 - If the node is already present in the map, a cycle exists.
 - If traversal reaches NULL, the linked list does not contain a cycle.

 Time Complexity:
 - Traversing the linked list: O(n)
 - Average hash map lookup: O(1)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing the visited nodes.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles a cycle pointing back to the head.
 - Handles a cycle occurring between any two nodes.
*/

bool hasCycle1(ListNode *head) {
    unordered_map<ListNode*, bool>mpp;

    ListNode* temp = head;
    while(temp != NULL){

        if(mpp.find(temp) != mpp.end()){
            return true;
        }

        mpp[temp] = true;
        temp = temp->next;
    }

    return false;
}


/*
 Approach 2: Floyd's Cycle Detection Algorithm

 Intuition:
 - Use two pointers: 'slow' moves one node at a time while 'fast' moves
   two nodes at a time.
 - If there is no cycle, 'fast' will eventually reach NULL.
 - If a cycle exists, 'fast' will eventually meet 'slow' inside the cycle.
 - Therefore, if slow == fast at any point, the linked list contains a cycle.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles a cycle pointing back to the head.
 - Handles cycles occurring at different positions in the list.
*/

bool hasCycle2(ListNode *head) {
    
    ListNode* slow = head;
    ListNode* fast = head;

    if(head == NULL || head->next == NULL){
        return false;
    }

    while(fast != NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
}  

// https://leetcode.com/problems/linked-list-cycle/