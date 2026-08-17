#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};


/*
 Approach: Iterative Pointer Swapping

 Intuition:
 - Traverse the doubly linked list while swapping the 'next' and 'prev'
   pointers of every node.
 - After swapping, move to the original next node using 'curr->prev'.
 - Keep track of the previous pointer in 'last' so that the new head can
   be identified after the traversal.
 - Once all nodes are processed, 'last->prev' points to the new head.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list containing only one node.
 - Correctly updates both 'next' and 'prev' pointers for every node.
*/


Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* last = NULL;
    Node* curr = head;

    while(curr != NULL){
        last = curr->prev;

        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }

    return last->prev;
}

// https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?leftPanelTabValue=PROBLEM