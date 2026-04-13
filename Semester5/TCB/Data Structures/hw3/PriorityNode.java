public class PriorityNode<T> {
    private T val;
    private int priority;
    private PriorityNode<T> next;

    public PriorityNode(T val, int priority) {
        this.val = val;
        this.priority = priority;
        this.next = null;
    }

    public PriorityNode(T val, int priority, PriorityNode<T> n) {
        this.val = val;
        this.priority = priority;
        this.next = n;
    }

    public T getValue() {
        return this.val;
    }

    public void setValue(T nv) {
        this.val = nv;
    }

    public int getPriority() {
        return this.priority;
    }

    public void setPriority(int newPriority) {
        this.priority = newPriority;
    }

    public PriorityNode<T> getNext() {
        return this.next;
    }

    public void setNext(PriorityNode<T> nn) {
        this.next = nn;
    }

    public boolean hasNext() {
        return this.next != null;
    }

    public String toString() {
        return "[" + this.val.toString() + " | P: " + this.priority + "]";
    }
}
