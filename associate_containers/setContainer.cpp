/***********************************************************************************************
 * Data Structure : set
 * Properties : stored Unique Elements in Sorted Order
 * Point : can't Modify the Elements
 * Operation : Red-Black Tree
 * Size : Dynamic
 * Memory : set object - Stack, tree node - Heap
 * Resize : Possible
 * insert : O(log N)
 * erase : O(log N)
 * find : O(log N)
 * Include : #include<set>
*************************************************************************************************/

#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    set<int> numSet;

    // INSERT
    numSet.insert(10);
    numSet.emplace(20);

    // FIND
    auto it = numSet.find(10);
    if(it != numSet.end()){
        cout<<"ELEMENT FOUND IN SET : "<<*it<<endl;
    }
    cout<<"COUNT GIVE 0 OR 1 : "<<numSet.count(20)<<endl;

    // ITERATE
    cout<<"ITERATE SET : "<<endl;
    for(auto fIt = numSet.begin(); fIt!=numSet.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;
    for(int x : numSet){
        cout<<x<<" ";
    }
    cout<<endl;

    // ERASE
    set<int> eraseSet = {1,2,3,4,5,5,5,5,6};
    eraseSet.erase(1); // Erase by Value
    cout<<"SET SIZE BY ERASE : "<<eraseSet.size()<<endl;
    eraseSet.erase(eraseSet.begin()); // Erase by Iterator
    cout<<"SET SIZE BY ERASE : "<<eraseSet.size()<<endl;
    eraseSet.erase(eraseSet.begin(), eraseSet.end()); // Erase by Range
    cout<<"SET SIZE BY ERASE : "<<eraseSet.size()<<endl;

    set<int> valSet = {1,2,3,4,5,5,5,5,6};

    cout<<"LOWER BOUND GIVE FIRST KEY ITERATOR >= k(ex k=3) : "<<*valSet.lower_bound(3)<<endl;
    cout<<"UPPER BOUND GIVE FIRST KEY ITERATOR > k(ex k=3) : "<<*valSet.upper_bound(3)<<endl;

    // Decending Order Set
    // set<int, greater<int>> decSet;

    vector<int> dupVec = {1,2,3,4,4,4,4,5,5,5,5,6,6,6,1,1,2,2,2};
    set<int> nonDupSet(dupVec.begin(), dupVec.end());
    cout<<"REVERSE ITERATOR : "<<endl;
    for(auto rIt=nonDupSet.rbegin(); rIt != nonDupSet.rend(); rIt++){
        cout<<*rIt<<" ";
    }
    cout<<endl;

    int maxiElement = *max_element(nonDupSet.begin(), nonDupSet.end());
    int miniElement = *min_element(nonDupSet.begin(), nonDupSet.end());

    cout<<"MAXI ELEMENT : "<<maxiElement<<endl;
    cout<<"MINI ELEMENT : "<<miniElement<<endl;
    
    return 0;
}
