template <class T>
~Vector() {
      for (int i=0; i < size; i++){
            delete[] data[i];
      }
      delete[] data;
}

template <class T>
Vector& operator+=(const T& obj){
      Vector** temp = new Vector[++size];
      for (int i=0; i < size - 1; i++){
            temp[i] = data[i];
            delete[] data[i];
      }
      temp[size-1] = obj;
      delete[] data;
      data = temp;
      return *this;
}

friend ostream& operator<<(ostream& os, const Vector<T> vec){
      if (vec.size == 0) {
            os << "empty" << endl;
            return os;
      }
      os << "array stuff: "
      for (int i=0; i<vec.size; i++){
            os << vec.data[i] << " ";
      }
      os << endl;
      return os;
}

template <class T>
int main(){
      Vector<float>* vec = new Vector<float>();
      // for with +=
      cout << vec;
      return 0;
}