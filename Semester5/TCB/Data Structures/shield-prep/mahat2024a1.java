

public class mahat2024a1 {
    public static boolean isUniform(Stack<Integer> st) {
        Stack<Integer> temp = new Stack<>();
        boolean flag;
        boolean ret = true;
        if (st.top() % 2 == 0) flag = true;
        else flag = false;
        int num;
        while (!st.isEmpty()) {
            num = st.pop();
            if (num % 2 == 0 && flag) temp.push(num);
            else if (num % 2 != 0 && !flag) temp.push(num);
            else break;
        }
        if (!st.isEmpty()) ret = false;
        while (!temp.isEmpty()) {
            st.push(temp.pop());
        }
        return ret;
    }
    
    public static int removeLast(Queue<Integer> q) {
        Queue<Integer> temp = new Queue<>();
        int count = 0;
        while (!q.isEmpty()) {
            temp.insert(q.remove());
            count++;
        }
        for (int i=0; i<count-1; i++) {
            q.insert(temp.remove());
        }
        return temp.remove();
    }

    public static boolean uniqNeg(Node<Integer> chain) {
        Node<Integer> pos = chain;
        Node<Integer> temp;
        int num;
        while (pos != null) {
            if (pos.getValue() < 0) {
                num = pos.getValue();
                temp = pos;
                while (temp != null) {
                    temp = temp.getNext();
                    if (temp.getValue() == num) return false;
                }
            }
            pos = pos.getNext();
        }
        return true;
    }

    public static void q8main(BinNode root) {
        if (root == null) return;
        double avg = (sumBTHelper(root.getRight(), 0) + sumBTHelper(root.getLeft(), 0) + root.getValue()) / TreeCount(root);
        underAvgPrint(root, avg);
    }

    public static int sumBTHelper(BinNode root, int sum) {
        if (root == null) return 0;
        sum = sumBTHelper(root.getLeft(), sum) + sumBTHelper(root.getRight(), sum);
        return sum;
    }

    public static void underAvgPrint(BinNode root, double avg) {
        if (root == null) return;
        if (root.getValue() < avg) System.out.println(root.getValue());
        underAvgPrint(root.getLeft(), avg);
        underAvgPrint(root.getRight(), avg);
    }

    public static double TreeCount(BinNode bt)
    {
        if (bt == null) {
            return 0;
        }
        else {
            return 1 + TreeCount(bt.getLeft()) + TreeCount(bt.getRight());
        }
    }

}
