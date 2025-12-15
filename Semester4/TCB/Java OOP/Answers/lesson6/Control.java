import java.util.ArrayList;

public class Control {
      private ArrayList<Doctor> doctors = new ArrayList<>();
      private ArrayList<Animal> animals = new ArrayList<>();

      public void addDoctor(Doctor d) {
            doctors.add(d);
      }

      public void addAnimal(Animal a) {
            animals.add(a);
      }

      public void printAnimalsOfDoctor(String doctorName) {

            ArrayList<Animal> printed = new ArrayList<>(); 

            for (Animal a : animals) {
                  for (Treatment t : a.getTreatments()) {
                        if (t.getDoctor().getName().equals(doctorName)) {
                              boolean alreadyPrinted = false;
                              for (Animal x : printed) {
                                    if (x.getSerial() == a.getSerial()) {
                                          alreadyPrinted = true;
                                          break;
                                    }
                              }
                              if (!alreadyPrinted) {
                                    System.out.println(a.getType() + " #" + a.getSerial());
                                    printed.add(a);
                              }
                        }
                  }
            }
      }
}
