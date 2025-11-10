#include <iostream>
#include <string>
using namespace std;

template <typename T>
void rotateRight(T& arr, int size){
    T last = arr[size-1];
    for (int i=size-2; i>=0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = last;
}

template <typename T>
void Print(T* arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i];
        if (i != size-1) cout << ", ";
    }
    cout << endl;
}

int main() {
    string* arr = new string[3]{"a", "b", "c"};
    rotateRight(*arr, 3);
    Print(arr, 3);
    delete[] arr;
}