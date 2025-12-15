public class Cat extends Animal {
      private boolean nailSubscription;

      public Cat(String owner, String breed, boolean nailSubscription) {
            super(owner, breed);
            this.nailSubscription = nailSubscription;
      }

      @Override
      public String getType() {
            return "Cat";
      }
}
