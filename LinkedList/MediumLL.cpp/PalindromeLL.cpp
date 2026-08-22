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
 Approach 1: Stack

 Intuition:
 - Traverse the linked list and push every node value onto a stack.
 - A stack stores elements in reverse order, which allows us to compare
   the linked list with its reversed sequence.
 - Traverse the linked list again and compare each value with the top
   element of the stack.
 - If any value differs, the linked list is not a palindrome.
 - If all values match, the linked list is a palindrome.

 Time Complexity:
 - First traversal: O(n)
 - Second traversal: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing all node values in the stack.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-length lists.
*/

bool isPalindrome1(ListNode* head) {
    ListNode* temp = head;
    stack<int>st;

    while(temp){     
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        if(temp->val != st.top()){
            return false;
        }
        
        st.pop();
        temp = temp->next;
    }
    return true;
}


/*
 Approach 2: Slow and Fast Pointers + Reversing the Second Half

 Intuition:
 - Use slow and fast pointers to find the middle of the linked list.
 - Reverse the second half of the list.
 - Compare the first half with the reversed second half node by node.
 - If any pair of values differs, the list is not a palindrome.
 - Restore the second half to its original order before returning.

 Time Complexity:
 - Finding the middle: O(n)
 - Reversing the second half: O(n)
 - Comparing both halves: O(n)
 - Restoring the list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space.
 - The recursive reverse function uses O(n) call stack space.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles both even and odd-length lists.
 - Restores the linked list to its original structure after checking.
*/

ListNode* reverseLL(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* newHead = reverseLL(head->next);
    
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;


    return newHead;
}

bool isPalindrome(ListNode* head) {

    if(head == NULL || head->next == NULL) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }   

    ListNode* newHead = reverseLL(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;

    while(second != NULL){
        if(first->val != second->val){
            reverseLL(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);
    return true;
}

// https://leetcode.com/problems/palindrome-linked-list/