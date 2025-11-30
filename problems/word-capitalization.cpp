#include <iostream>
#include <string>
using namespace std;

// https://codeforces.com/problemset/problem/281/A

int main() {

    string word;
    cin >> word;

    word[0] = toupper(word[0]);

    cout << word;

    return 0;
}