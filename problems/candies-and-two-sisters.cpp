#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/1335/A

int main(){

    int noTestCases;
    cin >> noTestCases;

    for (int i = 0 ; i < noTestCases ; i++){

        int noCandles;
        cin >> noCandles;

        cout << (noCandles-1) - (noCandles/2) << endl;
    }

    return 0;
}