#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int>& arr, int begin, int end)
{
    cout << begin << " " << end <<  endl;
    if (end - begin == 1) return arr;
    int pivot = end;
    int i = begin - 1;
    int j = begin;
    while (j != pivot){
        if (arr[j] > arr[pivot]) j++;
        else {
            swap(arr[++i], arr[j++]);
        }
    }
    swap(arr[++i],arr[pivot]);
    swap(i, pivot);

    quickSort(arr, begin, pivot - 1);
    quickSort(arr, pivot+1, end);
    return arr;
}

int main()
{

    vector<int> arr = {8, 2, 4, 7, 1, 3, 9, 6, 5};
    quickSort(arr, 0, arr.size() - 1);
    for (int i :  arr){
        cout << i << " ";
    }

    return 0;
}