public class FoodItem {
      private String name;
      private int quantity;
      private Date productionDate;
      private Date expirationDate;
      private int minTemperature;
      private int maxTemperature;
      private double price;

      public FoodItem(String name, int quantity, Date productionDate, Date expirationDate, int minTemperature, int maxTemperature, double price) {
            this.name = name;
            this.quantity = quantity;
            this.productionDate = productionDate;
            this.expirationDate = expirationDate;
            this.minTemperature = minTemperature;
            this.maxTemperature = maxTemperature;
            this.price = price;
      }

      public boolean isFresh(Date today) {
            return productionDate.Before(today) && expirationDate.Before(today);
      }

      public int howManyItems(double money) {
            int enoughMoney = (int)(money / price);
            if (enoughMoney < this.quantity) {
                  return enoughMoney;
            } 
            return quantity;
      }

      public int getMinTemperature() {
            return minTemperature;
      }

      public int getMaxTemperature() {
            return maxTemperature;
      }

      public int getQuantity() {
            return quantity;
      }
}
