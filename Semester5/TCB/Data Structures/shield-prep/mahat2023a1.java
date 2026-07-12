

public class mahat2023a1 {
    public static Queue<Double> averageQueue(Queue<Integer> marks, Queue<Integer> tests) {
        Queue<Double> nq = new Queue<>();
        int test;
        double avg;
        while (!tests.isEmpty()) {
            test = tests.remove();
            avg = 0;
            for (int i=0; i<test; i++) {
                avg += marks.remove();
            }
            nq.insert(avg/test);
        }
        return nq;
    }

    public static int numDigits(Node<Integer> n) {
        int dig = 0;
        Node<Integer> pos = n;
        while (pos != null) {
            dig++;
            pos = pos.getNext();
        }
        return dig;
    }

    public static int compare(Node<Integer> n1, Node<Integer> n2) {
        int len1 = numDigits(n1);
        int len2 = numDigits(n2);
        Node<Integer> pos1 = n1;
        Node<Integer> pos2 = n2;
        if (len1 > len2) {
            return 1;
        }
        else if (len2 > len1) {
            return 2;
        }
        int val1, val2;
        while (n1 != null) {
            val1 = pos1.getValue();
            val2 = pos2.getValue();
            if (val1 > val2) {
                return 1;
            }
            else if (val2 > val1) {
                return 2;
            }
            pos1 = pos1.getNext();
            pos2 = pos2.getNext();
        }
        return 0;
    }

    public static int distance(Node<Integer> lst, int num) {
        int sc = 0;
        int ec = 0;
        boolean flag = false;
        Node<Integer> pos = lst;
        while (pos != null) {
            if (pos.getValue() == num && !flag) {
                flag = true;
            }
            else if (flag && pos.getValue() == num) {
                ec = 0;
            }
            else {
                if (!flag) sc++;
                else ec++;
            }
            pos = pos.getNext();
        }
        if (ec+sc == 0) return -1;
        return ec+sc;
    }

    public static int minDistanceValue(Node<Integer> lst) {
        Node<Integer> pos = lst;
        int num = pos.getValue();
        int minDist = distance(lst, num);
        pos = pos.getNext();
        int temp;
        while (pos != null) {
            temp = distance(lst, pos.getValue());
            if (temp < minDist){
                minDist = temp;
                num = pos.getValue();
            }
            pos = pos.getNext();
        }
        return num;
    }


}   
