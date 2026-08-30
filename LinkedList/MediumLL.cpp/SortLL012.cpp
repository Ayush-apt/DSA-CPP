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

/*
 Approach 1: Frequency Map

 Intuition:
 - Traverse the linked list and count the frequency of 0, 1, and 2
   using a hash map.
 - Traverse the list again and overwrite each node's data according
   to the stored frequencies.
 - Since the list contains only 0, 1, and 2, the values can be placed
   in sorted order without changing the node links.

 Time Complexity:
 - First traversal: O(n)
 - Second traversal: O(n)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space since only the frequencies of 0, 1, and 2 are stored.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles lists containing only one type of value.
 - Handles duplicate occurrences of 0, 1, and 2.
*/

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


/*
 Approach 2: Three Separate Linked Lists

 Intuition:
 - Create three separate lists for nodes containing 0, 1, and 2.
 - Traverse the original list and attach each node to its corresponding
   list based on its value.
 - Connect the 0-list with the 1-list and the 1-list with the 2-list.
 - The resulting list is sorted without changing the node values.

 Time Complexity:
 - Single traversal to separate the nodes: O(n)
 - Connecting the three lists: O(1)
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space apart from the three dummy nodes.

 Edge Cases:
 - Handles an empty list.
 - Handles a single-node list.
 - Handles lists containing only 0s, only 1s, or only 2s.
 - Handles lists containing all three values.
 - Preserves the relative order of nodes within each value group.
*/

Node* sortList2(Node *head){
    if(head == NULL || head->next == NULL) return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
} 

// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTabValue=PROBLEM