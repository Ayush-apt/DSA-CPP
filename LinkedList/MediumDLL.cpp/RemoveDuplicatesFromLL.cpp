#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data, Node* prev, Node* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

/*
 Approach: Traversal + Direct Deletion

 Intuition:
 - Traverse the sorted doubly linked list using a temporary pointer.
 - For each node, check whether the following nodes contain the same value.
 - Delete all consecutive duplicate nodes.
 - Connect the current node with the first different node.
 - Update the prev pointer of the next remaining node.
 - Continue until the entire list is processed.

 Time Complexity:
 - O(n), where n is the number of nodes.
 - Each node is visited and deleted at most once.

 Space Complexity:
 - O(1), since no extra data structure is used.

 Edge Cases:
 - Empty linked list.
 - Single-node list.
 - No duplicates.
 - All nodes contain the same value.
 - Duplicates occur at the beginning, middle, or end.
*/

Node* removeDuplicates(Node *head){

    if(head == NULL) return head;

    Node* temp = head;
    
    while(temp != NULL && temp->next != NULL){

        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* del = nextNode;
            nextNode = nextNode -> next;
            delete(del);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next; 
    }   
    return head;
}

// https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?leftPanelTabValue=PROBLEM