public class Main {
      public static void main(String[] args) {
            Queue<Integer> q = new Queue<>();
            q.enqueue(2);
            q.enqueue(5);
            q.enqueue(5);
            q.enqueue(7);
            q.enqueue(2);
            q.enqueue(4);
            q.enqueue(1);
            q.enqueue(3);
            q.enqueue(2);
            q.enqueue(5);
            q.enqueue(5);
            q.enqueue(1);
            System.out.println("Original Queue: " + q);
            Queue<Integer> dupes = onlyDupes(q);
            System.out.println("Duplicates: " + dupes);
      }

      public static <T> boolean contains(Queue<T> q, T item) {
            boolean found = false;
            int currentSize = q.size();
            for (int i = 0; i < currentSize; i++) {
                  T val = q.dequeue();
                  if (val.equals(item)) {
                        found = true;
                  }
                  q.enqueue(val);
            }
            return found;
      }

      public static <T> int countOccurrences(Queue<T> q, T item) {
            int count = 0;
            int currentSize = q.size();
            for (int i = 0; i < currentSize; i++) {
                  T val = q.dequeue();
                  if (val.equals(item)) {
                        count++;
                  }
                  q.enqueue(val);
            }
            return count;
      }

      public static <T> Queue<T> onlyDupes(Queue<T> q) {
            Queue<T> dupes = new Queue<>();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                  T item = q.dequeue();
                  q.enqueue(item);
                  
                  if (countOccurrences(q, item) >= 3 && !contains(dupes, item)) {
                        dupes.enqueue(item);
                  }
            }
            return dupes;
      }

      public static void fixDatabase(GradesFile gf) {
            for (int i = 0; i < 100; i++) {
                  while (!gf.listIsGood(i)) {
                        Student currentStudent = gf.getStudent(i);
                        int targetIndex = currentStudent.getCode();
                        gf.moveStudent(i, targetIndex);
                  }
            }
      }
}
