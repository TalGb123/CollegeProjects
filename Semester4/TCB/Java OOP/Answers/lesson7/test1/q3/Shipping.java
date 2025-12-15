package q3;
public class Shipping {
      private String address;
      private Object[] arr;

      public Shipping(String address, int capacity) {
            this.address = address;
            this.arr = new Object[capacity];
      }

      public double sum() {
            double total = 0;
            for (int i = 0; i < this.arr.length; i++) {
                  if (this.arr[i] != null) {
                        if (this.arr[i] instanceof Clothes) {
                              total += ((Clothes) this.arr[i]).getPrice();
                        } 
                        else if (this.arr[i] instanceof Book) {
                              total += ((Book) this.arr[i]).getPrice();
                        }
                  }
            }
            return total;
      }
}