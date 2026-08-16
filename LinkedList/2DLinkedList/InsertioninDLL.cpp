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


Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}


Node* insertBeforeTail(Node* head, int val){
    
    if(head->next == NULL){
        return insertBeforeHead(head, val);
    }
    
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;
}


Node* insertAfterTail(Node* head, int val){

    if(head == NULL){
        return new Node(val, nullptr, nullptr);
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newTail = new Node(val, nullptr, temp);
    temp->next = newTail;

    return head;
}

// https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464?leftPanelTabValue=PROBLEM


Node* insertBeforeKthNode(Node* head, int k, int val){

    if(k == 1){
        insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;

    while(temp->next != NULL){
        cnt++;

        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    
    Node* newNode = new Node(val, node, prev);
    
    prev->next = newNode;
    node->back = newNode;
}