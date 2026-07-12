public class Data{
      private boolean free;
      private int size;
      //constructor
      public Data (int size) {
            this.free = true;
            this.size = size;
      }
      public boolean isFree(){ return free; }
      public int getSize() { return size; }
      public void setFree(boolean free){this.free = free; }
      public void setSize(int size){ this.size = size;}
}