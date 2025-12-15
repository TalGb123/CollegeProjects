public class Driver {
    public static void main(String[] args) {
        Student[] students = new Student[10];
        Lecturer lec1 = new Lecturer("lec1");
        Website website = new Website(lec1.GetID());
        for (int i=0; i<10; i++) {
            students[i] = new Student(Integer.toString(i+1));
        }
        while (StudentsLeft(students) > 0) {
            for (Student stud : students) {
                if (stud.readyToSubmit()){
                    stud.Submit(website, lec1.GetID());
                }
            }
            lec1.GradeHomework(website);
        }
        System.out.println("\n=== All homeworks graded ===");
        for (Student stud : students) {
            int grade = stud.GetHomework().GetGrade();
            stud.SetGrade(grade);
            stud.PrintGrade();
        }
    }

    public static int StudentsLeft(Student[] students) {
        int count = 0;
        for (Student stud : students) {
            if (stud.GetHomework() == null) {
                count++;
            }
        }
        return count;
    }

    
}
