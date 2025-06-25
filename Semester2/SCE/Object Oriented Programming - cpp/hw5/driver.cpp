#include <iostream>
#include <string>
#include <stdexcept>
#include "matrix.h"
using namespace std;

int main() {
    try {
        cout << "=== MATRIX TESTING PROGRAM ===" << endl;
        
        // Get matrix dimensions from user
        int rows, cols;
        cout << "Enter matrix dimensions (rows cols): ";
        cin >> rows >> cols;
        
        cout << "\n=== TESTING INT MATRICES ===" << endl;
        
        // Create int matrix with user input
        int** data1 = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data1[i] = new int[cols];
        }
        
        cout << "Enter " << rows << "x" << cols << " integer matrix values:" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "Row " << (i+1) << ": ";
            for (int j = 0; j < cols; j++) {
                cin >> data1[i][j];
            }
        }
        
        Matrix<int> matrix1(data1, rows, cols);
        cout << "\nOriginal int matrix:" << endl;
        cout << matrix1 << endl;
        
        // Test transpose
        char choice;
        cout << "Transpose matrix? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            matrix1.transpose();
            cout << "After transpose:" << endl;
            cout << matrix1 << endl;
        }
        
        // Test element access
        int r, c;
        cout << "Enter position to check (row col, 0-indexed): ";
        cin >> r >> c;
        try {
            cout << "Element at (" << r << "," << c << "): " << matrix1(r, c) << endl;
            
            // Test setting element
            int newVal;
            cout << "Enter new value for this position: ";
            cin >> newVal;
            matrix1(r, c, newVal);
            cout << "After setting (" << r << "," << c << ") = " << newVal << ":" << endl;
            cout << matrix1 << endl;
        } catch (const exception& e) {
            cout << "Error accessing element: " << e.what() << endl;
        }
        
        // Test isExists
        int searchVal;
        cout << "Enter value to search for: ";
        cin >> searchVal;
        cout << "Does " << searchVal << " exist? " << (matrix1.isExists(searchVal) ? "Yes" : "No") << endl;
        
        cout << "\n=== TESTING CHAR MATRICES ===" << endl;
        
        int charRows, charCols;
        cout << "Enter char matrix dimensions (rows cols): ";
        cin >> charRows >> charCols;
        
        char** charData = new char*[charRows];
        for (int i = 0; i < charRows; i++) {
            charData[i] = new char[charCols];
        }
        
        cout << "Enter " << charRows << "x" << charCols << " character matrix:" << endl;
        for (int i = 0; i < charRows; i++) {
            cout << "Row " << (i+1) << ": ";
            for (int j = 0; j < charCols; j++) {
                cin >> charData[i][j];
            }
        }
        
        Matrix<char> chMatrix1(charData, charRows, charCols);
        cout << "\nChar Matrix:" << endl;
        cout << chMatrix1 << endl;
        
        // Test addRow
        cout << "Add a new row? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            char* newRow = new char[charCols];
            cout << "Enter " << charCols << " characters for new row: ";
            for (int i = 0; i < charCols; i++) {
                cin >> newRow[i];
            }
            
            try {
                chMatrix1.addRow(newRow, charCols);
                cout << "After adding row:" << endl;
                cout << chMatrix1 << endl;
            } catch (const exception& e) {
                cout << "Error adding row: " << e.what() << endl;
            }
            delete[] newRow;
        }
        
        // Test transpose on char matrix
        cout << "Transpose char matrix? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            chMatrix1.transpose();
            cout << "After transpose:" << endl;
            cout << chMatrix1 << endl;
        }
        
        cout << "\n=== TESTING STRING MATRICES ===" << endl;
        
        int strRows, strCols;
        cout << "Enter string matrix dimensions (rows cols): ";
        cin >> strRows >> strCols;
        
        string** strData = new string*[strRows];
        for (int i = 0; i < strRows; i++) {
            strData[i] = new string[strCols];
        }
        
        cout << "Enter " << strRows << "x" << strCols << " string matrix:" << endl;
        cin.ignore(); 
        for (int i = 0; i < strRows; i++) {
            for (int j = 0; j < strCols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                getline(cin, strData[i][j]);
            }
        }
        
        Matrix<string> strMatrix(strData, strRows, strCols);
        cout << "\nString Matrix:" << endl;
        cout << strMatrix << endl;
        
        cout << "\n=== TESTING MATRIX OPERATIONS ===" << endl;
        
        // Create another int matrix for operations
        int opRows, opCols;
        cout << "Enter dimensions for operations test matrix (rows cols): ";
        cin >> opRows >> opCols;
        
        int** data2 = new int*[opRows];
        for (int i = 0; i < opRows; i++) {
            data2[i] = new int[opCols];
        }
        
        cout << "Enter " << opRows << "x" << opCols << " integer values:" << endl;
        for (int i = 0; i < opRows; i++) {
            cout << "Row " << (i+1) << ": ";
            for (int j = 0; j < opCols; j++) {
                cin >> data2[i][j];
            }
        }
        
        Matrix<int> matrix2(data2, opRows, opCols);
        cout << "\nOperations test matrix:" << endl;
        cout << matrix2 << endl;
        
        // Test addColumn
        cout << "Add a column? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int* newCol = new int[opRows];
            cout << "Enter " << opRows << " values for new column: ";
            for (int i = 0; i < opRows; i++) {
                cin >> newCol[i];
            }
            
            try {
                matrix2.addColumn(newCol, opRows);
                cout << "After adding column:" << endl;
                cout << matrix2 << endl;
                opCols++; 
            } catch (const exception& e) {
                cout << "Error adding column: " << e.what() << endl;
            }
            delete[] newCol;
        }
        
        // Test removeRow
        cout << "Remove a row? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int rowIndex;
            cout << "Enter row index to remove (0-" << (opRows-1) << "): ";
            cin >> rowIndex;
            
            try {
                matrix2.removeRow(rowIndex);
                cout << "After removing row " << rowIndex << ":" << endl;
                cout << matrix2 << endl;
                opRows--; 
            } catch (const exception& e) {
                cout << "Error removing row: " << e.what() << endl;
            }
        }
        
        // Test removeColumn
        cout << "Remove a column? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int colIndex;
            cout << "Enter column index to remove (0-" << (opCols-1) << "): ";
            cin >> colIndex;
            
            try {
                matrix2.removeColumn(colIndex);
                cout << "After removing column " << colIndex << ":" << endl;
                cout << matrix2 << endl;
                opCols--; 
            } catch (const exception& e) {
                cout << "Error removing column: " << e.what() << endl;
            }
        }
        
        // Test getRow
        if (opRows > 0) {
            int rowIndex;
            cout << "Enter row index to display (0-" << (opRows-1) << "): ";
            cin >> rowIndex;
            
            try {
                int* row = matrix2.getRow(rowIndex);
                cout << "Row " << rowIndex << " elements: ";
                for (int i = 0; i < opCols; i++) {
                    cout << row[i] << " ";
                }
                cout << endl;
            } catch (const exception& e) {
                cout << "Error getting row: " << e.what() << endl;
            }
        }
        
        // Clean up dynamically allocated arrays
        for (int i = 0; i < rows; i++) {
            delete[] data1[i];
        }
        delete[] data1;
        
        for (int i = 0; i < charRows; i++) {
            delete[] charData[i];
        }
        delete[] charData;
        
        for (int i = 0; i < strRows; i++) {
            delete[] strData[i];
        }
        delete[] strData;
        
        for (int i = 0; i < opRows; i++) {
            delete[] data2[i];
        }
        delete[] data2;
        
        cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << endl;
        
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        return 1;
    }

    return 0;
}