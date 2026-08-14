#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* removeHead(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}
 
// https://www.naukri.com/code360/problems/delete-head-of-a-given-linked-list_9941216


Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = nullptr;

    return head;
}

// https://www.naukri.com/code360/problems/delete-node-of-linked-list_8160463?leftPanelTabValue=PROBLEM

Node* deleteKthElement(Node* head, int k){
    int pos = 0;
    Node* prev = NULL;
    Node* temp = head;

    if(head == NULL) return head;
    if(k==1){
        head = head->next;
        delete temp;
        return head;
    }

    while(temp){
        pos++;

        if(pos == k){
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteElement(Node* head, int el){
    Node* prev = NULL;
    Node* temp = head;

    if(head == NULL) return head;
    if(head->data == el){
        head = head->next;
        delete temp;
        return head;
    }

    while(temp){

        if(temp->data == el){
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}