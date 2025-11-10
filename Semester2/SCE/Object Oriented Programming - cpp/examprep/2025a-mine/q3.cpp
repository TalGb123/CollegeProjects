#include <iostream>
#include <string>
using namespace std;
#include <stdexcept>

template <class T>
class Matrix {
    T** data;
    int rows, cols;

    public:
        Matrix(T** db, int r, int c) : rows(r), cols(c) {
            data = new T*[rows];
            for (int i = 0; i < rows; ++i) {
                this->data[i] = new T[cols];
                for (int j = 0; j < cols; ++j) {
                    this->data[i][j] = db[i][j];
                }
            }
        }

        ~Matrix() {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }

        void Print() const {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++){
                    cout << data(i,j) << " ";
                }
                cout << endl;
            }
        }

        friend ostream& operator<<(ostream& output, const Matrix& m) {
            for (int i=0; i<m.rows; i++) {
                for (int j=0; j<m.cols; j++){
                    output << data(i,j) << " ";
                }
                output << endl;
            }
            return output;
        }

        T& operator()(int row, int col) const {
            if (0 <= row < rows && 0<=col<cols){
                return data[row][col];
            }
            else {
                throw range_error("out of range");
            }
        }
};

int main() {
    int** matrix = new int*[2];
    for (int i=0; i<2; i++){
        matrix[i] = new int[5];
        for (int j=0; j<5; j++){
            matrix[i][j] = i+j;
        }
    }

    Matrix<int>* m = new Matrix<int>(matrix, 2, 5);

    cout << "print: " << endl;
    m->Print();

    cout << "op: " << endl;
    cout << m;
}