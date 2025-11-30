#include <iostream>
#include <string>
using namespace std;

// https://codeforces.com/problemset/problem/266/A

int main(){

    
    int wordLength, sum = 0;
    cin >> wordLength;
    string word;
    cin >> word;

    for (int i = 1 ; i < wordLength ; i++){
        if (word[i-1] == word[i]) sum++;
    }

    cout << sum;

    return 0;
}