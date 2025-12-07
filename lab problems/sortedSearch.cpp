#include <iostream>
#include <algorithm>

using namespace std;

int sortedSearch(int val, int *arr, int size){
    sort(arr, arr+size);
    for (int i = 0 ; i < size ; i++){
        if (val == arr[i]) return i;
        if (val > arr[i]) return -1;
    }
    return -1;
}

int main(){
    int arr[] = {1, 5, 3, 59, 40, 4};

    cout << sortedSearch(43, arr, 6) << endl;

    for (int i : arr){
        cout << i << " ";
    }

}