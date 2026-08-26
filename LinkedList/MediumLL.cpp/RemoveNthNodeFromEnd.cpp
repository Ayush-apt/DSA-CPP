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
 Approach 1: Length Calculation + Two Traversals

 Intuition:
 - First, calculate the total number of nodes in the linked list.
 - The node to be removed is at position (length - n) from the beginning.
 - If n equals the length of the list, the head itself needs to be removed.
 - Otherwise, traverse to the node just before the target node.
 - Update its next pointer to skip the node that needs to be deleted.
 - Delete the removed node to free its memory.

 Time Complexity:
 - Calculating the length: O(n)
 - Finding and removing the target node: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles removing the head node.
 - Handles removing the last node.
 - Handles a single-node list.
 - Handles removing a node from the middle of the list.
*/

int lengthofLL(ListNode* head){
    int cnt = 0;
    ListNode* temp = head;

    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode* temp = head;

    int cnt = lengthofLL(head);
    int res = cnt-n;

    if(cnt == n){
        ListNode* newHead = head->next;
        delete(head);
        return newHead;
    }

    while(temp != NULL){
        res--;

        if(res == 0) break;
        temp = temp->next;
    }

    ListNode* deleteNode = temp->next;
    temp->next = temp->next->next;

    delete(deleteNode);
    return head;
}


/*
 Approach 2: Two Pointers

 Intuition:
 - Use two pointers, 'fast' and 'slow', initially pointing to the head.
 - Move 'fast' n positions ahead of 'slow'.
 - If 'fast' becomes NULL, the node to remove is the head.
 - Otherwise, move both pointers together until 'fast' reaches the last node.
 - At that point, 'slow' is positioned at the node just before the node
   that needs to be removed.
 - Skip the target node and delete it.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles removing the head node.
 - Handles removing the last node.
 - Handles a single-node list.
 - Handles removing a node from the middle of the list.
*/

ListNode* removeNthFromEnd2(ListNode* head, int n) {

    ListNode* fast = head;
    ListNode* slow = head;

    int cnt = n;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        ListNode* newHead = head->next;
        delete(head);
        return newHead;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);

    return head;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/