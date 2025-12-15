package q9;
public class Nurse extends Employee {
      private String type;

      public Nurse(String name, String type) {
            super(name);
            this.type = type;
      }
      
      public String getType() { return type; }
}