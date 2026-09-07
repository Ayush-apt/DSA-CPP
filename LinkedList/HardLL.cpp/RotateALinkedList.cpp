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
 Approach: Find Length + Circular Connection

 Intuition:
 - First find the length of the linked list and keep track of the tail.
 - Since rotating by the length of the list gives the same list, reduce k
   using k % len.
 - Connect the tail to the head to form a circular linked list.
 - Find the new last node at position len - k.
 - The node after it becomes the new head.
 - Break the circular connection by setting newLastNode->next to NULL.

 Time Complexity:
 - O(n), where n is the number of nodes.
 - Finding the length takes O(n), and finding the new last node takes O(n).

 Space Complexity:
 - O(1), since no extra data structure is used.

 Edge Cases:
 - Empty linked list.
 - Single-node list.
 - k = 0.
 - k is a multiple of the list length.
 - k is greater than the list length.
*/

ListNode* findNthNode(ListNode* head, int k){
    int cnt = 1;
    ListNode* temp = head;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return NULL;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL  || k == 0) return head;

    ListNode* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head;

    k = k % len;

    tail->next = head;
    ListNode* newLastNode = findNthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

// https://leetcode.com/problems/rotate-list/