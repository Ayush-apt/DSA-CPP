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

            free(temp);
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}

// https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM