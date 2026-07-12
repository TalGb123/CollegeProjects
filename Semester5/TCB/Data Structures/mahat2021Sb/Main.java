public class Main {
    public static void main(String[] args) {
        //q1
        // int N = 4;
        // Queue<Integer> stepQ = createStepQueue(N);
        // System.out.println("Generated Step Queue for N=" + N + ":");
        // System.out.println(stepQ);
        // System.out.println("Is stepQ a valid step queue for N=4? " + isStepQueue(stepQ, 4)); 
        // System.out.println("Is stepQ a valid step queue for N=3? " + isStepQueue(stepQ, 3)); 
        // System.out.println("Queue after check: " + stepQ); 

        //q2
        // Node<Integer> head1 = new Node<>(1);
        // head1.setNext(new Node<>(1));
        // head1.getNext().setNext(new Node<>(2));
        // head1.getNext().getNext().setNext(new Node<>(4));
        // System.out.println("Is head1 a sum sequence? " + isSumSequence(head1));
        // Node<Integer> head2 = new Node<>(64);
        // head2.setNext(new Node<>(32));
        // head2.getNext().setNext(new Node<>(16));
        // head2.getNext().getNext().setNext(new Node<>(8));
        // head2.getNext().getNext().getNext().setNext(new Node<>(4));
        // head2.getNext().getNext().getNext().getNext().setNext(new Node<>(2));
        // head2.getNext().getNext().getNext().getNext().getNext().setNext(new Node<>(2));
        // System.out.println("Is head2 a sum sequence? " + isInverseSumSequence(head2));

        
    }

    public static Queue<Integer> createStepQueue(int N) {
        Queue<Integer> q = new Queue<>();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                q.enqueue(i);
            }
        }
        return q;
    }

    public static boolean isStepQueue(Queue<Integer> q, int N) {
        Queue<Integer> temp = new Queue<>();
        boolean isValid = true;
        int expectedVal = 1;
        int expectedCount = 1; 
        while (!q.isEmpty()) {
            int current = q.dequeue();
            temp.enqueue(current);
            if (isValid) {
                if (expectedVal > N || current != expectedVal) {
                    isValid = false;
                } 
                else {
                    expectedCount--;
                    if (expectedCount == 0) {
                        expectedVal++;
                        expectedCount = expectedVal;
                    }
                }
            }
        }
        if (expectedVal != N + 1) {
            isValid = false;
        }
        while (!temp.isEmpty()) {
            q.enqueue(temp.dequeue());
        }
        return isValid;
    }

    public static boolean isSumSequence(Node<Integer> head) {
        if (head == null || head.getNext() == null) {
            return true;
        }
        int prev = head.getValue();
        Node<Integer> curr = head.getNext();
        if (curr.getValue() != prev) {
            return false;
        }
        prev = curr.getValue();
        curr = curr.getNext();
        while (curr != null) {
            if (curr.getValue() != 2 * prev) {
                return false;
            }
            prev = curr.getValue();
            curr = curr.getNext();
        }
        return true;
    }

    public static boolean isInverseSumSequence(Node<Integer> head) {
        if (head == null || head.getNext() == null) {
            return true;
        }
        Node<Integer> curr = head;
        while (curr.getNext() != null) {
            int currentVal = curr.getValue();
            int nextVal = curr.getNext().getValue();
            if (curr.getNext().getNext() == null) {
                if (currentVal != nextVal) {
                    return false;
                }
            } 
            else {
                if (currentVal != 2 * nextVal) {
                    return false;
                }
            }
            curr = curr.getNext();
        }
        return true;
    }
}
