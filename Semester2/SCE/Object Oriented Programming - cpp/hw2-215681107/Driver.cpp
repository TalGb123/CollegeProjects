// Assignment: 2
// Creator: Tal Gubenko, 215681107

#include "Game.h"
#include <iostream>
using namespace std;

int main(){
    int no;
    cout<<"Enter number of cards you want to play with"<<endl;
    cin>>no;
    Game m(no);
    m.Run();
    return 0;
}