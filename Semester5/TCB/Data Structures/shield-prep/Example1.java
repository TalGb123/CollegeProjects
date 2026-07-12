public class Example1 {
    public static int EvenOrOdd(Node<Integer> lst) {
        if (lst == null) return -1;
        int flag = lst.getValue() % 2;
        Node<Integer> pos = lst.getNext();
        while (pos != null) {
            if (pos.getValue() % 2 != flag) {
                return -1;
            }
            pos = pos.getNext();
        }
        return flag;
    }

    public static boolean Unique(Queue<Integer> q) {
        Queue<Integer> temp = new Queue<>();
        Queue<Integer> nq = new Queue<>();
        int size = 0;
        while (!q.isEmpty()) {
            temp.insert(q.remove());
            size++;
        }
        int num, tempNum;
        for (int i=0; i<size; i++) {
            num = temp.remove();
            q.insert(num);
            while (!temp.isEmpty()) {
                tempNum = temp.remove();
                if (tempNum == num) return false;
                nq.insert(tempNum);
            }
            while (!nq.isEmpty()) {
                temp.insert(nq.remove());
            }
        }
        return true;
    }

    public static boolean UpOrDown(Node<Integer> lst) {
        if (lst == null || lst.getNext() == null) return false;
        Node<Integer> pos1 = lst.getNext();
        int dir = 1;
        if (pos1.getValue() < lst.getValue()) return false;
        while (pos1.getNext() != null) {
            if (pos1.getValue() < pos1.getNext().getValue() && dir == 1) {}
            else if (pos1.getValue() > pos1.getNext().getValue() && dir == 1) {
                dir = 2;
                pos1 = pos1.getNext();
            }
            else if (pos1.getValue() < pos1.getNext().getValue() && dir == 2) return false;
            pos1 = pos1.getNext();
        }
        return dir == 2;
    }

    public static int QueueSize(Queue<Integer> q) {
        Queue<Integer> temp = new Queue<>();
        int count = 0;
        while (!q.isEmpty()) {
            temp.insert(q.remove());
            count++;
        }
        while (!temp.isEmpty()) q.insert(temp.remove());
        return count;
    }

    public static boolean StartQueue(Queue<Integer> q1, Queue<Integer> q2) {
        boolean flag = true;
        int n1, n2;
        int s1 = QueueSize(q1);
        int s2 = QueueSize(q2);
        if (s1 >= s2) return false;
        Queue<Integer> temp = new Queue<>();
        while (!q1.isEmpty()) {
            n1 = q1.remove();
            n2 = q2.remove();
            if (n1 != n2) flag = false;
            temp.insert(n1);
            temp.insert(n2);
        }
        while (!q2.isEmpty()) {
            temp.insert(q2.remove());
        }
        while (!temp.isEmpty()) {
            if (s1 > 0) {
                q1.insert(temp.remove());
                s1--;
            }
            if (s2 > 0) {
                q2.insert(temp.remove());
                s2--;   
            }
        }
        return flag;
    }
}   
