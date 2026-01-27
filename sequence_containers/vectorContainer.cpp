/***********************************************************************************************
 * Data Structure : vector
 * Size : Dynamic
 * Memory : Heap
 * Fast : Yes
 * Resize : Possible
 * Access : O(1)
 * push_back : O(1) amortized
 * insert/erase middle : O(N)
 * erase : O(N)
 * remove : O(N)
 * search : O(N)
 * Sort : O(N * log N)
 * Access : Fast
 * Insert Middle : Slow
 * Include : #include<vector>
*************************************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> empVec;
    cout<<"EMPTY VECTOR SIZE : "<<empVec.size()<<endl;

    vector<int> zeroVec(5); // Size = 5, All 0
    cout<<"ZERO VECTOR : "<<endl;
    for(int i=0;i<zeroVec.size();i++){
        cout<<zeroVec[i]<<" ";
    }
    cout<<endl;

    vector<int> fillVec(5, -1); // Size = 5. All -1
    cout<<"FILLED VECTOR : "<<endl;
    for(int i=0;i<fillVec.size();i++){
        cout<<fillVec.at(i)<<" ";
    }
    cout<<endl;

    /*
      <vector_name>.at(<index>) => Gives Out of Bounds Error
      <vector_name>[<index>] => Can't give Out of Boounds Error
    */

    vector<int> iniVec = {1, 2, 3, 4, 5};
    cout<<"INITIALIZED VECTOR : "<<endl;
    for(int v: iniVec){
        cout<<v<<" ";
    }
    cout<<endl;

    vector<int> numVec;
    for(int i=1;i<=5;i++){
        numVec.push_back(i);
    }
    cout<<"NUMBER VECTOR : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    cout<<"VECTOR SIZE : "<<numVec.size()<<endl;
    cout<<"VECTOR CAPACITY : "<<numVec.capacity()<<endl;
    cout<<"VECTOR FIRST ELEMENT : "<<numVec.front()<<endl;
    cout<<"VECTOR LAST ELEMENT : "<<numVec.back()<<endl;

    numVec.push_back(10);
    numVec.emplace_back(20); // Faster than push_back
    cout<<"NUMBER VECTOR AFTER PUSH AND EMPLACE BACK : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    numVec.pop_back();
    cout<<"NUMBER VECTOR AFTER POP BACK : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    int indexToRemove = 2;
    numVec.erase(numVec.begin() + 2);
    cout<<"NUMBER VECTOR AFTER INDEX 2 ERASED : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    numVec.erase(numVec.begin()+1, numVec.begin()+3); // erase(s, e) => erase s to e-1
    cout<<"NUMBER VECTOR AFTER ERASED FROM INDEX 1 TO 2 : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    vector<int> remVec = {1,2,3,4,2,5};
    auto endIt = remove(remVec.begin(), remVec.end(), 2);
    // Remove all the Instance of 2 and put garbage values at last and return the shifted places Iterator
    // remove will not change the size of vector
    cout<<"LAST ELEMENT OF REM VECTOR BY REMOVE METHOD : "<<*endIt<<endl;
    cout<<"REMOVED 2 PLACES IN REM VECTOR : "<<endl;
    for(auto fIt = remVec.begin(); fIt != remVec.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;

    // ERASE + REMOVE Usage
    vector<int> eraseRemoveTest = {1,2,3,4,5,6,7,6,7,6,6};
    eraseRemoveTest.erase(
        remove(eraseRemoveTest.begin(), eraseRemoveTest.end(), 6),
        eraseRemoveTest.end()
    );
    // Shift Elements which are not equal to 6 then erase the unwanted garbage values
    // Advatage of using erase + remove => If you want to delete all the instance of x then running loop and erase will take O(N^2) but this take O(N)

    cout<<"ERASE + REMOVE OPERATION : "<<endl;
    for(int i=0;i<eraseRemoveTest.size();i++){
        cout<<eraseRemoveTest.at(i)<<" ";
    }
    cout<<endl;

    // Remove All Zeros in an vector
    /* 
    <vector_name>.erase(
        remove(<vector_name>.begin(), <vector_name>.end(), 0),
        <vector_name>.end()
    ) 
    */

    // Remove All Negative Number in an Vector
    /*
    <vector_name>.erase(
        remove_if(<vector_name>.begin(), <vector_name>.end(), 
            [](int x){retunr x<0}
        ),
        <vector_name>.end()
    )
    */

    // ITERATORS FOR ARRAY
    // Iterators Stores the address of the elements, so dereference and get the element
    cout<<"ITERATOR : \n";
    for(auto fIt = numVec.begin(); fIt != numVec.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;
    cout<<"REVERSE ITERATOR : \n";
    for(auto rIt = numVec.rbegin(); rIt != numVec.rend(); rIt++){
        cout<<*rIt<<" ";
    }
    cout<<endl;

    numVec.insert(numVec.begin() + 1, 100); // Inserted 100 in Index 1
    numVec.insert(numVec.begin() + 1, 5, 200); // Inserted 5 times 200 from Index 1
    cout<<"NUMBER VECTOR AFTER INSERTION : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    numVec.resize(15); // Change the Size
    numVec.reserve(100); // Change only the Capacity
    cout<<"NUMBER VECTOR AFTER RESIZE : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    // numVec.clear(); // Make Size = 0, Capacity = unchanged

    cout<<"IS EMPTY NUMBER VECTOR : "<<numVec.empty()<<endl;

    numVec.swap(iniVec);
    cout<<"NUMBER VECTOR SWAP : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;
    cout<<"INITIALIZE VECTOR SWAP : "<<endl;
    for(int i=0;i<iniVec.size();i++){
        cout<<iniVec.at(i)<<" ";
    }
    cout<<endl;
    numVec.swap(iniVec);

    sort(numVec.begin(), numVec.end());
    cout<<"NUMBER VECTOR SORT : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    sort(numVec.begin(), numVec.end(), greater<int>());
    cout<<"NUMBER VECTOR SORT DECENDING : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    reverse(numVec.begin(), numVec.end());
    cout<<"NUMBER VECTOR REVERSE : "<<endl;
    for(int i=0;i<numVec.size();i++){
        cout<<numVec.at(i)<<" ";
    }
    cout<<endl;

    int countElement = count(numVec.begin(), numVec.end(), 200);
    cout<<"COUNT OF 200 IN NUMBER VECTOR : "<<countElement<<endl;

    int maxiElement = *max_element(numVec.begin(), numVec.end());
    int miniElement = *min_element(numVec.begin(), numVec.end());

    cout<<"MINI ELEMENT IN NUMBER VECTOR : "<<miniElement<<endl;
    cout<<"MAXI ELEMENT IN NUMBER VECTOR : "<<maxiElement<<endl;

    // 2-D VECTOR
    vector<vector<int>> twoDVec(5, vector<int>(5, 0));
    cout<<"2D VECTOR : "<<endl;
    for(auto &row : twoDVec){
        for(int x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    /*
     for(auto row : twoDVec){} -> This copies vector Element, size, capacity by Iteration
     for(auto &row : teoDVec){} -> Here row is reference to the Actual vector (** FASTER THE COPYING **) 
     for(const auto &row : twoDVec){} -> Read Only + Safe
    */
    
    return 0;
}
