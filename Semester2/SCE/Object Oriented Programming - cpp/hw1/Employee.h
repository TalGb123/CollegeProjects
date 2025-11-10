// Creator: Tal Gubenko
// ID: 215681107
// Assignment: 1

class Employee {
    // Attributes
    private:
        char name[51];
        char id[10];
        int seniority;
        int excellence;
        bool hasDegree;
        bool isNumeric(const char* str);
        
    // function declarations
    public:
        Employee(const char* name, const char* id, int seniority, int excellence, bool hasDegree);
        Employee();
        Employee(const Employee& other);
        void SetDefaults();
        void SetName(char* name);
        void SetId(char* id);
        void SetSeniority(int seniority);
        void SetExcellence(int excellence);
        void SetHasDegree(bool hasDegree);
        char* GetName();
        char* GetId();
        int GetSeniority();
        int GetExcellence();
        bool GetHasDegree();
        int BonusCalculation();
        int SalaryCalculation();
        void PrintEmployeeInfo();
};

