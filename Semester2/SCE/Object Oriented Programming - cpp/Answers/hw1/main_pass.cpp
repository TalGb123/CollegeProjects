// Creator: Tal Gubenko
// ID: 215681107
// Assignment: 1

#include "Password.cpp"

int main() {
    char* password = new char(); 
    Password p1, p2, p3, p4;
    for (int i = 0; i < 4; i++) {
        cout << "Enter password: ";
        cin >> password; 

        // Create a Password object and print password info
        Password p(password);
        p.PrintPasswordInfo();

        // Store the password in a variable based on the index
        if (i==0) Password p1 = p; 
        else if (i==1) Password p2 = p;
        else if (i==2) Password p3 = p;
        else if (i==3) Password p4 = p; 
    }

    // Compare passwords
    cout << "-----Output-----" << endl;
    cout << "If p1 = p3? " << (p1.ComparePwd(p3) ? "Yes" : "No") << endl;
    cout << "If p1 = p2? " << (p1.ComparePwd(p3) ? "Yes" : "No") << endl;
    return 0;
}