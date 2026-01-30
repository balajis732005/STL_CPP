/***********************************************************************************************
* STL Utility : tuple
* Stores multiple values
*************************************************************************************************/

#include <iostream>
#include <tuple>   // tuple

using namespace std;

int main(){

    // 1) Declare and initialize
    tuple<int, string, double> t1 = {1, "Balaji", 98.5};

    // Access using get<index>
    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

    cout << endl;

    // 2) Using make_tuple
    auto t2 = make_tuple(10, 20, 30);

    cout << get<0>(t2) << " "
         << get<1>(t2) << " "
         << get<2>(t2) << endl;

    cout << endl;

    // 3) Modify values
    get<1>(t2) = 200;

    cout << "Modified tuple: ";
    cout << get<0>(t2) << " "
         << get<1>(t2) << " "
         << get<2>(t2) << endl;

    cout << endl;

    // 4) Unpacking tuple
    int a;
    string b;
    double c;

    tie(a, b, c) = t1;

    cout << "Unpacked values: ";
    cout << a << " " << b << " " << c << endl;

    cout << endl;

    // 5) Ignore some values
    tie(a, ignore, c) = t1;
    cout << a << " " << c << endl;

    cout << endl;

    // 6) Tuple comparison
    tuple<int,int,int> x = {1,2,3};
    tuple<int,int,int> y = {1,2,4};

    if(x < y){
        cout << "x is smaller than y" << endl;
    }

    return 0;
}
