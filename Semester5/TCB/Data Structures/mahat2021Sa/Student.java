public class Student {
    private int studentId; // 8-digit number
    private int grade;     // Final grade

    // Constructors, getters, and setters
    public Student(int studentId, int grade) {
        this.studentId = studentId;
        this.grade = grade;
    }
    
    public int getStudentId() { return this.studentId; }
    public int getGrade() { return this.grade; }

    public int getCode() {
        int temp = this.studentId / 1000;
        return temp % 100;
    }

    
}