#include <iostream>
using namespace std;
#include <string>

template <class T>
class Set {
      T* data;
      int size;
      public:
            Set() :data(NULL), size(0) {}//def ctor
            ~Set() { delete[] data; } //dtor
            void Print() const;

            template <class T>
            bool operator==(const Set<T>& second)const{
                  if (size != second.size) return false;
                  for (int i=0; i<size; i++){
                        for (int j=0; j<second.size; j++){
                              if (data[i] == second.data[j]){
                                    break;
                              }
                              if (j == second.size-1) return false;
                        }
                  }
                  return true;
            }

            
            Set<T>& operator-=(const T val) {
                  int newIndex = 0;
                  bool found = false;
                  if (size <= 0) return *this;
                  T* temp = new T[size-1];
                  for (int i=0; i<size; i++){
                        if (data[i] != val){
                              temp[newIndex++] = data[i];
                        }
                        else found = true;
                  }
                  if (found) {
                        delete[] data;
                        data = temp;
                        size--;    
                        cout << "val removed" << endl;
                  } 
                  else {
                        delete[] temp;
                        cout << "val not removed" << endl;
                  }
                  return *this;
            }

            void Print() const {
                  for (int i = 0; i < size; i++){
                        cout << data[i] << ','; 
                  }
                  cout << endl;
            }     
};

int main() {
      Set<string> set1, set2;

      // set1 += "apple";
      // set1 += "banana";
      // set1 += "cherry";

      // set2 += "banana";
      // set2 += "apple";
      // set2 += "cherry";
      
      cout << "Set1: ";
      set1.Print();
      cout << "Set2: ";
      set2.Print();
      
      if (set1 == set2) {
            cout << "The sets are identical!" << endl;
      } else {
            cout << "The sets are different!" << endl;
      }
      
      cout << "\nRemoving 'banana' from set1..." << endl;
      set1 -= "banana";
      
      cout << "Set1 after removal: ";
      set1.Print();
      
      if (set1 == set2) {
            cout << "The sets are identical!" << endl;
      } else {
            cout << "The sets are different!" << endl;
      }
      
      cout << "\nTrying to remove 'grape' from set1..." << endl;
      set1 -= "grape";
      cout << "Set1 after trying to remove non-existing element: ";
      set1.Print();
      
      return 0;
}