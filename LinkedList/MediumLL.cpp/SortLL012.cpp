#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList1(Node *head){

    if(head == NULL) return head;

    Node* temp = head;
    unordered_map<int,int>mpp;

    while(temp){
        mpp[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    while(temp){
        if(mpp[0] != 0){
            temp->data = 0;
            mpp[0]--;
        }
        else if(mpp[1] != 0){
            temp->data = 1;
            mpp[1]--;
        }
        else if(mpp[2] != 0){
            temp->data = 2;
            mpp[2]--;
        }
        temp = temp->next;
    }
    return head;
}