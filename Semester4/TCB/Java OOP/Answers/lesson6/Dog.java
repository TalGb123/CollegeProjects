public class Dog extends Animal {
      private boolean needsMuzzle;

      public Dog(String owner, String breed, boolean needsMuzzle) {
            super(owner, breed);
            this.needsMuzzle = needsMuzzle;
      }

      @Override
      public String getType() {
            return "Dog";
      }
}
