#include <bits/stdc++.h>
using namespace std;

/*
 Approach: Recursion + Insert at Bottom

 Intuition:
 - First, reverseStack() removes the top element and recursively processes
   the remaining stack.
 - Once the stack becomes empty, start restoring the removed elements.
 - insertAtBottom() recursively removes all existing elements until the
   stack becomes empty.
 - Insert the given element x at the bottom and push back all the
   previously removed elements.
 - This places every element at its reversed position.

 Time Complexity:
 - O(n^2), where n is the number of elements.
 - Each insertAtBottom() operation takes O(n) in the worst case,
   and it is called for every element.

 Space Complexity:
 - O(n), due to the recursive call stack.

 Edge Cases:
 - Empty stack.
 - Stack containing only one element.
 - Stack containing duplicate elements.
 - Stack containing multiple elements.
*/

void insertAtBottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(temp);
}

void reverseStack(stack<int> &st) {

    if(st.empty()) return;
    
    int temp = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st,temp);
}

// https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875