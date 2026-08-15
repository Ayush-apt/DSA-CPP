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


Node* insertAtHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

// https://www.naukri.com/code360/problems/insert-node-at-the-beginning_8144739?leftPanelTabValue=PROBLEM


Node* insertAtTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    } 
     
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

// https://www.naukri.com/code360/problems/insert-at-end_9886933?leftPanelTabValue=PROBLEM


Node* insertNode(Node* head, int pos, int val){
    
    if(head == NULL){
        if(pos==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(pos == 1){
        return new Node(val, head);
    }
    
    Node* temp = head;
    int cnt = 0;

    while(temp){
        cnt++;

        if(cnt == pos-1){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;

    }
    return head;
}

// https://www.naukri.com/code360/problems/insertion-in-a-singly-linked-list_4609646?leftPanelTabValue=PROBLEM


Node* insertBeforeValue(Node* head, int x, int val){
    Node* temp = head;

    if(head == NULL) return head;

    if(head->data == val){
        return new Node(x, head);
    }

    while(temp){

        if(temp->next->data == val){
            Node* newNode = new Node(x, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;

    }
    return head;
}