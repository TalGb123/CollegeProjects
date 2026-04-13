public class PriorityQueue<T> {
    private PriorityNode<T> head;

    public PriorityQueue() {
        this.head = null;
    }

    public void enqueue(T item, int priority) {
        PriorityNode<T> newNode = new PriorityNode<>(item, priority);
        if (isEmpty() || priority > this.head.getPriority()) {
            newNode.setNext(this.head);
            this.head = newNode;
        } 
        else {
            PriorityNode<T> current = this.head;
            while (current.hasNext() && current.getNext().getPriority() >= priority) {
                current = current.getNext();
            }
            newNode.setNext(current.getNext());
            current.setNext(newNode);
        }
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Priority Queue is empty");
        }
        T val = this.head.getValue();
        this.head = this.head.getNext();
        return val;
    }

    public T Top() {
        if (isEmpty()) {
            throw new IllegalStateException("Priority Queue is empty");
        }
        return this.head.getValue();
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public String toString() {
        if (isEmpty()) return "[]";
        String str = "[\n";
        PriorityNode<T> current = this.head;
        while (current != null) {
            str = str + " " + current.toString();
            if (current.hasNext()) {
                str += ",\n";
            }
            current = current.getNext();
        }
        str += "\n]";
        return str;
    }
}
