import java.util.ArrayList;

public class Main {
      public static void main(String[] args) {
            Control control = new Control();

            ArrayList<String> d1Specialties = new ArrayList<>();
            d1Specialties.add("dog");
            d1Specialties.add("cat");

            ArrayList<String> d2Specialties = new ArrayList<>();
            d2Specialties.add("bird");

            Doctor d1 = new Doctor("111", "Dr. Cohen", d1Specialties);
            Doctor d2 = new Doctor("222", "Dr. Levy", d2Specialties);

            control.addDoctor(d1);
            control.addDoctor(d2);

            Dog dog1 = new Dog("Amit", "Labrador", true);
            Cat cat1 = new Cat("Dana", "Persian", false);
            Bird bird1 = new Bird("Noa", "Parrot", "Green");

            control.addAnimal(dog1);
            control.addAnimal(cat1);
            control.addAnimal(bird1);

            d1.treat(dog1, "Vaccination for dog");
            d1.treat(cat1, "Nails trimming");

            d1.treat(bird1, "Beak cleaning");

            d2.treat(bird1, "Wing treatment");

            d2.treat(bird1, "General health check");

            System.out.println("\nAnimals treated by Dr. Cohen:");
            control.printAnimalsOfDoctor("Dr. Cohen");

            System.out.println("\nAnimals treated by Dr. Levy:");
            control.printAnimalsOfDoctor("Dr. Levy");
      }
}
