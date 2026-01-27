/***********************************************************************************************
 * Data Structure : multiset
 * Properties : duplicate elements allowed, Elements stored in sorted order
 * Point : can't Modify the Elements
 * Operation : Red-Black Tree
 * Size : Dynamic
 * Memory : multiset object - Stack, tree node - Heap
 * Resize : Possible
 * insert : O(log N)
 * erase : O(log N)
 * find : O(log N)
 * Access : O(log N)
 * Count : O(log N + K)
 * Include : #include<set>
*************************************************************************************************/

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    multiset<int> numMultiSet;

    // INSERT
    numMultiSet.insert(1);
    numMultiSet.insert(2);
    numMultiSet.insert(3);
    numMultiSet.insert(4);
    numMultiSet.emplace(5);
    numMultiSet.emplace(5);
    numMultiSet.emplace(5);
    numMultiSet.emplace(1);
    numMultiSet.emplace(2);

    // INTERATE
    cout<<"ITERATE MULTISET : ";
    for(auto fIt = numMultiSet.begin(); fIt != numMultiSet.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;
    for(int el : numMultiSet){
        cout<<el<<" ";
    }
    cout<<endl;

    // SEARCH
    cout<<"FIND GIVE ITERATOR OF FIRST OCCURENCE : "<<*numMultiSet.find(1)<<endl;
    cout<<"COUNT GIVE NO.OF TIMES THE ELEMENT PRESENT : "<<numMultiSet.count(5)<<endl;

    // Find All Occurance
    auto rangeIt = numMultiSet.equal_range(5);
    cout<<"OCCURANCE OF K (ex k =5) : "<<endl;
    for(auto it = rangeIt.first; it != rangeIt.second; it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"LOWER BOUND GIVE FIRST ELEMENT ITERATOR >= k (k=2) : "<<*numMultiSet.lower_bound(2)<<endl;
    cout<<"UPPER BOUND GIVE FIRST ELEMENT ITERATOR > k (k=2) : "<<*numMultiSet.upper_bound(2)<<endl;

    // ERASE
    multiset<int> eraseMultiSet = {1,2,3,4,5,5,5,5,6,1,2,3};
    eraseMultiSet.erase(1); // Erase by Value
    cout<<"SET SIZE BY ERASE : "<<eraseMultiSet.size()<<endl;
    eraseMultiSet.erase(eraseMultiSet.begin()); // Erase by Iterator
    cout<<"SET SIZE BY ERASE : "<<eraseMultiSet.size()<<endl;
    eraseMultiSet.erase(eraseMultiSet.begin(), eraseMultiSet.end()); // Erase by Range
    cout<<"SET SIZE BY ERASE : "<<eraseMultiSet.size()<<endl;

    cout<<"IS EMPTY IN MULTISET : "<<eraseMultiSet.empty()<<endl;

    // Decenting Order multiset
    // multiset<int, greater<int>> ms;

    return 0;
}