#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> orgArr){
    vector<int> arr =  orgArr;
    for (int i = 0 ; i < arr.size() ; i++){
        int min = i;
        for (int j = i + 1 ; j < arr.size() ; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (arr[i] != arr[min]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return arr;
}

int main(){

    vector<int> arr = {1, 45, 5, 3, 544, 6, -5};
    vector<int> sorted = selectionSort(arr);

    for (int i : sorted){
        cout << i << " ";
    }

    return 0;
}
