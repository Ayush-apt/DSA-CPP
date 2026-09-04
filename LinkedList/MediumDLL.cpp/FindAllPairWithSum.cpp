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
 Approach 1: Hash Map

 Intuition:
 - Traverse the linked list and store each visited value in a hash map.
 - For every current value, check whether k - val already exists.
 - If it exists, a valid pair is found, so add it to the answer.
 - This allows us to find all pairs in a single traversal.

 Time Complexity:
 - O(n) on average.
 - Hash map insertion and lookup take O(1) average time.

 Space Complexity:
 - O(n), for storing the values in the hash map.

 Edge Cases:
 - Empty linked list.
 - No valid pair exists.
 - Duplicate values are present.
 - Multiple valid pairs exist.
*/

vector<pair<int, int>> findPairs1(Node* head, int k){

    vector<pair<int, int>> ans;
    unordered_map<int, int> mpp;
    Node* temp = head;

    while(temp){
        int val = temp->data;

        if(mpp.find(k-val) != mpp.end()){
            ans.push_back({val, k-val});
        }

        mpp[val] = 1;
        temp = temp->next;
    }
    return ans;
}


/*
 Approach 2: Two-Pointer

 Intuition:
 - Since the doubly linked list is sorted, use two pointers:
   left at the head and right at the tail.
 - If left + right equals k, store the pair and move both pointers.
 - If the sum is greater than k, move right backwards to reduce the sum.
 - If the sum is smaller than k, move left forward to increase the sum.
 - Continue until the two pointers meet or cross.

 Time Complexity:
 - O(n).
 - Finding the tail takes O(n), and the two-pointer traversal takes O(n).

 Space Complexity:
 - O(1) extra space, excluding the space used for the answer.

 Edge Cases:
 - Empty linked list.
 - Single-node list.
 - No valid pair exists.
 - Multiple valid pairs exist.
 - Duplicate values are present.
*/

Node* findTail(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    return temp;
}

vector<pair<int, int>> findPairs2(Node* head, int k){

    vector<pair<int, int>> ans;
    if(head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);

    while(left->data < right->data){
        if(left->data + right->data == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }

        else if(left->data + right->data > k){
            right = right->prev;
        }

        else{
            left = left->next;
        }
    }
    return ans;
}   

// https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172?leftPanelTabValue=PROBLEM