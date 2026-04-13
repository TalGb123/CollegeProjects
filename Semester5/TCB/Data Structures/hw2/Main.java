public class Main {
    public static void main(String[] args) {
        
    }

    public static Node<Integer> removeEvenValues(Node<Integer> head) {
        while (head != null && head.getValue() % 2 == 0) {
            head = head.getNext();
        }
        if (head == null) return null;
        Node<Integer> current = head;
        while (current.hasNext()) {
            if (current.getNext().getValue() % 2 == 0) {
                current.setNext(current.getNext().getNext());
            } else {
                current = current.getNext();
            }
        }
        return head;
    }

    public static Node<Integer> removeEvenPositions(Node<Integer> head) {
        if (head == null) return null;
        head = head.getNext();
        if (head == null) return null;
        Node<Integer> current = head;
        while (current != null && current.hasNext()) {
            Node<Integer> evenNode = current.getNext();
            current.setNext(evenNode.getNext());
            current = current.getNext();
        }
        return head;
    }
}
