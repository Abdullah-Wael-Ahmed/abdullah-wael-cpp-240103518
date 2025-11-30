#include <iostream>
#include <string>
using namespace std;

// https://codeforces.com/problemset/problem/58/A

int main() {

    string word, val = "hello";
    int cursor = 0;
    cin >> word;

    for (int i = 0 ; i < word.length() ; i++){
        if (word[i] == val[cursor]) cursor++;
    }

    if (cursor == 5) cout << "YES";
    else cout << "NO";

    return 0;
}