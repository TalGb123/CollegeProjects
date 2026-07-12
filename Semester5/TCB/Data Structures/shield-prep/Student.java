public class Student {
    private String sid; 
    private Node<Grade> gl;

    public Student(String sid, String cid, int s1g, int s2g) {
        this.sid = sid;
        Node<Grade> temp = gl;
        while (temp.hasNext()) {
            temp = temp.getNext();
        }
        temp.setNext(new Node<>(new Grade(cid, s1g, s2g)));
    }
}
