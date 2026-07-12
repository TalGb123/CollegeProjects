public class Queue<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public Queue() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void insert(T item) {
        Node<T> newNode = new Node<>(item);
        if (isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.setNext(newNode);
            this.tail = newNode;
        }
        this.size++;
    }

    public T remove() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T val = this.head.getValue();
        this.head = this.head.getNext();
        if (this.head == null) {
            this.tail = null;
        }
        this.size--;
        return val;
    }

    public T head() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return this.head.getValue();
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public int size() {
        return this.size;
    }
    
    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        
        StringBuilder sb = new StringBuilder("[");
        Node<T> current = this.head;
        while (current != null) {
            sb.append(current.getValue());
            if (current.hasNext()) {
                sb.append(", ");
            }
            current = current.getNext();
        }
        sb.append("]");
        return sb.toString();
    }
}
