#include <iostream>
using namespace std;

int search(int val, int *arr, int size){
    for (int i = 0 ; i < size ; i++){
        if (val == arr[size]) return i;
    }
    return -1;
}