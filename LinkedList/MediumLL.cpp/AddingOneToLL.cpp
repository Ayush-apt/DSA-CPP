#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node* reverseList(Node* head) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverseList(head->next);
    
    Node* front = head->next;
    front->next = head;
    head->next = NULL;


    return newHead;
}

Node *addOne(Node *head)
{
    head = reverseList(head);
    Node* temp = head;
    int carry = 1;

    while(temp != NULL){
        temp->data = temp->data + 1;
        if(temp->data < 10){
            carry = 0;
            break;
        }

        else{
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        head = reverseList(head);
        newNode->next = head;
        return newNode;
    }

    head = reverseList(head);
    return head;
}


int helper(Node* temp){
    if(temp == NULL) return 1;

    int carry;
    carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry;
    carry = helper(head);

    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}

// https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557?leftPanelTabValue=PROBLEM