public class SalesEmployee extends Employee implements Sale {
      private float commis;

      public SalesEmployee(float salary, float commis) {
            super(salary);
            this.commis = commis;
      }

      @Override
      public float ComputeSalary() {
            return super.ComputeSalary() * (1 + commis / 100);
      }

      @Override
      public float getCom() {
            return commis;
      }

      @Override
      public String getSaleName() {
            return "SalesEmployee";
      }

      @Override
      public String getName() {
            return "SalesEmployee";
      }
}
