#include <ostream>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> class Matrix;
template <typename T> ostream& operator<<(ostream& os, const Matrix<T>& m);

template <typename T> 
class Matrix {
      private:
            int rows;
            int cols;
            T** matrix;
      public:
            Matrix();
            Matrix(T** mtr, int rows, int cols);
            Matrix(const Matrix<T>& other);
            ~Matrix();
            bool isExists(T var);
            T& operator()(int r, int c);
            void operator()(int r, int c, T val);
            void transpose();
            void addRow(T* row, int rowSize);
            void addColumn(T* col, int colSize);
            void removeRow(int rowIndex);
            void removeColumn(int colIndex);
            T* getRow(int rowIndex) const;
            Matrix<T>& operator=(const Matrix<T>& other);
            bool operator==(const Matrix<T>& other) const;
            friend ostream& operator<<<T>(ostream& os, const Matrix<T>& m);
            int getRows() const { return rows; }
            int getCols() const { return cols; }
            
                 
};