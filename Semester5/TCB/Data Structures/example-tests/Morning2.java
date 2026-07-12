public class Morning2 {
    public static int countGreaterThanKIterative(Node<Integer> head, int k) {
        int count = 0;
        Node<Integer> current = head;
        while (current != null) {
            if (current.getValue() > k) {
                count++;
            }
            current = current.getNext();
        }
        return count;
    }

    public static int countGreaterThanKRecursive(Node<Integer> head, int k) {
        if (head == null) {
            return 0;
        }
        if (head.getValue() > k) {
            return 1 + countGreaterThanKRecursive(head.getNext(), k);
        } else {
            return countGreaterThanKRecursive(head.getNext(), k);
        }
    }
}

// O(n)
