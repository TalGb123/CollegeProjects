#include <iostream>
using namespace std;

template <typename T>
bool CheckSortAsc(const T* arr, int size){
    for (int i=1; i<size; i++){
        if (arr[i] <= arr[i-1]) return false;
    }
    return true;
}

int main(){
    double* arr = new double[3]{1, 2, 3};
    if (CheckSortAsc(arr, 3)) cout << "sorted array" << endl;
    else cout << "unsorted array" << endl;
    delete[] arr;
}
