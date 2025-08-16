#include "matrix.h"

// Default constructor: creates a 1x1 matrix with default value
template <typename T>
Matrix<T>::Matrix() : rows(1), cols(1) {
      matrix = new T*[rows];
      matrix[0] = new T[cols];
      matrix[0][0] = T(); 
}

// Constructor: creates a matrix from a given 2D array
template <typename T>
Matrix<T>::Matrix(T** mtr, int rows, int cols) : rows(rows), cols(cols) {
      matrix = new T*[rows];
      for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                  matrix[i][j] = mtr[i][j];
            }
      }
}

// Copy constructor: deep copies another matrix
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
      matrix = new T*[rows];
      for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                  matrix[i][j] = other.matrix[i][j];
            }
      }
}

// Destructor: releases all dynamically allocated memory
template <typename T>
Matrix<T>::~Matrix() {
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
}

// Checks if a value exists in the matrix
template <typename T>
bool Matrix<T>::isExists(T var) {
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if (matrix[i][j] == var) {
                        return true;
                  }
            }
      }
      return false;
}

// Returns a reference to the element at (r, c)
template <typename T>
T& Matrix<T>::operator()(int r, int c) {
      if (r < 0 || c < 0 || r >= rows || c >= cols) {
            throw out_of_range("Invalid indices");
      }
      return matrix[r][c];
}

// Sets the element at (r, c) to val
template <typename T>
void Matrix<T>::operator()(int r, int c, T val) {
      if (r < 0 || c < 0 || r >= rows || c >= cols) {
            throw out_of_range("Invalid indices");
      }
      matrix[r][c] = val;
}

// Transposes the matrix (rows become columns and vice versa)
template <typename T>
void Matrix<T>::transpose() {
      T** transposed = new T*[cols];
      for (int i = 0; i < cols; i++) {
            transposed[i] = new T[rows];
            for (int j = 0; j < rows; j++) {
                  transposed[i][j] = matrix[j][i];
            }
      }
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      matrix = transposed;
      swap(rows, cols);
}

// Adds a new row to the matrix
template <typename T>
void Matrix<T>::addRow(T* row, int rowSize) {
      if (rowSize != cols) {
            throw out_of_range("Invalid indices");
      }
      T** newMatrix = new T*[rows + 1];
      for (int i = 0; i < rows; i++) {
            newMatrix[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                  newMatrix[i][j] = matrix[i][j];
            }
      }
      newMatrix[rows] = new T[rowSize];
      for (int j = 0; j < rowSize; j++) {
            newMatrix[rows][j] = row[j];
      }
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      matrix = newMatrix;
      rows++;
}

// Adds a new column to the matrix
template <typename T>
void Matrix<T>::addColumn(T* col, int colSize) {
      if (colSize != rows) {
            throw out_of_range("Invalid indices");
      }
      T** newMatrix = new T*[rows];
      for (int i = 0; i < rows; i++) {
            newMatrix[i] = new T[cols+1];
            for (int j = 0; j < cols; j++) {
                  newMatrix[i][j] = matrix[i][j];
            }
            newMatrix[i][cols] = col[i];
      }
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      matrix = newMatrix;
      cols++;
}

// Removes the row at the given index
template <typename T>
void Matrix<T>::removeRow(int rowIndex){
      if (rowIndex < 0 || rowIndex >= rows){
            throw out_of_range("Invalid indices");
      }
      T** newMatrix = new T*[rows-1];
      int newRowIndex = 0;
      for (int i = 0; i < rows; i++) {
            if (i == rowIndex) continue;
            newMatrix[newRowIndex] = new T[cols];
            for (int j = 0; j < cols; j++) {
                  newMatrix[newRowIndex][j] = matrix[i][j];
            }
            newRowIndex++;
      }
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      matrix = newMatrix;
      rows--;
}

// Removes the column at the given index
template <typename T>
void Matrix<T>::removeColumn(int colIndex){
      if (colIndex < 0 || colIndex >= cols){
            throw out_of_range("Invalid indices");
      }
      T** newMatrix = new T*[rows];
      for (int i = 0; i < rows; i++) {
            int newColIndex = 0;
            newMatrix[i] = new T[cols-1];
            for (int j = 0; j < cols; j++) {
                  if (j == colIndex) continue;
                  newMatrix[i][newColIndex] = matrix[i][j];
                  newColIndex++;
            }
      }
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      matrix = newMatrix;
      cols--;
}

// Returns a pointer to the row at the given index
template <typename T>
T* Matrix<T>::getRow(int rowIndex) const{
      if (rowIndex < 0 || rowIndex >= rows){
            throw out_of_range("Invalid indices");
      }
      return matrix[rowIndex];
}

// Assignment operator: deep copies another matrix
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
      if (this == &other) return *this;
      for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
      }
      delete[] matrix;
      rows = other.rows;
      cols = other.cols;
      matrix = new T*[rows];
      for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                  matrix[i][j] = other.matrix[i][j];
            }
      }
      return *this;
}

// Equality operator: checks if two matrices are equal
template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const {
      if (rows != other.rows || cols != other.cols) return false;
      for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                  if (matrix[i][j] != other.matrix[i][j]) return false;
            }
      }
      return true;
} 

// Output operator: prints the matrix to the output stream
template <typename T>
ostream& operator<<(ostream& os, const Matrix<T>& m) {
      os << "Matrix of type: " << typeid(T).name() << endl;
      os << "Size: " << m.rows << " x " << m.cols << endl;
      for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                  os << m.matrix[i][j] << " ";
            }
            os << endl;
      }
      return os;
}

// Explicit template instantiations for int, string, and char
template class Matrix<int>;
template class Matrix<string>;
template class Matrix<char>;  
template ostream& operator<<(ostream& os, const Matrix<int>& m);
template ostream& operator<<(ostream& os, const Matrix<string>& m);
template ostream& operator<<(ostream& os, const Matrix<char>& m);
