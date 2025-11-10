public class Manager extends Employee {
      private float kmult;

      public Manager(float salary, float kmult) {
            super(salary);
            this.kmult = kmult;
      }

      @Override
      public float ComputeSalary() {
            return super.ComputeSalary() * kmult;
      }

      @Override
      public String getName() {
            return "Manager";
      }
}
