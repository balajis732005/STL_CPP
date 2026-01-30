/***********************************************************************************************
* Data Structure : list (Doubly Linked List)
* Size           : Dynamic
* Memory         : Heap (Non-contiguous)
* Fast           : Insert/Delete operations
* Resize         : Possible
* Access         : O(N)
* push_back      : O(1)
* push_front     : O(1)
* insert middle  : O(1)  (if iterator is known)
* erase          : O(1)  (if iterator is known)
* remove(value)  : O(N)
* search         : O(N)
* Sort           : O(N log N)   (using list::sort)
* Access         : Slow (no random access)
* Insert Middle  : Fast
* Include        : #include <list>
*************************************************************************************************/

#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main(){

    list<int> zeroLis(5); // 5 Elements initialized to 0
    list<int> valLis(5, 100); // {10,10,10,10,10}

    // INTERATE
    cout<<"ITERATE : "<<endl;
    for(int v: valLis){
        cout<<v<<" ";
    }
    cout<<endl;
    for(auto it = valLis.begin(); it != valLis.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
     
    list<int> numLis;
    numLis.push_front(1);
    numLis.push_back(2);
    numLis.emplace_front(3);
    numLis.emplace_back(4);

    cout<<"NUMLIST : "<<endl;
    for(int v: numLis){
        cout<<v<<" ";
    }
    cout<<endl;

    // INSERT
    auto it = numLis.begin();
    advance(it, 2); // Move Iterator
    numLis.insert(it, 100);

    cout<<"NUMLIST INSERT : "<<endl;
    for(auto fIt = numLis.begin(); fIt != numLis.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;

    // ERASE
    list<int> eraseLis;
    for(int i=1;i<=20;i++){
        eraseLis.emplace_back(i);
    }
    eraseLis.emplace_back(20);
    eraseLis.emplace_back(20);
    eraseLis.emplace_back(20);
    eraseLis.emplace_back(20);

    eraseLis.remove(20); // Erase All the occurence of 20
    eraseLis.remove_if([](int x){
        return x % 2 == 0;
    });

    cout<<"ERASED NUMLIST : "<<endl;
    for(int v: eraseLis){
        cout<<v<<" ";
    }
    cout<<endl;

    // CLEAR
    // numLis.clear()

    cout<<"FRONT FROM LIST : "<<numLis.front()<<endl;
    cout<<"LAST FROM LIST  : "<<numLis.back()<<endl;

    /*
    We can't access list as:
    - <list_name>[i]
    - <list_name>.at(i)
    */

    cout<<"LIST SIZE : "<<numLis.size()<<endl;
    cout<<"IS LIST EMPTY : "<<numLis.empty()<<endl;

    numLis.reverse();

    cout<<"REVERSE LIST : "<<endl;
    for(int x: numLis){
        cout<<x<<" ";
    }
    cout<<endl;

    numLis.sort();
    cout<<"SORT LIST : "<<endl;
    for(int v: numLis){
        cout<<v<<" ";
    }
    cout<<endl;

    // REMOVE CONSECUTIVE DUMPLICATES - So Sort Before Remove
    numLis.emplace_front(1);
    numLis.emplace_front(1);
    numLis.emplace_front(1);
    numLis.emplace_front(1);

    cout<<"BEFORE DUMPLICATES REMOVE : "<<endl;
    for(int v: numLis){
        cout<<v<<" ";
    }
    cout<<endl;

    numLis.unique();

    cout<<"AFTER DUMPLICATES REMOVE : "<<endl;
    for(int v: numLis){
        cout<<v<<" ";
    }
    cout<<endl;

    list<int> lis1 = {1,2,3};
    list<int> lis2 = {4,5};

    // Merge two sorted list
    lis1.merge(lis2);

    cout<<"AFTER MERGE LIST 1 : "<<endl;
    for(int x: lis1){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"AFTER MERGE LIST 2 : "<<endl;
    for(int x: lis2){
        cout<<x<<" ";
    }
    cout<<endl;

    // Move Elements from one list to another list without copying - O(1) Time Compelxity
    list<int> lis3 = {1,2,3,4,5};
    list<int> lis4 = {6,7};

    // Merge two sorted list
    lis3.splice(lis3.end(), lis4);

    cout<<"AFTER SPLICE LIST 3 : "<<endl;
    for(int x: lis3){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"AFTER SPLICE LIST 4 : "<<endl;
    for(int x: lis4){
        cout<<x<<" ";
    }
    cout<<endl;

    //  RESIZE
    numLis.resize(5); // Adds Zero
    for(int v: numLis){
        cout<<v<<" ";
    }
    cout<<endl;

    return 0;
}