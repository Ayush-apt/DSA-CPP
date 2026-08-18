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
 Approach: Digit-by-Digit Addition using a Dummy Node

 Intuition:
 - Traverse both linked lists simultaneously, starting from the least
   significant digits.
 - Add the current digits from both lists along with the carry from the
   previous addition.
 - Create a new node containing sum % 10 and update the carry using sum / 10.
 - Continue until both lists are completely traversed.
 - If a carry remains after processing both lists, add it as the final node.
 - Use a dummy node to simplify construction of the resulting linked list.

 Time Complexity:
 - Each node from both lists is visited once: O(max(n, m))
 - Overall: O(max(n, m))

 Space Complexity:
 - O(max(n, m)) for the resulting linked list.
 - O(1) extra space excluding the output list.

 Edge Cases:
 - Handles linked lists of different lengths.
 - Handles carry propagation across multiple digits.
 - Handles a final carry after both lists are exhausted.
 - Handles lists containing a single digit.
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    ListNode* dummy = new ListNode(-1);

    ListNode* curr = dummy;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL){

        int sum = carry;

        if(temp1) sum += temp1->val;
        if(temp2) sum += temp2->val;

        ListNode* newNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }

    return dummy->next;
}

// https://leetcode.com/problems/add-two-numbers/