/***********************************************************************************************
* STL Algorithms Demo
* 1) binary_search  -> Search in sorted container
* 2) stable_sort    -> Sort while preserving relative order
* 3) partial_sort   -> Sort only first K elements
*************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    // BINARY SEARCH
    vector<int> bsVec = {5, 1, 4, 2, 3};
    sort(bsVec.begin(), bsVec.end());
    cout << "Sorted Vector : ";
    for(int x : bsVec){
        cout << x << " ";
    }
    cout << endl;

    int key = 3;
    if(binary_search(bsVec.begin(), bsVec.end(), key)){
        cout << key << " FOUND using binary_search" << endl;
    } else {
        cout << key << " NOT FOUND using binary_search" << endl;
    }

    // STABLE_SORT
    // pair<value, original_id>
    vector<pair<int,char>> stVec = {
        {2,'A'}, {1,'B'}, {2,'C'}, {1,'D'}
    };

    cout << "Before stable_sort : ";
    for(auto p : stVec){
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    // Stable sorting by first value
    stable_sort(stVec.begin(), stVec.end(),
        [](auto &a, auto &b){
            return a.first < b.first;
        }
    );

    cout << "After stable_sort  : ";
    for(auto p : stVec){
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    /*
        Note:
        Elements with same key (1 or 2) preserve original order
        (1,B) comes before (1,D)
        (2,A) comes before (2,C)
    */

    // PARTIAL_SORT
    vector<int> psVec = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    cout << "Original Vector   : ";
    for(int x : psVec){
        cout << x << " ";
    }
    cout << endl;

    int k = 4;

    // Sort only first k elements
    partial_sort(psVec.begin(), psVec.begin() + k, psVec.end());
    cout << "After partial_sort (k=4): ";
    for(int x : psVec){
        cout << x << " ";
    }
    cout << endl;

    /*
        First 4 elements are the smallest 4 elements in sorted order
        Remaining elements are in unspecified order
    */

    return 0;
}
