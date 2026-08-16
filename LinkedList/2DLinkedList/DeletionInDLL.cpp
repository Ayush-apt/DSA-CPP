#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
}; 

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){;
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){;
        return NULL;
    }

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

// https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469?leftPanelTabValue=PROBLEM


Node* deleteKthNode(Node* head, int pos){
    if(head == NULL) return head;

    int cnt = 0;
    Node* temp = head;

    while(temp->next != NULL){
        cnt++;

        if(cnt == pos) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }

    else if(prev == NULL){
        deleteHead(head);
        return head;
    }

    else if(front == NULL){
        deleteTail(head);
        return head;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}


void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
    return;
}