public class mahat2025s2 {
    public static boolean IsProperK(Stack<Integer> st, int k) {
        Stack<Integer> s2 = new Stack<>();
        boolean streak = false;
        boolean broke = false;
        boolean res = true;
        int num, fn;
        int count = 0;
        while (!st.isEmpty()) {
            num = st.pop();
            s2.push(num);
            fn = num;
            while (fn / 10 > 0) {
                fn /= 10;
            }
            if (fn == k && !streak && !broke) {
                streak = true;
                count++;
            }
            else if (fn == k && streak) count++;
            else if (fn != k && streak && !broke) broke = true;
            else if (fn == k && broke) res = false;
        }
        while (!s2.isEmpty()) st.push(s2.pop());
        if (count > 1 && res) return true;
        return false;
    }
}
