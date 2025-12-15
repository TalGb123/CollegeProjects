package q9;
public class Doctor extends Employee {
      private String specialization;

      public Doctor(String name, String spec) {
            super(name);
            this.specialization = spec;
      }
}