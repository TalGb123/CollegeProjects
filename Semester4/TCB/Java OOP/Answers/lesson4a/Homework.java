public class Homework {
    private String studentID;
    private String lecturerID;
    private int grade;

    public Homework(String studentID, String lecturerID) {
        this.studentID = studentID;
        this.lecturerID = lecturerID;
        this.grade = -1;
    }

    @Override
    public String toString() {
        return String.format("Student %s | Lecturer %s | Grade %s",
            this.studentID, this.lecturerID, (grade == -1 ? "Not graded yet" : grade));
    }

    public void SetGrade(int grade) {
        this.grade = grade;
    }

    public int GetGrade() {
        return this.grade;
    }
}
