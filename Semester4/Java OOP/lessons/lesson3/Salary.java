public class Salary {
      public static void main(String[] args) {
            Employee e = new Employee(5000);
            SalesEmployee se = new SalesEmployee(5000, 10);
            Manager m = new Manager(5000, 1.5f);
            SalesManager sm = new SalesManager(5000, 1.5f, 10);

            Employee[] employees = {e, se, m, sm};

            for (Employee emp : employees) {
                  System.out.println(emp.getName() + " salary: " + emp.ComputeSalary());
            }
      }
}
