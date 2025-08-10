template <class T>
void MoveLeft(T* arr, int size, int num) {
      T* temp = new T[size];
      for (int i=0; i<size; i++){
            temp[(i-num+size)%size] = arr[i];
      }
      for (int i=0; i<size; i++){
            arr[i] = temp[i];
      }
      delete[] temp;
}

int main(){
      char ch[] = {'a', 'b', 'c', 'd'};
      MoveLeft(ch, 4, 2);
      return 0;
}