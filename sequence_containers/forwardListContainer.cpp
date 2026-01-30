/***********************************************************************************************
* Data Structure : forward_list (Singly Linked List)
* Size           : Dynamic
* Memory         : Heap (Non-contiguous)
* Fast           : Insert/Delete operations
* Resize         : Possible
* Access         : O(N)
* push_front     : O(1)
* push_back      : Not Supported
* insert middle  : O(1) (if iterator is known)
* erase          : O(1) (if iterator is known)
* remove(value)  : O(N)
* search         : O(N)
* Sort           : O(N log N)   (using forward_list::sort)
* Access         : Slow (no random access)
* Insert Middle  : Fast
* Extra Memory   : Less than list (no prev pointer)
* Include        : #include <forward_list>
*************************************************************************************************/

#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main(){

    forward_list<int> zeroLis(5);      // 5 elements initialized to 0
    forward_list<int> valLis(5, 100);  // {100,100,100,100,100}

    // ITERATE
    cout << "ITERATE : " << endl;
    for(int v : valLis){
        cout << v << " ";
    }
    cout << endl;

    for(auto it = valLis.begin(); it != valLis.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    forward_list<int> numLis;

    // INSERT (Only front allowed)
    numLis.push_front(1);
    numLis.emplace_front(2);
    numLis.emplace_front(3);

    cout << "NUMLIST : " << endl;
    for(int v : numLis){
        cout << v << " ";
    }
    cout << endl;

    // INSERT AFTER
    auto it = numLis.begin();
    numLis.insert_after(it, 100);

    cout << "AFTER INSERT_AFTER : " << endl;
    for(int v : numLis){
        cout << v << " ";
    }
    cout << endl;

    // ERASE AFTER
    numLis.erase_after(it);

    cout << "AFTER ERASE_AFTER : " << endl;
    for(int v : numLis){
        cout << v << " ";
    }
    cout << endl;

    // REMOVE VALUE
    forward_list<int> eraseLis;
    for(int i = 1; i <= 10; i++){
        eraseLis.push_front(i);
    }
    eraseLis.push_front(10);
    eraseLis.push_front(10);

    eraseLis.remove(10);

    cout << "REMOVE VALUE 10 : " << endl;
    for(int v : eraseLis){
        cout << v << " ";
    }
    cout << endl;

    // REMOVE IF
    eraseLis.remove_if([](int x){
        return x % 2 == 0;
    });

    cout << "REMOVE EVEN NUMBERS : " << endl;
    for(int v : eraseLis){
        cout << v << " ";
    }
    cout << endl;

    // SORT
    eraseLis.sort();
    cout << "SORTED LIST : " << endl;
    for(int v : eraseLis){
        cout << v << " ";
    }
    cout << endl;

    // UNIQUE (removes consecutive duplicates)
    eraseLis.unique();
    cout << "AFTER UNIQUE : " << endl;
    for(int v : eraseLis){
        cout << v << " ";
    }
    cout << endl;

    // REVERSE
    eraseLis.reverse();
    cout << "REVERSED LIST : " << endl;
    for(int v : eraseLis){
        cout << v << " ";
    }
    cout << endl;

    // SPLICE AFTER
    forward_list<int> lis1 = {1,2,3};
    forward_list<int> lis2 = {4,5};

    lis1.splice_after(lis1.before_begin(), lis2);

    cout << "AFTER SPLICE LIST 1 : " << endl;
    for(int v : lis1){
        cout << v << " ";
    }
    cout << endl;

    cout << "AFTER SPLICE LIST 2 : " << endl;
    for(int v : lis2){
        cout << v << " ";
    }
    cout << endl;

    // RESIZE
    lis1.resize(3);
    cout << "AFTER RESIZE : " << endl;
    for(int v : lis1){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
