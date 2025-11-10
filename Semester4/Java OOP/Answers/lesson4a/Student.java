public class Student {
    private String studentID;
    private Homework homework;

    public Student(String studentID) {
        this.studentID = studentID;
        this.homework = null;
    }

    public boolean readyToSubmit() {
        if (this.homework != null) {
            return false;
        }
        int randomNum = (int) (Math.random() * 2); 
        if (randomNum == 1) {
            return true;
        }   
        return false;
    }   

    public void Submit(Website website, String lecturerID) {
        this.homework = new Homework(this.studentID, lecturerID);
        website.SetHomework(this.homework);
    }

    public String GetStudentID() {
        return this.studentID;
    }

    public Homework GetHomework() {
        return this.homework;
    }

    public void SetGrade(int grade){
        this.homework.SetGrade(grade);
    }

    public void PrintGrade(){
        System.out.println("Student " + this.studentID + " grade: " + this.homework.GetGrade());
    }
}
