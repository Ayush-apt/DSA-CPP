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
 Approach 1: Length Calculation + Traversal

 Intuition:
 - First, calculate the total number of nodes in the linked list.
 - The middle node is at index length / 2 using 0-based indexing.
 - Traverse the list until reaching the node just before the middle node.
 - Remove the middle node by updating the previous node's next pointer.
 - Delete the removed node to free its memory.

 Time Complexity:
 - Calculating the length: O(n)
 - Traversing to the middle: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-sized lists.
 - For an even-sized list, removes the second middle node.
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

ListNode* deleteMiddle1(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    int len = lengthofLL(head);
    int res = (len)/2;
    ListNode* temp = head;
    
    while(temp != NULL){
        res--;

        if(res == 0) break;
        temp = temp->next;
    }
    ListNode* middle = temp->next;
    temp->next = temp->next->next;
    delete(middle);

    return head;
}


/*
 Approach 2: Slow and Fast Pointers

 Intuition:
 - Use 'slow' and 'fast' pointers to find the node just before the middle.
 - Start 'fast' two nodes ahead so that when it reaches the end,
   'slow' points to the node before the middle node.
 - Move 'slow' one step and 'fast' two steps at a time.
 - Remove the node after 'slow' and delete it.
 - This avoids calculating the length of the linked list separately.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-sized lists.
 - For an even-sized list, removes the second middle node.
*/

ListNode* deleteMiddle2(ListNode* head) {

    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* middleNode = slow->next;
    slow->next = slow->next->next;
    delete(middleNode);

    return head;
}

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/