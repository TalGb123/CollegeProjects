public class Queue<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public Queue() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void enqueue(T item) {
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

    public T dequeue() {
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

    public T top() {
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

    // public boolean contains(T item) {
    //     boolean found = false;
    //     int currentSize = this.size();
    //     for (int i = 0; i < currentSize; i++) {
    //         T val = this.dequeue();
    //         if (val.equals(item)) {
    //             found = true;
    //         }
    //         this.enqueue(val);
    //     }
    //     return found;
    // }

    // public int countOccurrences(T item) {
    //     int count = 0;
    //     int currentSize = this.size();
    //     for (int i = 0; i < currentSize; i++) {
    //         T val = this.dequeue();
    //         if (val.equals(item)) {
    //             count++;
    //         }
    //         this.enqueue(val);
    //     }
    //     return count;
    // }
    
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
