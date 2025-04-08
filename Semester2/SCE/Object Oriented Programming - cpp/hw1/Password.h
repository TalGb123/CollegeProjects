#include <iostream>
using namespace std;

class Password {
    // attributes
    private:
        int length;
        char* password;
    
    // functions
    public:
        Password(char* password);
        Password();
        Password(Password& other);
        ~Password();
        void SetDefaults();
        char* PasswordCheck(const char* password);
        char* GetPassword();
        void PrintPasswordInfo();
        bool ComparePwd(Password& other);
};