public class Worker {
      private String id;
      private int status; 
      private int basic; 
      private int extra; 

      public Worker(String id, int status) 
      {
            this.id = id;
            this.status = status;
            this.basic = 0;
            this.extra = 0;
      } 

      public double getSalary() 
      {
            switch (this.status) {
                  case 1:
                        return this.basic * 90 + this.extra * 100;
                  case 2:
                        return this.basic * 50 + this.extra * 100;
                  default:
                        return -1; 
            }
      }

      public void input() {
            java.util.Scanner sc = new java.util.Scanner(System.in);
            int totalMinutes = 0;
            this.basic = 0;
            this.extra = 0;

            for (int i = 0; i < 3; i++) {
                  System.out.print("Enter start time (HH:mm): ");
                  String startTime = sc.nextLine();
                  System.out.print("Enter end time (HH:mm): ");
                  String endTime = sc.nextLine();

                  try {
                        int startHour = Integer.parseInt(startTime.substring(0, 2));
                        int startMin = Integer.parseInt(startTime.substring(3, 5));
                        int endHour = Integer.parseInt(endTime.substring(0, 2));
                        int endMin = Integer.parseInt(endTime.substring(3, 5));

                        int totalStart = startHour * 60 + startMin;
                        int totalEnd = endHour * 60 + endMin;
                        int diff = totalEnd - totalStart;

                        if (diff < 0) {
                              System.out.println("Invalid time range. Please try again.");
                              i--;
                              continue;
                        }

                        totalMinutes += diff;

                        int hoursWorked = diff / 60;
                        int minsWorked = diff % 60;
                        System.out.println("Worked: " + hoursWorked + " hours and " + minsWorked + " minutes.");

                        // Calculate basic and extra hours for this day
                        if (hoursWorked > 8) {
                              this.basic += 8;
                              this.extra += (hoursWorked - 8);
                        } else {
                              this.basic += hoursWorked;
                        }

                  } catch (Exception e) {
                        System.out.println("Invalid input format. Please use HH:mm.");
                        i--;
                  }
            }

            int totalHours = totalMinutes / 60;
            int totalMins = totalMinutes % 60;
            System.out.println("Total worked in 3 days: " + totalHours + " hours and " + totalMins + " minutes.");
      }

      public static void PrintAll(Worker[] workers) {
            int totalEng = 0;
            int totalWork = 0;
            for (Worker worker : workers) {
                  if (worker == null) continue;
                  int totalHours = worker.basic + worker.extra;
                  System.out.println("ID: " + worker.id + ", Time Worked: " + totalHours + " hours, Salary: " + worker.getSalary());
                  if (worker.status == 1) {
                        totalEng += worker.getSalary();
                  } else if (worker.status == 2) {
                        totalWork += worker.getSalary();
                  }
            }
            System.out.println("Total Salary for Engineers: " + totalEng);
            System.out.println("Total Salary for Workers: " + totalWork);
      }     
}
