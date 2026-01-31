/***********************************************************************************************
* STL Count
* 1) count     -> Count exact value occurrences
* 2) count_if  -> Count elements satisfying a condition
*************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v = {1, 2, 3, 4, 3, 2, 3, 5};

    // COUNT
    int target = 3;
    int cnt = count(v.begin(), v.end(), target);
    cout << "Vector elements : ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    cout << "Count of " << target << " = " << cnt << endl;

    // COUNT_IF
    // Count even numbers
    int evenCount = count_if(v.begin(), v.end(),
        [](int x){
            return x % 2 == 0;
        }
    );
    cout << "Even numbers count = " << evenCount << endl;

    // Count numbers greater than 3
    int greaterCount = count_if(v.begin(), v.end(),
        [](int x){
            return x > 3;
        }
    );
    cout << "Numbers > 3 count = " << greaterCount << endl;

    return 0;
}
