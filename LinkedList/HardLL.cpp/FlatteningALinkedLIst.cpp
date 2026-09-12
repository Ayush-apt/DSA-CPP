#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};


/*
 Approach 1: Store All Values + Sorting

 Intuition:
 - Traverse the linked list and collect the data from every node and its
   child list into a vector.
 - Sort the vector to arrange all values in ascending order.
 - Create a new linked list using the sorted values.
 - Return the newly created flattened list.

 Time Complexity:
 - O(n log n), where n is the total number of nodes.
 - Traversing all nodes takes O(n), and sorting takes O(n log n).

 Space Complexity:
 - O(n), for storing all node values in the vector.
 - O(n), for creating the resulting linked list.

 Edge Cases:
 - Empty linked list.
 - Only one node.
 - Nodes without child nodes.
 - Multiple child nodes.
*/

Node* convertToLL(vector<int> &arr){

    if(arr.size() == 0) return NULL;

	Node* dummyNode = new Node(-1);
	Node* temp = dummyNode;

	for(int i=0; i<arr.size(); i++){
		Node* newNode = new Node(arr[i]);
		temp->next = newNode;

		temp = temp->next;
	}
	return dummyNode->next;
}

Node* flattenLinkedList1(Node* head) {
	vector<int> arr;
	Node* temp = head;

	while(temp){
		arr.push_back(temp->data);
		if(temp->child != NULL){
			Node* childNode = temp->child;
			while(childNode){
				arr.push_back(childNode -> data);
				childNode = childNode->child;
			}
		}
		temp = temp->next;
	}

	sort(arr.begin(), arr.end());
	Node* ans = convertToLL(arr);

	return ans;
}


/*
 Approach 2: Recursion + Merge

 Intuition:
 - Recursively flatten the linked list starting from head->next.
 - This gives a flattened list containing all nodes after the current head.
 - Merge the current list with the already flattened list using the merge
   function.
 - The merge function compares the data values and connects nodes through
   their child pointers in sorted order.
 - This avoids storing all values in an extra vector.

 Time Complexity:
 - O(n^2) in the worst case due to repeatedly merging the lists.
 - Each merge operation takes time proportional to the nodes being merged.

 Space Complexity:
 - O(n) in the worst case due to the recursive call stack.
 - No extra array or hash map is used.

 Edge Cases:
 - Empty linked list.
 - Only one node.
 - No child nodes.
 - Multiple child lists.
 - Child lists are already sorted.
*/

Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
	Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
    }
    if(list1) res->child = list1;
    else res->child = list2;

    if(dummyNode->child) dummyNode->child->next = nullptr;
    return dummyNode->child;
}

Node* flattenLinkedList2(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* mergeHead = flattenLinkedList2(head->next);
    head = merge(head, mergeHead);
    return head;
}

// https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?leftPanelTabValue=PROBLEM