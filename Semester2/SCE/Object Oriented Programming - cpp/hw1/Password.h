// Creator: Tal Gubenko
// ID: 215681107
// Assignment: 1

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