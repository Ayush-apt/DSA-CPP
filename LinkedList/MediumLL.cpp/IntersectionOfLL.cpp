#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

/*
 Approach 1: Hash Map

 Intuition:
 - Traverse the first linked list and store the address of every node
   in a map.
 - Traverse the second linked list and check whether each node already
   exists in the map.
 - The first common node encountered is the intersection point.
 - If no common node is found, the two linked lists do not intersect.

 Time Complexity:
 - Traversing both lists: O(n + m)
 - Average map lookup: O(log n) for std::map
 - Overall: O((n + m) log n)

 Space Complexity:
 - O(n) for storing nodes of the first linked list.

 Edge Cases:
 - Handles an empty list.
 - Handles lists with no intersection.
 - Handles intersection at the head.
 - Handles intersection at the last node.
*/

ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    map<ListNode*, int>mpp;
    ListNode* temp = headA;

    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = headB;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    
    return NULL;
}


/*
 Approach 2: Length Difference + Collision Point

 Intuition:
 - First, calculate the lengths of both linked lists.
 - Find the difference between their lengths.
 - Move the pointer of the longer list ahead by this difference so that
   both pointers have the same number of nodes remaining.
 - Move both pointers one step at a time.
 - The first node where both pointers are equal is the intersection point.

 Time Complexity:
 - Calculating both lengths: O(n + m)
 - Finding the intersection: O(max(n, m))
 - Overall: O(n + m)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles an empty list.
 - Handles lists with no intersection.
 - Handles lists of equal lengths.
 - Handles intersection at the head.
 - Handles intersection at the last node.
*/

ListNode* collisionPoint(ListNode* head1, ListNode* head2, int pt){
    for(int i=0; i<pt; i++){
        head2 = head2->next;
    }

    while(head1 && head2){
        if(head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    int n1 = 0;
    int n2 = 0;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while(temp1){
        n1++;
        temp1 = temp1->next;
    }

    while(temp2){
        n2++;
        temp2 = temp2->next;
    }

    if(n2 > n1){
        return collisionPoint(headA, headB, n2-n1);
    }
    else{
        return collisionPoint(headB, headA, n1-n2);
    }

}


/*
 Approach 3: Two-Pointer Switching

 Intuition:
 - Use two pointers starting at the heads of the two linked lists.
 - Move both pointers one node at a time.
 - When a pointer reaches the end of its list, move it to the head of
   the other list.
 - This makes both pointers travel the same total distance.
 - If an intersection exists, both pointers will eventually meet at
   the intersection node.
 - If there is no intersection, both pointers will eventually become NULL.

 Time Complexity:
 - Each pointer traverses at most both lists: O(n + m)
 - Overall: O(n + m)

 Space Complexity:
 - O(1) extra space.

 Edge Cases:
 - Handles an empty list.
 - Handles lists with no intersection.
 - Handles intersection at the head.
 - Handles lists of different lengths.
 - Handles intersection at the final node.
*/

ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    ListNode* t1 = headA;
    ListNode* t2 = headB;

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = headB;
        if(t2 == NULL) t2 = headA; 
    }

    return t1;
}

// https://leetcode.com/problems/intersection-of-two-linked-lists/