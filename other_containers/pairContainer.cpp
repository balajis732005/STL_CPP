/***********************************************************************************************
* STL Utility : pair
* Stores exactly 2 values
*************************************************************************************************/

#include <iostream>
#include <utility>
#include<vector>

using namespace std;

int main(){

    pair<int, int> p1 = {10, 20};

    cout << "First  = " << p1.first << endl;
    cout << "Second = " << p1.second << endl;

    // Make Pair
    pair<string, int> p2 = make_pair("Balaji", 100);
    cout << p2.first << " " << p2.second << endl;

    // Pair in vector
    vector<pair<int, int>> v = {{1,2}, {3,4}, {5,6}};

    for(auto p : v){
        cout << p.first << "," << p.second << "  ";
    }
    cout << endl;

    // Nested pair
    pair<int, pair<int, int>> p3 = {1, {2, 3}};
    cout << p3.first << " "<< p3.second.first << " "<< p3.second.second << endl;

    // Pair Comparison lexicographical
    pair<int,int> a = {1, 5};
    pair<int,int> b = {2, 3};

    if(a < b){
        cout << "a is smaller than b" << endl;
    }

    return 0;
}
