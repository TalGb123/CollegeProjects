
public class BST {
    private BinNode<Integer> root;

    public void insertR(int x) {
        root = insertRec(root, x);
    }

    private BinNode<Integer> insertRec(BinNode<Integer> node, int x) {
        if (node == null) {
            return new BinNode<>(x);
        }

        if (x < node.getValue()) {
            node.setLeft(insertRec(node.getLeft(), x));
        } else {
            node.setRight(insertRec(node.getRight(), x));
        }

        return node;
    }

    public void insertI(int x) {
        if (root == null) {
            root = new BinNode<>(x);
            return;
        }

        BinNode<Integer> curr = root;

        while (true) {
            if (x < curr.getValue()) {
                if (curr.getLeft() == null) {
                    curr.setLeft(new BinNode<>(x));
                    return;
                }
                curr = curr.getLeft();
            } else {
                if (curr.getRight() == null) {
                    curr.setRight(new BinNode<>(x));
                    return;
                }
                curr = curr.getRight();
            }
        }
    }

    public static int getFollowing(BinNode<Integer> root, int n) {
        BinNode<Integer> successor = null;
        BinNode<Integer> curr = root;

        while (curr != null) {
            if (n < curr.getValue()) {
                successor = curr;
                curr = curr.getLeft();
            } else if (n > curr.getValue()) {
                curr = curr.getRight();
            } else {
                break;
            }
        }

        if (curr == null)
            return -1;

        if (curr.hasRight()) {
            BinNode<Integer> temp = curr.getRight();
            while (temp.hasLeft()) {
                temp = temp.getLeft();
            }
            return temp.getValue();
        }

        return (successor != null) ? successor.getValue() : -1;
    }

    public static boolean equalNodes(BinNode<Integer> root) {
        if (root == null) {
            return false;
        }

        if (root.hasLeft() && root.hasRight()) {
            if (root.getLeft().getValue().equals(root.getRight().getValue())) {
                return true;
            }
        }

        return equalNodes(root.getLeft()) || equalNodes(root.getRight());
    }

    public static int sumNodes(BinNode<Integer> root) {
        if (root == null)
            return 0;
        return root.getValue() + sumNodes(root.getLeft()) + sumNodes(root.getRight());
    }

    public static int biggerNodes(BinNode<Integer> root) {
        if (root == null)
            return 0;
        return biggerNodesRec(root.getRight());
    }

    private static int biggerNodesRec(BinNode<Integer> root) {
        if (root == null)
            return 0;
        return 1 + biggerNodesRec(root.getLeft()) + biggerNodesRec(root.getRight());
    }

    public static int biggerNodesTree(BinNode<Integer> root) {
        if (root == null)
            return 0;
        return biggerNodesTreeRec(root, root.getValue());
    }

    private static int biggerNodesTreeRec(BinNode<Integer> root, int value) {
        if (root == null)
            return 0;
        return (root.getValue() > value ? 1 : 0) + biggerNodesTreeRec(root.getLeft(), value)
                + biggerNodesTreeRec(root.getRight(), value);

    }

    public boolean isBst(BinNode<Integer> root) {
        return isBstHelper(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isBstHelper(BinNode<Integer> root, int min, int max) {
        if (root == null) {
            return true;
        }

        if (root.getValue() <= min || root.getValue() >= max) {
            return false;
        }

        return isBstHelper(root.getLeft(), min, root.getValue()) &&
                isBstHelper(root.getRight(), root.getValue(), max);
    }

    public int findMax(BinNode<Integer> root) {
        if (!root.hasRight())
            return root.getValue();
        return findMax(root.getRight());
    }

    public static BinNode<Integer> deleteNode(BinNode<Integer> root, int value) {
        if (root == null)
            return null;
        int curr = root.getValue();
        if (curr > value) {
            root.setLeft(deleteNode(root.getLeft(), value));
        } else if (curr < value) {
            root.setRight(deleteNode(root.getRight(), value));
        } else {
            if (!root.hasLeft())
                return root.getRight();
            else if (!root.hasRight())
                return root.getLeft();

            int minValue = findMin(root.getRight());
            root.setValue(minValue);
            root.setRight(deleteNode(root.getRight(), minValue));
        }
        return root;
    }

    public static int findMin(BinNode<Integer> root) {
        if (!root.hasLeft())
            return root.getValue();
        return findMin(root.getLeft());
    }

    public static boolean search(BinNode<Integer> root, int value) {
        if (root == null)
            return false;
        return searchRec(root, value);
    }

    private static boolean searchRec(BinNode<Integer> root, int value) {
        if (root == null)
            return false;
        if (value < root.getValue()) {
            return searchRec(root.getLeft(), value);
        } else if (value > root.getValue()) {
            return searchRec(root.getRight(), value);
        } else
            return true;
    }

    public static void printPreOrder(BinNode<Integer> root) {
        if (root == null)
            return;
        System.out.print(String.valueOf(root.getValue()) + " ");
        printPreOrder(root.getLeft());
        printPreOrder(root.getRight());
    }

    public static void printInOrder(BinNode<Integer> root) {
        if (root == null)
            return;
        printInOrder(root.getLeft());
        System.out.print(String.valueOf(root.getValue()) + " ");
        printInOrder(root.getRight());
    }

    public static void printPostOrder(BinNode<Integer> root) {
        if (root == null)
            return;
        printPostOrder(root.getLeft());
        printPostOrder(root.getRight());
        System.out.print(root.getValue() + " ");
    }

    public static int getHeight(BinNode<Integer> root) {
        if (root == null)
            return -1;
        return Math.max(getHeight(root.getLeft()), getHeight(root.getRight())) + 1;
    }
}
