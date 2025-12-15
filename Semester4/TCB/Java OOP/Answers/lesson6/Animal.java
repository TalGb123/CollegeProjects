import java.util.ArrayList;

public class Animal {
      private static int counter = 0;

      protected int serial;
      protected String owner;
      protected String breed;
      protected ArrayList<Treatment> treatments;

      public Animal(String owner, String breed) {
            this.serial = ++counter;
            this.owner = owner;
            this.breed = breed;
            this.treatments = new ArrayList<>();
      }

      public int getSerial() { return serial; }
      public String getOwner() { return owner; }
      public String getBreed() { return breed; }

      public void addTreatment(Treatment t) {
            treatments.add(t);
      }

      public ArrayList<Treatment> getTreatments() {
            return treatments;
      }

      public String getType() {
            return "Animal";
      }
}
