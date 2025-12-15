public class Bird extends Animal {
      private String color;

      public Bird(String owner, String breed, String color) {
            super(owner, breed);
            this.color = color;
      }

      @Override
      public String getType() {
            return "Bird";
      }
}
