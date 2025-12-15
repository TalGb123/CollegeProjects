
import java.util.LinkedList;
import java.util.Queue;

public class Website {
    private Queue<Homework> homeworks;
    private String lecturerID;

    public Website(String lecturerID) {
        this.lecturerID = lecturerID;
        this.homeworks = new LinkedList<>();
    }

    public void SetHomework(Homework hw) {
        this.homeworks.add(hw);
    }

    public Homework GetNextHomework() {
        return homeworks.poll(); 
    }

    public boolean HasHomework() {
        return !homeworks.isEmpty();
    }
}
