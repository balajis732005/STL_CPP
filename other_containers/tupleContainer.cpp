/***********************************************************************************************
* STL Utility : tuple
* Stores multiple values
*************************************************************************************************/

#include <iostream>
#include <tuple>

using namespace std;

int main(){

    tuple<int, string, double> t1 = {1, "Balaji", 98.5};

    // ACCESS
    cout << get<0>(t1) <<" "<< get<1>(t1) <<" "<< get<2>(t1) << endl;

    // MAKE TUPLE
    auto t2 = make_tuple(10, "NAME", 30);
    cout << get<0>(t2) << " "<< get<1>(t2) << " "<< get<2>(t2) << endl;

    // MODIFY
    get<0>(t2) = 200;

    cout << "Modified tuple: ";
    cout << get<0>(t2) << " "<< get<1>(t2) << " "<< get<2>(t2) << endl;

    // Unpacking tuple
    int a;
    string b;
    double c;

    tie(a, b, c) = t1;

    cout << "Unpacked values: ";
    cout << a << " " << b << " " << c << endl;

    // Ignore some values in tuple
    tie(a, ignore, c) = t1;
    cout << a << " " << c << endl;

    // Tuple comparison
    tuple<int,int,int> x = {1,2,3};
    tuple<int,int,int> y = {1,2,4};

    if(x < y){
        cout << "x is smaller than y" << endl;
    }

    return 0;
}
