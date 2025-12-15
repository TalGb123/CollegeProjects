public class Parent {
      protected double x;
      protected String name;
      private String lastName; 
      public static int year = 2021;

      public Parent(double x, String name) {
            this.x = x;
            this.name = name;
      }

      public Parent(double x, String name, String lastName) {
            this.x = x;
            this.name = name;
            this.lastName = lastName;
      }

      public String getLastName() {
            return this.lastName;
      }

      public int method() {
            return 0; 
      }

      public double calculate(double d) {
            return d;
      }

      public void print() {
            System.out.println("Parent");
      }
}