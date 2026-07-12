public class Morning1 {
    public static Node<Integer> switchHalves(Node<Integer> head) {
        if (head == null || !head.hasNext()) {
            return head;
        }
        Node<Integer> slow = head;
        Node<Integer> fast = head;
        Node<Integer> prevSlow = null;
        while (fast != null && fast.hasNext()) {
            fast = fast.getNext().getNext();
            prevSlow = slow;
            slow = slow.getNext();
        }
        prevSlow.setNext(null);
        Node<Integer> current = slow;
        while (current.hasNext()) {
            current = current.getNext();
        }
        current.setNext(head);
        return slow;
    }

    public static BinNode flipTree(BinNode root) {
        if (root == null) {
            return null;
        }
        BinNode flippedLeft = flipTree(root.getLeft());
        BinNode flippedRight = flipTree(root.getRight());
        root.setLeft(flippedRight);
        root.setRight(flippedLeft);
        return root;
    }
}

// O(n)
