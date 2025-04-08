#include "Password.h"
#include <iostream>
#include <string.h>

// Default values to set
void Password::SetDefaults() {
    this->length = 0;
    this->password = nullptr;
}

// Default constructor
Password::Password() {
    SetDefaults();
}

// Helper function to check password strength
char* Password::PasswordCheck(const char* pwd) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    const char* specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    int len = strlen(pwd);

    for (int i = 0; i < len; ++i) {
        if (isupper(pwd[i])) hasUpper = true;
        else if (islower(pwd[i])) hasLower = true;
        else if (isdigit(pwd[i])) hasDigit = true;
        else if (strchr(specialChars, pwd[i])) hasSpecial = true;
    }

    // Dynamically allocate memory for the result
    char* result = new char[6];
    result[0] = hasUpper ? '1' : '0';
    result[1] = hasLower ? '1' : '0';
    result[2] = hasDigit ? '1' : '0';
    result[3] = hasSpecial ? '1' : '0';
    result[4] = (len >= 8) ? '1' : '0';
    result[5] = '\0';
    return result;
}

// Constructor with password input
Password::Password(char* pwd) {
    char* check = PasswordCheck(pwd);

    // Validate the password
    if (strcmp(check, "11111") == 0) {
        this->length = strlen(pwd);
        this->password = new char[this->length + 1];
        strcpy(this->password, pwd);
    } else {
        SetDefaults(); 
    }

    delete[] check; 
}

// Copy Constructor
Password::Password(Password& other) {
    this->length = other.length;
    if (other.password) {
        this->password = new char[this->length + 1];
        strcpy(this->password, other.password);
    } else {
        this->password = nullptr;
    }
}

// Destructor
Password::~Password() {
    if (password) delete[] password;
}

// Getter
char* Password::GetPassword() {
    return this->password;
}

// Output info
void Password::PrintPasswordInfo() {
    char* check = nullptr;
    if (this->password == nullptr) {
        check = PasswordCheck(""); 
    } else {
        check = PasswordCheck(this->password);
    }

    cout << "-----Output-----" << endl;
    if (strcmp(check, "11111") == 0) {
        cout << "Password is strong." << endl;
    } else {
        cout << "Password is weak:\n";
        if (check[0] == '0') cout << "Missing uppercase letter" << endl;
        if (check[1] == '0') cout << "Missing lowercase letter" << endl;
        if (check[2] == '0') cout << "Missing digit" << endl;
        if (check[3] == '0') cout << "Missing special character" << endl;
        if (check[4] == '0') cout << "Password is shorter than 8 characters" << endl;
    }

    cout << "Password length: " << length << endl;
    if (this->password != nullptr) cout << password << endl;

    delete[] check; 
}

// Compare two passwords
bool Password::ComparePwd(Password& other) {
    if (this->password == nullptr || other.password == nullptr) {
        return false; 
    }
    return strcmp(this->password, other.password) == 0;
}