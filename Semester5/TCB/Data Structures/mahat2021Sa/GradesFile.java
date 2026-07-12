public class GradesFile {
    private Queue<Student>[] gradesArray; 

    public GradesFile() {
        this.gradesArray = new Queue[100]; 
        for (int i = 0; i < 100; i++) {
            this.gradesArray[i] = new Queue<Student>();
        }
    }
    
    public void moveStudent(int k, int j) {
        if (k < 0 || k > 99 || j < 0 || j > 99) {
            return;
        }
        if (this.isEmpty(k)) {
            return;
        }
        Student s = this.gradesArray[k].dequeue();
        this.gradesArray[j].enqueue(s);
    }

    public boolean isEmpty(int k) {
        if (k < 0 || k >= 100) {
            return true;
        }
        if (this.gradesArray[k] == null) {
            return true;
        }
        return this.gradesArray[k].isEmpty();
    }

    public Student getStudent(int k) {
        if (this.isEmpty(k)) {
            return null;
        }
        return this.gradesArray[k].top(); 
    }

    public boolean listIsGood(int k) {
        if (this.isEmpty(k)) {
            return true;
        }
        boolean isGood = true;
        Queue<Student> tempQueue = new Queue<Student>();
        while (!this.gradesArray[k].isEmpty()) {
            Student currentStudent = this.gradesArray[k].dequeue();
            if (currentStudent.getCode() != k) {
                isGood = false;
            }
            tempQueue.enqueue(currentStudent);
        }
        while (!tempQueue.isEmpty()) {
            this.gradesArray[k].enqueue(tempQueue.dequeue());
        }
        return isGood;
    }
}

