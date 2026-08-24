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
 Approach 1: Extra Array

 Intuition:
 - Traverse the linked list and first collect the values of nodes at odd
   positions.
 - Then traverse again from the second node and collect the values of
   nodes at even positions.
 - Finally, traverse the original linked list and replace its values
   using the reordered array.
 - This keeps the linked list structure unchanged while rearranging its values.

 Time Complexity:
 - Collecting odd-position values: O(n)
 - Collecting even-position values: O(n)
 - Updating the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing the node values.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-sized lists.
 - Preserves the relative order of nodes within the odd and even groups.
*/

ListNode* oddEvenList1(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;
    vector<int>data;
    ListNode* temp = head;

    while(temp != NULL){
        data.push_back(temp->val);

        if(temp->next == NULL){
            break;
        }

        temp = temp->next->next;
    }

    temp = head->next;
    while(temp != NULL){
        data.push_back(temp->val);

        if(temp->next == NULL){
            break;
        }

        temp = temp->next->next;
    }

    temp = head;
    int i = 0;

    while(temp != NULL){
        temp->val = data[i];
        temp = temp->next;

        i++;
    }

    return head;
}


/*
 Approach 2: In-Place Pointer Manipulation

 Intuition:
 - Maintain two pointers: 'odd' for the odd-position nodes and 'even'
   for the even-position nodes.
 - Keep 'evenHead' to remember the beginning of the even-position list.
 - Reconnect the next pointers so that all odd-position nodes are linked
   together, followed by all even-position nodes.
 - Continue until there are no more pairs of nodes to process.
 - Finally, connect the last odd-position node to the beginning of the
   even-position list.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-sized lists.
 - Preserves the relative order of nodes within both groups.
*/

ListNode* oddEvenList2(ListNode* head) {

    if(head == NULL || head->next == NULL)
        return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;

    while(even != NULL && even->next != NULL){

        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

// https://leetcode.com/problems/odd-even-linked-list/