#include <iostream>
#include <string>
using namespace std;

// Template function to swap two elements
template <typename T>
void Swap(T& a, T& b) {
      T temp = a;
      a = b;
      b = temp;
}

// Template partition function for QuickSort
template <typename T>
int partition(T* arr, int low, int high) {
      T pivot = arr[high];
      int i = low - 1;
      for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                  ++i;
                  Swap(arr[i], arr[j]);
            }
      }
      Swap(arr[i + 1], arr[high]);
      return i + 1;
}

// Template QuickSort function
template <typename T>
void QuickSort(T* arr, int low, int high) {
      if (low < high) {
            int pi = partition(arr, low, high);
            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
      }
}

// ✅ Template function to check if value exists in array
template <typename T>
bool ExistsInArray(T* arr, int size, T value) {
      for (int i = 0; i < size; ++i) {
            if (arr[i] == value)
                  return true;
      }
      return false;
}

int main() {
      int arr[10] = {12, 11, 9, 8, 1, 14, 10, 20, 3, 16};
      int n = 10;
      cout << "Given the following int array:" << endl;
      for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
      }
      cout << endl;

      QuickSort(arr, 0, n - 1);

      cout << "The sorted array will be:" << endl;
      for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
      }
      cout << endl;

      int valToFind = 10;
      cout << "Does value " << valToFind << " exist in the array? "
            << (ExistsInArray(arr, n, valToFind) ? "Yes" : "No") << endl;

      // Example with strings
      string sarr[5] = {"banana", "apple", "orange", "grape", "pear"};
      int sn = 5;
      cout << "\nGiven the following string array:" << endl;
      for (int i = 0; i < sn; ++i) {
            cout << sarr[i] << " ";
      }
      cout << endl;

      QuickSort(sarr, 0, sn - 1);

      cout << "The sorted string array will be:" << endl;
      for (int i = 0; i < sn; ++i) {
            cout << sarr[i] << " ";
      }
      cout << endl;

      string strToFind = "grape";
      cout << "Does value \"" << strToFind << "\" exist in the array? "
            << (ExistsInArray(sarr, sn, strToFind) ? "Yes" : "No") << endl;

      return 0;
}
