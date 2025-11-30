#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/228/A

int main(){


    int shoes[4];
    int sum = 0;

    for (int i = 0 ; i < 4 ; i++){
        cin >> shoes[i];
    }

    for (int i = 0 ; i < 3 ; i++){
        for (int j = i + 1 ; j < 4 ; j++){
            if (shoes[i] == shoes[j]) {
                sum++;
                break;
            }
        }
    }

    cout << sum;

    return 0;
}