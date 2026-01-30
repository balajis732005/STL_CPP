/***********************************************************************************************
* Data Structure : priority_queue
* Order          : Heap Based
* Default Heap   : Max Heap
* Implementation : Heap (vector internally)
* Memory         : Heap
* Access         : Top only
* push           : O(log N)
* pop            : O(log N)
* top            : O(1)
* search         : Not supported
* Iterators      : Not supported
* Include        : #include <queue>
*************************************************************************************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    // MAX HEAP (default)
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.emplace(40);

    cout << "MAX HEAP TOP : " << pq.top() << endl;

    pq.pop();
    cout << "AFTER POP, TOP : " << pq.top() << endl;

    // PRINT PRIORITY QUEUE
    cout << "PRIORITY QUEUE (MAX HEAP) : ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(10);
    minpq.push(50);
    minpq.push(20);
    minpq.push(40);

    cout << "PRIORITY QUEUE (MIN HEAP) : ";
    while(!minpq.empty()){
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << endl;

    return 0;
}
