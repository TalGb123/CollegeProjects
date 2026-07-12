public class Evening1 {
    public static int getDepthIterative(BinNode root, int k) {
        BinNode current = root;
        int depth = 0;
        while (current != null) {
            if (k == current.getValue()) {
                return depth;
            }
            if (k < current.getValue()) {
                current = current.getLeft();
            } else {
                current = current.getRight();
            }
            depth++;
        }
        return -1;
    }

    public static int getDepthRecursive(BinNode root, int k) {
        return getDepthRecursiveHelper(root, k, 0);
    }

    private static int getDepthRecursiveHelper(BinNode node, int k, int currentDepth) {
        if (node == null) {
            return -1;
        }
        if (k == node.getValue()) {
            return currentDepth;
        }
       if (k < node.getValue()) {
            return getDepthRecursiveHelper(node.getLeft(), k, currentDepth + 1);
        } else {
            return getDepthRecursiveHelper(node.getRight(), k, currentDepth + 1);
        }
    }
}

// O(n)