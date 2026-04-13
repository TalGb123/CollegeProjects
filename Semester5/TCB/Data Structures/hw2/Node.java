public class Node<T> {
    private T val;
    private Node<T> next;

    public Node(T val) {
        this.val = val;
        this.next = null;
    }

    public Node(T val, Node<T> n) {
        this.val = val;
        this.next = n;
    }

    public T getValue() {
        return this.val;
    }

    public Node<T> getNext() {
        return this.next;
    }

    public void setValue(T nv) {
        this.val = nv;
    }

    public boolean hasNext() {
        return this.next != null;
    }

    public void setNext(Node<T> nn) {
        this.next = nn;
    }

    public String toString() {
        return this.val.toString();
    }
}
