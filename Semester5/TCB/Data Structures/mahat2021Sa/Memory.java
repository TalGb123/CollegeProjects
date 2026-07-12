public class Memory {
      private Node<Data> start;
      public Memory(int totalSize) {
            this.start = new Node<>(new Data(totalSize));
      }

      public boolean dangerousState() {
            Node<Data> temp = start;
            int totalSize = 0;
            int usedSize = 0;
            while (temp != null) {
                  totalSize += temp.getValue().getSize();
                  if (!temp.getValue().isFree()) {
                        usedSize += temp.getValue().getSize();
                  }
                  temp = temp.getNext();
            }
            return (double) usedSize >= (double) totalSize * 0.9;
      }

      public boolean firstFit(int num) {
            Node<Data> temp = start;
            while (temp != null) {
                  if (temp.getValue().isFree() && temp.getValue().getSize() >= num) {
                        temp.getValue().setFree(false);
                        if (this.dangerousState()) {
                              temp.getValue().setFree(true);
                              return false;
                        }
                        int memLeft = temp.getValue().getSize() - num;
                        temp.getValue().setSize(num);
                        if (memLeft > 0) {
                              Node<Data> next = temp.getNext();
                              temp.setNext(new Node<>(new Data(memLeft)));
                              temp.getNext().setNext(next);
                        }
                        return true;
                  }
                  temp = temp.getNext();
            }
            return false;
      }
}
