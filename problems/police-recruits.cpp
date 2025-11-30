#include <iostream>
using namespace std;

int main() {

    int police = 0, crimes = 0, noEvents;

    cin >> noEvents;

    for (int i = 0 ; i < noEvents ; i++){
        int event;
        cin >> event;

        if (event > 0) {
            police += event;
        }

        else {
            if (police > 0) police--  ;
            else crimes++;
        }
    }

    cout << crimes;

    return 0;
}