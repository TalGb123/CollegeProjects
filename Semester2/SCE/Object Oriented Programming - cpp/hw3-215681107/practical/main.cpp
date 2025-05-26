// name: Tal Gubenko
// id: 215681107
// assignment: 3

#include "EncryptedText.h"
#include <iostream>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {   
    srand(0); 
    EncryptedText etext1("The London is capital of Great Britian.", 0); 
    int key1[] = { 3, -1, 4, 1, -1, 3, 1, 0, 4, 4, -1, 0, 5, -1, 0, -2 }; 
    cout << etext1; 
    etext1.setKeySize(16);
    etext1 += key1; 
    !etext1;        
    cout << etext1;
    cout << "----------------------------------------------------------" << endl; 
    EncryptedText etext2("RH oLMWLM gSV yIRGRZM tIVZG LU 3eCQ GZOXZKR.", 1); 
    cout << etext2; 
    etext2.setKeySize(16);
    etext2 += key1; 
    &etext2; 
    cout << etext2;
}