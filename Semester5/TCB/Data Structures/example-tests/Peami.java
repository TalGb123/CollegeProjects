public class Peami {
    public static BinNode buildBSTFromList(Node<Integer> head) {
        if (head == null) {
            return null;
        }
        BinNode root = new BinNode(head.getValue());
        Node<Integer> current = head.getNext();
        while (current != null) {
            insertToBST(root, current.getValue());
            current = current.getNext();
        }
        return root;
    }

    private static void insertToBST(BinNode root, int value) {
        if (value < root.getValue()) {
            if (!root.hasLeft()) {
                root.setLeft(new BinNode(value));
            } else {
                insertToBST(root.getLeft(), value);
            }
        } else {
            if (!root.hasRight()) {
                root.setRight(new BinNode(value));
            } else {
                insertToBST(root.getRight(), value);
            }
        }
    }

    public static Node<Integer> bstToSortedList(BinNode root) {
        return bstToSortedListHelper(root, null);
    }

    private static Node<Integer> bstToSortedListHelper(BinNode root, Node<Integer> nextNode) {
        if (root == null) {
            return nextNode;
        }
        Node<Integer> rightList = bstToSortedListHelper(root.getRight(), nextNode);
        Node<Integer> currentListNode = new Node<>(root.getValue(), rightList);
        return bstToSortedListHelper(root.getLeft(), currentListNode);
    }
}

// O(n)