#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    bool swapped;
    
    do{
        swapped = false;
        for (int i = 0 ; i < arr.size() - 1 ; i++){
            int j = i+1;
            if (arr[i] > arr[j]){
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
    }while(swapped != false);
}


int main(){

    vector<int> arr = {5, 59, 3, 22, 10, -5, 0};
    bubbleSort(arr);
    for (int i : arr){
        cout << i << " ";
    }
}