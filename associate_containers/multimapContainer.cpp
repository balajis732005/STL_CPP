/***********************************************************************************************
 * Data Structure : multimap
 * Properties : duplicate keys allowed, Sorted by Keys
 * Operation : Red-Black Tree
 * Size : Dynamic
 * Memory : multimap object - Stack, tree node - Heap
 * Resize : Possible
 * insert : O(log N)
 * erase : O(log N)
 * find : O(log N)
 * Access : O(log N)
 * Include : #include<map>
*************************************************************************************************/

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    multimap<int, int> numMultimap;

    // INSERT
    numMultimap.insert({1, 10});
    numMultimap.insert({1, 20});
    numMultimap.insert({2, 30});
    numMultimap.emplace(2, 40);

    // <multimap_name>[<key>] -> It is Not Allowed

    // ITERATION
    for(auto fIt = numMultimap.begin(); fIt != numMultimap.end(); fIt++){
        cout<<fIt->first<<" - "<<fIt->second<<endl;
    }
    for(auto &p : numMultimap){
        cout<<p.first<<" - "<<p.second<<endl;
    }

    // SEARCH
    cout<<"FIND GIVES FIRST OCCURENCE OF KEY ITERATOR : "<<numMultimap.find(1)->second<<endl;
    cout<<"COUNT GIVES NO.OF ENTRIES WITH KEY : "<<numMultimap.count(1)<<endl;

    auto keyAllvalues = numMultimap.equal_range(1);
    cout<<"VALUES OF KEY 1 : "<<endl;
    for(auto fIt = keyAllvalues.first; fIt != keyAllvalues.second; fIt++){
        cout<<fIt->second<<" ";
    }
    cout<<endl;

    cout<<"LOWER BOUND GIVE FIRST KEY ITERATOR >= K (ex k=1) : "<<numMultimap.lower_bound(1)->second<<endl;
    cout<<"UPPER BOUND GIVE FIRST KEY ITERTOR > K (ex k=1) : "<<numMultimap.upper_bound(1)->second<<endl;

    // ERASE
    multimap<int, int> eraseMultiMap = {
        {1,10},
        {1,20},
        {1,30},
        {2,40},
        {2,50},
        {2,60},
        {3,70},
        {3,80},
        {4,90},
        {4,100}
    };

    eraseMultiMap.erase(4); // Erase All Entries with key = 4
    cout<<"SIZE OF MAP : "<<eraseMultiMap.size()<<endl;

    // Erase only the first Entry
    auto it = eraseMultiMap.find(1);
    if(it != eraseMultiMap.end()){
        eraseMultiMap.erase(it); // Erase by Iterator
    }
    cout<<"SIZE OF MAP : "<<eraseMultiMap.size()<<endl;

    // Erase by Range
    auto rangeIt = eraseMultiMap.equal_range(2);
    eraseMultiMap.erase(rangeIt.first, rangeIt.second);
    cout<<"SIZE OF MAP : "<<eraseMultiMap.size()<<endl;

    cout<<"IS EMPTY IN MAP : "<<numMultimap.empty()<<endl;

    // Decending Order of multimap
    // multimap<int, int, greater<int>> mp;

    return 0;
}