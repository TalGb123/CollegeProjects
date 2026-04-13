public class Main {
    public static void main(String[] args) {
        System.out.println("=== Power ===");
        System.out.println("2^10 = " + power(2, 10));
        System.out.println("3^4 = "  + power(3, 4));
        System.out.println("5^0 = "  + power(5, 0));

        System.out.println("\n=== Linked List ===");
        Node<Integer> head = buildList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Forward:  "); 
        printList(head);           
        System.out.println();
        System.out.print("Reversed: "); 
        printListReversed(head);   
        System.out.println();

        System.out.println("\n=== String to Int ===");
        System.out.println("\"1234\"  -> " + stringToInt("1234"));
        System.out.println("\"-567\"  -> " + stringToInt("-567"));
        System.out.println("\"0\"     -> " + stringToInt("0"));

        System.out.println("\n=== String to Double ===");
        System.out.println("\"3.14\"  -> " + stringToDouble("3.14"));
        System.out.println("\"0.5\"   -> " + stringToDouble("0.5"));
        System.out.println("\"-42.0\"  -> " + stringToDouble("-42.0"));

        System.out.println("\n=== Reverse Queue ===");
        Queue<Integer> q = new Queue<>();
        for (int i = 1; i <= 5; i++) q.enqueue(i);
        System.out.println("Before: " + q);
        reverseQueue(q);
        System.out.println("After:  " + q);
    }

    public static Node<Integer> buildList(int[] arr) {
        if (arr.length == 0) return null;
        Node<Integer> head = new Node<>(arr[0]);
        Node<Integer> current = head;
        for (int i = 1; i < arr.length; i++) {
            Node<Integer> newNode = new Node<>(arr[i]);
            current.setNext(newNode);
            current = newNode;
        }
        return head;
    }

    public static double power(double x, int y) {
        if (y == 0) return 1;
        return x * power(x, y - 1);
    }

    public static void printList(Node node) {
        if (node == null) return;
        System.out.print(node.toString() + " ");
        printList(node.getNext());
    }

    public static void printListReversed(Node node) {
        if (node == null) return;
        printListReversed(node.getNext());
        System.out.print(node.toString() + " ");
    }

    public static int stringToInt(String s) {
        if (s.length() == 0) return 0;
        if (s.charAt(0) == '-') return -stringToInt(s.substring(1));
        int lastDigit = s.charAt(s.length() - 1) - '0';
        int rest = stringToInt(s.substring(0, s.length() - 1));
        return rest * 10 + lastDigit;
    }

    public static double stringToDouble(String s) {
        int dot = s.indexOf('.');
        if (dot == -1) return stringToInt(s);
        String intPart = s.substring(0, dot);
        String decPart = s.substring(dot + 1);
        double intValue = stringToInt(intPart);
        double decValue = decimalPart(decPart, 1);
        return intValue + decValue;
    }

    private static double decimalPart(String s, int depth) {
        if (s.length() == 0) return 0.0;
        double digit = s.charAt(0) - '0';
        return digit / Math.pow(10, depth) + decimalPart(s.substring(1), depth + 1);
    }

    public static void reverseQueue(Queue<Integer> q) {
        if (q.isEmpty()) return;
        int front = q.dequeue();
        reverseQueue(q);
        q.enqueue(front);
    }
}