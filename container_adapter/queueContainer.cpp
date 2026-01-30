/***********************************************************************************************
* Data Structure : queue
* Order          : FIFO (First In First Out)
* Implementation : Adapter (deque by default)
* Memory         : Heap
* Access         : Front & Back only
* push           : O(1)
* pop            : O(1)
* front          : O(1)
* back           : O(1)
* search         : Not supported
* Iterators      : Not supported
* Include        : #include <queue>
*************************************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<int> q;

    // PUSH
    q.push(10);
    q.push(20);
    q.push(30);
    q.emplace(40);

    cout << "QUEUE FRONT : " << q.front() << endl;
    cout << "QUEUE BACK  : " << q.back() << endl;

    // POP
    q.pop();

    cout << "AFTER POP, FRONT : " << q.front() << endl;

    // SIZE & EMPTY
    cout << "QUEUE SIZE : " << q.size() << endl;
    cout << "IS QUEUE EMPTY : " << q.empty() << endl;

    // PRINT QUEUE (POP BASED)
    cout << "QUEUE ELEMENTS : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
