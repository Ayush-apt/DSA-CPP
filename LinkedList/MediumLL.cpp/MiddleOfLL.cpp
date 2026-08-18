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
 Approach 1: Two-Pass Traversal

 Intuition:
 - First, traverse the linked list to count the total number of nodes.
 - The middle node is at position (n / 2) + 1 using 1-based indexing.
 - Traverse the list again until reaching that position and return the node.
 - For an even-sized list, this naturally returns the second middle node.

 Time Complexity:
 - First traversal: O(n)
 - Second traversal: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list containing only one node.
 - For an even-sized list, returns the second middle node.
*/

ListNode* middleNode1(ListNode* head) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    int cnt = 0;
    ListNode* temp = head;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    cnt = (cnt/2)+1;
    temp = head;

    while(temp){
        cnt--;

        if(cnt == 0){
            return temp;
        }

        temp = temp->next;
    }

    return head;
}


/*
 Approach 2: Slow and Fast Pointers

 Intuition:
 - Use two pointers: 'slow' moves one node at a time while 'fast' moves
   two nodes at a time.
 - When 'fast' reaches the end of the list, 'slow' will be at the middle.
 - For an even-sized list, the movement naturally makes 'slow' point to
   the second middle node.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list containing only one node.
 - For an even-sized list, returns the second middle node.
*/

ListNode* middleNode2(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// https://leetcode.com/problems/middle-of-the-linked-list/