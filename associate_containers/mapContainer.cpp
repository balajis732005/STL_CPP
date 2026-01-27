/***********************************************************************************************
 * Data Structure : map
 * Properties : keys are unique, Stored in Sorted Order
 * Operation : Red-Black Tree
 * Size : Dynamic
 * Memory : map object - Stack, tree nodes(key-value) - Heap
 * Resize : Possible
 * Access : O(log N)
 * insert : O(log N) 
 * delete : O(log N)
 * find : O(log N)
 * Include : #include<map>
*************************************************************************************************/

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    map<int, int> numMap;

    // INSERTION
    numMap[1] = 10; // Create Automatically if key not found
    numMap.insert({2,20});
    numMap.insert(make_pair(3,30));
    numMap.emplace(4, 40); // Faster then insert

    // ACCESS
    cout<<"ACCESS KEY 1 : "<<numMap[1]<<endl; // UnSafe - Creates Key if not found
    // Safe Access
    cout<<"ACCESS KEY 2 : ";
    auto it = numMap.find(2);
    if(it != numMap.end()){
        cout<<it->first<<" - "<<it->second<<endl;
    }
    cout<<"ACCESS KEY 3 : "<<numMap.at(3)<<endl; 
    // Throws Exception if key not found

    // ITERATE
    cout<<"NUMBER MAP ITERATION : "<<endl;
    for(auto &p : numMap){
        cout<<p.first<<" - "<<p.second<<endl;
    }

    for(auto fIt = numMap.begin(); fIt != numMap.end(); fIt++){
        cout<<fIt->first<<" - "<<fIt->second<<endl;
    }

    cout<<"MAP SIZE : "<<numMap.size()<<endl;
    cout<<"IS MAP EMPTY : "<<numMap.empty()<<endl;

    map<int, int> eraseMap  = {
        {1, 100},
        {2, 200},
        {3, 300},
        {4, 400},
        {5, 500},
        {6, 600},
        {7, 700},
        {8, 800},
        {9, 900},
        {10, 1000}
    };

    eraseMap.erase(10); //  Erase by key
    cout<<"AFTER ERASE MAP SIZE : "<<eraseMap.size()<<endl;
    eraseMap.erase(eraseMap.begin()); // Erase by Iterator
    cout<<"AFTER ERASE MAP SIZE : "<<eraseMap.size()<<endl;
    eraseMap.erase(eraseMap.begin(), eraseMap.end()); // Erase by Range
    cout<<"AFTER ERASE MAP SIZE : "<<eraseMap.size()<<endl;

    cout<<"FIND GIVE ITERATOR : "<<numMap.find(3)->second<<endl;
    cout<<"COUNT GIVE 0 OR 1 : "<<numMap.count(3)<<endl;

    cout<<"LOWER BOUND GIVE FIRST KEY ITERATOR >= k(ex k=3) : "<<numMap.lower_bound(3)->second<<endl;
    cout<<"UPPER BOUND GIVE FIRST KEY ITERATOR > k(ex k=3) : "<<numMap.upper_bound(3)->second<<endl;

    // Keys Stored in Decending Order
    // map<int, int, greater<int>> decMap;

    // Updated Map value
    // map[1]+= 5
    // map[2]++

    return 0;
}
