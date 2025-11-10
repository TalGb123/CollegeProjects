public class Lecturer {
    private String lecturerID;

    public Lecturer(String lecturerID) {
        this.lecturerID = lecturerID;
    }
    
    public void GradeHomework(Website website) {
        while (website.HasHomework()) {
            Homework hw = website.GetNextHomework();
            if (hw != null) {
                hw.SetGrade((int)(Math.random() * (101 - 20)) + 20);
            }
        }
    }

    public String GetID() {
        return lecturerID;
    }
}
