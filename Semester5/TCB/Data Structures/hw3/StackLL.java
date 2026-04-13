public class StackLL<T> {
    private Node<T> head;
    private int size;

    public StackLL(T val) {
        this.size = 1;
        this.head = new Node<T>(val);
    }

    public StackLL() {
        this.head = null;
        this.size = 0;
    }

    public void push(T val) {
        head = new Node<T>(val, head);
        size++;
    }

    public T pop() {
        if (isEmpty()) {
            
        }
        T val = head.getValue();
        head = head.getNext();
        size--;
        return val;
    }

    public boolean isEmpty() {
        return head == null;
    }
}
