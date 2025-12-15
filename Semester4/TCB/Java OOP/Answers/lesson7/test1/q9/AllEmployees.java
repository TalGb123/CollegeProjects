package q9;
public class AllEmployees {
    private Employee[] arr;
    private int current;

      public AllEmployees() {
            this.arr = new Employee[200];
            this.current = 0;
      }

      public int numSupervisor() {
            int count = 0;
            for (int i = 0; i < current; i++) {
                  if (this.arr[i] instanceof Supervisor) {
                        count++;
                  }
            }
            return count;
      }

      public Nurse getNewNurse(String type) {
            for (int i = current - 1; i >= 0; i--) {
                  if (this.arr[i] instanceof Nurse) {
                        Nurse n = (Nurse) this.arr[i];
                        if (n.getType().equals(type)) {
                              return n;
                        }
                  }
            }
            return null;
      }
}