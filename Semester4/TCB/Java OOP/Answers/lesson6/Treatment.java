public class Treatment {
      private Doctor doctor;
      private Animal animal;
      private String description;

      public Treatment(Doctor doctor, Animal animal, String description) {
            this.doctor = doctor;
            this.animal = animal;
            this.description = description;
      }

      public Doctor getDoctor() { return doctor; }
      public Animal getAnimal() { return animal; }
      public String getDescription() { return description; }
}
