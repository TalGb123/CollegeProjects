public class BinNode {
    private int value;
    private BinNode left;
    private BinNode right;

    public BinNode(BinNode left, int value, BinNode right) {
        this.left = left;
        this.value = value;
        this.right = right;
    }

    // בנאי לצומת עלה (ללא בנים)
    public BinNode(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    // Getters and Setters
    public int getValue() { return value; }
    public void setValue(int value) { this.value = value; }
    public BinNode getLeft() { return left; }
    public void setLeft(BinNode left) { this.left = left; }
    public BinNode getRight() { return right; }
    public void setRight(BinNode right) { this.right = right; }

    public boolean hasLeft() { return this.left != null; }
    public boolean hasRight() { return this.right != null; }
}