#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/*
 Approach 1: Hash Map with Visit Time

 Intuition:
 - Traverse the linked list while storing the time at which each node
   was first visited.
 - If a node is encountered again, a cycle exists.
 - The length of the cycle is the difference between the current time
   and the time when that node was first visited.
 - If traversal reaches NULL, there is no cycle.

 Time Complexity:
 - Single traversal of the linked list: O(n)
 - Average hash map lookup: O(1)
 - Overall: O(n)

 Space Complexity:
 - O(n) for storing each visited node and its visit time.

 Edge Cases:
 - Handles an empty list.
 - Handles a list without a cycle.
 - Handles a cycle containing a single node.
 - Handles cycles starting at any position in the list.
*/

int lengthOfLoop1(Node *head) {

    unordered_map<Node*, int>mpp;
    Node* temp = head;
    int time = 0;

    while(temp){
        time++;

        if(mpp.find(temp) != mpp.end()){
            return time - mpp[temp];
        }

        mpp[temp] = time;
        temp = temp->next;
    }
    return 0;
}


/*
 Approach 2: Floyd's Cycle Detection Algorithm

 Intuition:
 - Use two pointers: 'slow' moves one node at a time while 'fast' moves
   two nodes at a time.
 - If they meet, a cycle exists.
 - Once the meeting point is found, keep one pointer fixed and move the
   other pointer around the cycle until it reaches the meeting point again.
 - The number of movements gives the length of the cycle.
 - If 'fast' reaches NULL, there is no cycle.

 Time Complexity:
 - Cycle detection: O(n)
 - Counting cycle length: O(n) in the worst case
 - Overall: O(n)

 Space Complexity:
 - O(1) extra space

 Edge Cases:
 - Handles an empty list.
 - Handles a list without a cycle.
 - Handles a cycle containing a single node.
 - Handles cycles of different lengths.
*/

int lengthOfLoop2(Node *head) {

    Node* slow = head;
    Node* fast = head;
    int cnt = 0;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            int cnt = 1;
            slow = slow->next;

            while(slow != fast){
                cnt++;
                slow = slow->next;
            }
            
            return cnt;
        }
    }
    return 0;
}

// https://www.naukri.com/code360/problems/find-length-of-loop_8160455?leftPanelTabValue=PROBLEM