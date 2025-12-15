import java.util.ArrayList;

public class Doctor {
      private String id;
      private String name;
      private ArrayList<String> specialties;

      public Doctor(String id, String name, ArrayList<String> specialties) {
            this.id = id;
            this.name = name;
            this.specialties = specialties;
      }

      public String getName() { return name; }

      public void treat(Animal a, String description) {
            String type = a.getType().toLowerCase();
            if (!specialties.contains(type)) {
                  System.out.println("Doctor " + name + " cannot treat this type of animal.");
                  return;
            }
            Treatment t = new Treatment(this, a, description);
            a.addTreatment(t);
      }
}
