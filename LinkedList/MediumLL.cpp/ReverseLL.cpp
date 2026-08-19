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
 Approach 1: Iterative Pointer Reversal

 Intuition:
 - Use three pointers: 'prev', 'temp', and 'nxt'.
 - Store the next node before changing the current node's pointer.
 - Reverse the current node's 'next' pointer to point to 'prev'.
 - Move 'prev' and 'temp' forward and repeat until the entire list is reversed.
 - At the end, 'prev' points to the new head of the reversed list.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list containing only one node.
 - Correctly reverses lists of any length.
*/

ListNode* reverseList1(ListNode* head) {
    ListNode* prev = NULL;

    ListNode* temp = head;

    while(temp){
        ListNode* nxt = NULL;

        nxt = temp->next;
        temp->next = prev;

        prev = temp;
        temp = nxt;
    }

    return prev;
}


/*
 Approach 2: Recursive Pointer Reversal

 Intuition:
 - Recursively reverse the linked list starting from head->next.
 - Once the remaining list is reversed, make the next node point back
   to the current node.
 - Set head->next to NULL to prevent creating a cycle.
 - The new head returned from the recursive call remains the head of
   the reversed list.

 Time Complexity:
 - Each node is visited once: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) due to the recursive call stack.

 Edge Cases:
 - Handles an empty list.
 - Handles a list containing only one node.
 - Correctly reverses the links without creating a cycle.
*/

ListNode* reverseList2(ListNode* head) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* newHead = reverseList(head->next);
    
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;


    return newHead;
}

// https://leetcode.com/problems/reverse-linked-list/