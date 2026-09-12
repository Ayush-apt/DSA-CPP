#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
 Approach: Hash Map + Deep Copy

 Intuition:
 - Traverse the original linked list and create a new node for every node.
 - Store the mapping between each original node and its corresponding
   copied node in an unordered_map.
 - Traverse the list again and connect the next and random pointers of
   each copied node using the stored mappings.
 - Return the copied head node.

 Time Complexity:
 - O(n), where n is the number of nodes.
 - The list is traversed twice, and hash map operations take O(1) average time.

 Space Complexity:
 - O(n), for storing the mapping between original and copied nodes.

 Edge Cases:
 - Empty linked list.
 - Single-node list.
 - random pointer is NULL.
 - random pointer points to itself.
 - random pointer points to any other node in the list.
*/

Node* copyRandomList(Node* head) {
    Node* temp = head;
    unordered_map<Node*, Node*>mpp;

    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }

    return mpp[head];
}

/*
 Approach: In-Place Interleaving + Pointer Adjustment

 Intuition:
 - First, create a copy of every node and insert it immediately after
   its original node.
 - This creates an alternating structure:
   original -> copy -> original -> copy ...
 - In the second traversal, set each copied node's random pointer.
   Since the copy is directly after the original, temp->random->next
   gives the corresponding copied random node.
 - Finally, separate the original and copied lists.
 - Restore the original list while constructing the deep-copied list.

 Time Complexity:
 - O(n), where n is the number of nodes.
 - The list is traversed three times.

 Space Complexity:
 - O(1) extra space, excluding the newly created copied nodes.
 - No hash map or other auxiliary data structure is used.

 Edge Cases:
 - Empty linked list.
 - Single-node list.
 - random pointer is NULL.
 - random pointer points to itself.
 - random pointer points to another node.
*/

Node* copyRandomList(Node* head) {

    if(head == NULL) return head;

    Node* temp = head;
    while(temp){
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }

    temp = head;
    while(temp){
        Node* copyNode = temp->next;
        if(temp->random != NULL)copyNode->random = temp->random->next;
        temp = temp->next->next;
    }

    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    temp = head;

    while(temp){
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

// https://leetcode.com/problems/copy-list-with-random-pointer/