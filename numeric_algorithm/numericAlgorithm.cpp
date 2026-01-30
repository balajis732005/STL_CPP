/***********************************************************************************************
* STL Numeric Algorithms
* 1) accumulate -> Sum / custom accumulation
* 2) gcd        -> Greatest Common Divisor
* 3) lcm        -> Least Common Multiple
*************************************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>   // accumulate, gcd, lcm

using namespace std;

int main(){

    vector<int> v = {1, 2, 3, 4, 5};

    /**************************************
     * 1) ACCUMULATE
     **************************************/
    cout << "===== ACCUMULATE =====" << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of elements = " << sum << endl;

    // Accumulate with custom operation (product)
    int product = accumulate(v.begin(), v.end(), 1,
        [](int a, int b){
            return a * b;
        }
    );

    cout << "Product of elements = " << product << endl;

    cout << endl;

    /**************************************
     * 2) GCD
     **************************************/
    cout << "===== GCD =====" << endl;

    int a = 24, b = 36;

    cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;

    cout << endl;

    /**************************************
     * 3) LCM
     **************************************/
    cout << "===== LCM =====" << endl;

    cout << "lcm(" << a << ", " << b << ") = " << lcm(a, b) << endl;

    return 0;
}
