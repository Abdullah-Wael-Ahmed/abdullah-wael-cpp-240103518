#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int val, vector<int> unsortedArr){
    if (unsortedArr.size() <= 0) return -1; 
    else if (unsortedArr.size() == 1) {
        if (unsortedArr[0] == val) return 0;
        else return -1;
    }
    
    vector<int> arr = unsortedArr;
    sort(arr.begin(), arr.end());

    int low = 0;
    int high = arr.size() - 1;
    int mid = (low + high) / 2;

    
    while (mid <= high && mid >= low){
        if(val < arr[mid]){
            high = mid-1;
        } else if (arr[mid] < val){
            low = mid+1;
        } else {
            return mid;
        }
        mid = (high + low) / 2;
    }
    return -1;
}

int main(){

    vector<int> arr = {1, 11, 21, 31, 45, 57, 89};

    cout << binarySearch(56, arr);
}