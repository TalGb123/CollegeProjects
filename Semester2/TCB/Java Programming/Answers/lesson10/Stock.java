public class Stock {
      private FoodItem[] stock;
      private int numOfItems;

      public Stock() {
            this.stock = new FoodItem[100];
            this.numOfItems = 0;
      }

      public int howMany(int temp){
            if (numOfItems == 0) {
                  return 0;
            }
            int count = 0;
            for (int i=0; i<numOfItems; i++) {
                  if (stock[i].getMinTemperature() >= temp) {
                        count += stock[i].getQuantity();
                  }
            }
            return count;
      }

      public void removeAfterDate(Date today) {
            for (int i = 0; i < numOfItems; i++) {
                  if (!stock[i].isFresh(today)) {
                        stock[i] = stock[numOfItems - 1];
                        numOfItems--;
                        i--; 
                  }
            }
      }
}
