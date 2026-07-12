public class Evening2 {
    public static Node<Integer> separateEvenOdd(Node<Integer> head) {
        if (head == null) {
            return null;
        }
        Node<Integer> evenHead = null, evenTail = null;
        Node<Integer> oddHead = null, oddTail = null;
        Node<Integer> current = head;
        while (current != null) {
            int val = current.getValue();
            Node<Integer> newNode = new Node<>(val);
            if (val % 2 == 0) {
                if (evenHead == null) {
                    evenHead = newNode;
                    evenTail = newNode;
                } else {
                    evenTail.setNext(newNode);
                    evenTail = newNode;
                }
            } else {
                if (oddHead == null) {
                    oddHead = newNode;
                    oddTail = newNode;
                } else {
                    oddTail.setNext(newNode);
                    oddTail = newNode;
                }
            }
            current = current.getNext();
        }
        if (evenHead == null) {
            return oddHead; 
        }
        evenTail.setNext(oddHead); 
        return evenHead;
    }

    public static Node<Integer> breakCircle(Node<Integer> anyNode) {
        if (anyNode == null) {
            return null;
        }
        Node<Integer> current = anyNode;
        Node<Integer> tail = null;
        boolean foundTear = false;
        Node<Integer> temp = anyNode;
        while (true) {
            int currentVal = temp.getValue();
            int nextVal = temp.getNext().getValue();
            if (currentVal % 2 != 0 && nextVal % 2 == 0) {
                tail = temp;
                foundTear = true;
                break;
            }
            temp = temp.getNext();
            if (temp == anyNode) {
                break;
            }
        }
        if (!foundTear) {
            tail = anyNode;
            while (tail.getNext() != anyNode) {
                tail = tail.getNext();
            }
        }
        Node<Integer> head = tail.getNext();
        tail.setNext(null);
        return head;
    }
}

// O(n)
