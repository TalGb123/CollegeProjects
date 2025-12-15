package q9;

public class Supervisor extends Doctor {
      private Employee[] arr;
      private int current;

      public Supervisor(String name, String spec) {
            super(name, spec);
            this.arr = new Employee[10];
            this.current = 0;
      }

}