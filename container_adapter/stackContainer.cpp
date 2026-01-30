/***********************************************************************************************
* Data Structure : stack
* Order          : LIFO (Last In First Out)
* Implementation : Adapter (deque by default)
* Memory         : Heap
* Access         : Top only
* push           : O(1)
* pop            : O(1)
* top            : O(1)
* search         : ❌ Not supported
* Iterators      : ❌ Not supported
* Include        : #include <stack>
*************************************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> st;

    // PUSH
    st.push(10);
    st.push(20);
    st.push(30);
    st.emplace(40);

    cout << "STACK TOP : " << st.top() << endl;

    // POP
    st.pop();

    cout << "AFTER POP, TOP : " << st.top() << endl;

    // SIZE & EMPTY
    cout << "STACK SIZE : " << st.size() << endl;
    cout << "IS STACK EMPTY : " << st.empty() << endl;

    // PRINT STACK (POP BASED)
    cout << "STACK ELEMENTS : ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
