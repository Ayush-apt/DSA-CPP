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
 Approach: Recursive Reversal + K-Group Processing

 Intuition:
 - First find the kth node from the current position using findKthNode().
 - If fewer than k nodes remain, leave them unchanged.
 - Disconnect the current group from the remaining list.
 - Reverse the current group using recursive reverseLL().
 - Connect the reversed group with the previous group.
 - Move to the next group and repeat until the entire list is processed.

 Time Complexity:
 - O(n) for reversing the linked list.
 - findKthNode() takes O(k) for every group, resulting in O(n) overall.
 - Overall: O(n).

 Space Complexity:
 - O(k) recursion stack for reversing each group.
 - O(1) auxiliary space apart from the recursive call stack.

 Edge Cases:
 - Empty linked list.
 - k = 1, so the list remains unchanged.
 - k is greater than the length of the list.
 - The last group contains fewer than k nodes.
 - The list length is exactly divisible by k.
*/

ListNode* reverseLL(ListNode* head){

    if(head == NULL || head->next == NULL) return head;

    ListNode* newHead = reverseLL(head->next);
    ListNode* front = head->next;

    front->next = head;
    head->next = NULL;

    return newHead;
}

ListNode* findKthNode(ListNode* temp, int k){
    int cnt = 0;
    ListNode* tempx = temp;

    while(tempx){
        cnt++;
        if(cnt == k){
            return tempx;
        }
        tempx = tempx->next;
    }
    
    return NULL;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp != NULL){
        ListNode* kthNode = findKthNode(temp, k);

        if(kthNode == NULL){
            if(prev) prev->next = temp;
            break;
        }

        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseLL(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prev->next = kthNode;
        }

        prev = temp;
        temp = nextNode;
    }

    return head;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/