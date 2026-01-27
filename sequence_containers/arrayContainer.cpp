/***********************************************************************************************
 * Data Structure : array
 * Size : fixed
 * Memory : Stack
 * Fast : Yes
 * Resize : Notpossible
 * Access : O(1)
 * Sort : O(N * log N)
 * Include : #include<array>
*************************************************************************************************/

#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int main(){
    // WITHOUT ELEMENT INITIALIZATION
    array<int, 5> garArr; // Intialize with garbage values
    array<int, 5> zeroArr = {}; // Intialize all with zeros

    // TRAVERSAL
    cout<<"GARBAGE ARRAY : \n";
    for(int i=0;i<garArr.size();i++){
        cout<<garArr.at(i)<<" ";
    }
    cout<<endl;

    cout<<"ZERO ARRAY : \n";
    for(int i=0;i<zeroArr.size();i++){
        cout<<zeroArr[i]<<" ";
    }
    cout<<endl;

    /*
      <array_name>.at(<index>) => Gives Out of Bounds Error
      <array_name>[<index>] => Can't give Out of Boounds Error
    */

    // ARRAY ACCESS, SIZE AND EMPTY CHECK
    array<int, 5> numArr = {1, 2, 3, 4, 5};
    cout<<"ARRAY FIRST ELEMENT : "<<numArr.front()<<endl;
    cout<<"ARRAY LAT ELEMENT : "<<numArr.back()<<endl;
    cout<<"ARRAY SIZE : "<<numArr.size()<<" - "<<numArr.max_size()<<endl;
    cout<<"IS EMPTY : "<<numArr.empty()<<endl;

    // ARRAY FILL
    array<int, 5> fillArr;
    fillArr.fill(-1);
    cout<<"FILL ARRAY : \n";
    for(int f: fillArr){
        cout<<f<<" ";
    }
    cout<<endl;

    // ARRAYS SWAP
    array<int, 5> oddArr = {1, 3, 5, 7, 9};
    array<int, 5> evenArr = {2, 4, 6, 8, 10};
    oddArr.swap(evenArr);
    cout<<"SWAPED ARRAYS : \n";
    for(int i=0;i<5;i++){
        cout<<"ARR 1 - ["<<i<<"] : "<<oddArr.at(i)<<endl;
        cout<<"ARR 2 - ["<<i<<"] : "<<evenArr.at(i)<<endl;
    }

    // ITERATORS FOR ARRAY
    // Iterators Stores the address of the elements, so dereference and get the element
    cout<<"ITERATOR : \n";
    for(auto fIt = numArr.begin(); fIt != numArr.end(); fIt++){
        cout<<*fIt<<" ";
    }
    cout<<endl;
    cout<<"REVERSE ITERATOR : \n";
    for(auto rIt = numArr.rbegin(); rIt != numArr.rend(); rIt++){
        cout<<*rIt<<" ";
    }
    cout<<endl;

    // SORT ARRAY
    array<int, 5> sortArr = {3, 1, 10, 4, 5};
    sort(sortArr.begin(), sortArr.end());
    cout<<"SORT ARRAY : \n";
    for(auto it = sortArr.begin(); it != sortArr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    sort(sortArr.begin(), sortArr.end(), greater<int>());
    cout<<"SORT ARRAY DECENDING : \n";
    for(auto it = sortArr.begin(); it != sortArr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // REVERSE ARRAY
    reverse(sortArr.begin(), sortArr.end());
    cout<<"REVERSE ARRAY : \n";
    for(auto it = sortArr.begin(); it != sortArr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // FIND ELEMENT IN ARRAY
    auto findEle = find(sortArr.begin(), sortArr.end(), 20); 
    // Return the pointer Address points to that Element. If Element not found then return array last element pointing address
    if(findEle != sortArr.end()){
        cout<<"FIND ELEMENT 4 INDEX : "<<findEle - sortArr.begin()<<endl; 
        // To get the Index of Element subtract the array first element address
    }else{
        cout<<"Element Not Found"<<endl;
    }

    // ARRAY COMPARISON
    cout<<"ARRAY COMPARISON : "<< (sortArr == sortArr) <<endl; // Match meanse return 1 otherwise 0

    // Runtime Element we Can't Assign as size for the array
    // int len;
    // cout<<"Enter the size of array : ";
    // cin>>len;
    // array<int, len> lenArr;

    // MAXIMUM IN ARRAY
    cout<<"MAXIMUM ELEMENT OF ARRAY : ";
    int maxEle = *max_element(sortArr.begin(), sortArr.end()); 
    // Return the address pointing to maximum element, so dereference and get the element
    cout<<maxEle<<endl;

    // MINIMUM IN ARRAY
    cout<<"MINIMUM ELEMENT OF ARRAY : ";
    int minEle = *min_element(sortArr.begin(), sortArr.end());
    // Return the address pointing to minimum element, so dereference and get the element
    cout<<minEle<<endl;
    return 0;
}
