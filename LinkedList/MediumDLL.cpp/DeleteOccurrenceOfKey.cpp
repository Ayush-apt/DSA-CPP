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
Approach 1: Traversal + Direct Deletion

Intuition:

- Traverse the doubly linked list using a temporary pointer.
- If the current node contains k, remove it from the list.
- If the node is the head, update head to the next node.
- Connect the previous node with the next node using prev and next pointers.
- Continue traversal using the saved nextNode after deletion.

Time Complexity:

- O(n), where n is the number of nodes in the linked list.

Space Complexity:

- O(1), since no extra data structure is used.

Edge Cases:

- Empty list.
- Single-node list.
- All nodes contain k.
- k occurs at the head, middle, or tail.
- k does not exist in the list.
*/

Node * deleteAllOccurrences(Node* head, int k) {
    
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == k){

            if(temp == head){
                head = temp->next;
            }

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            if(nextNode != NULL) nextNode->prev = prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;

            delete(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}

// https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM