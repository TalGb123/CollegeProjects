import java.util.Stack;

public class MyStack {
      int[] data;
      int topIndex;
      int capacity;

      public MyStack(int size) {
          this.capacity = size;
          this.data = new int[size];
          this.topIndex = -1;
      }

      public MyStack(MyStack other){
            this.capacity = other.capacity;
            this.data = new int[this.capacity];
            this.topIndex = other.topIndex;
            for (int i = 0; i <= other.topIndex; i++) {
                  this.data[i] = other.data[i];
            }
      }

      public void Push(int item){
            if (topIndex == capacity - 1) {
                  capacity += 5;
                  int[] temp = new int[capacity];
                  for (int i = 0; i <= topIndex; i++){
                        temp[i] = data[i];
                  }
                  this.data = temp;
            }
            topIndex++;
            data[topIndex] = item;
      }

      public int Pop() {
            if (IsEmpty()){
                  return -1; 
            }
            int item = data[topIndex];
            topIndex--;
            return item;
      }

      public int Top(){
            if (IsEmpty()){
                return -1;
            }
            return data[topIndex];
      }

      public boolean IsEmpty() {
            return topIndex == -1;
      }

      public void PrintStack() {
            if (IsEmpty()) {
                  System.out.println("Stack is empty.");
                  return;
            }
            MyStack tempStack = new MyStack(this.capacity);
            System.out.print("Stack (top to bottom): ");

            while (!this.IsEmpty()) {
                  int item = this.Pop();
                  System.out.print(item + " ");
                  tempStack.Push(item);
            }
            System.out.println();

            while (!tempStack.IsEmpty()) {
                  this.Push(tempStack.Pop());
            }
      }

      public MyStack GetReverseStack() {
            MyStack rs = new MyStack(this.capacity);
            MyStack temp = new MyStack(this); 
            while (!temp.IsEmpty()) {
                  rs.Push(temp.Pop());
            }
            return rs;
      }

      public MyStack GetMaxStack() {
            MyStack temp = new MyStack(this); 
            MyStack as = new MyStack(this.capacity);
            int maxVal = as.Top();
            while (!temp.IsEmpty()) {
                  int current = temp.Pop();
                  if (current > maxVal) {
                        maxVal = current;
                  }
                  as.Push(current);
            }
            MyStack retS = new MyStack(this.capacity);
            boolean maxSkipped = false; 
            while (!as.IsEmpty()) {
                  int current = as.Pop();
                  if (current == maxVal && !maxSkipped) {
                        maxSkipped = true; 
                  } else {
                        retS.Push(current); 
                  }
            }
            retS.Push(maxVal);
            return retS;
      }

      public MyStack GetEvenStack() {
            if (this.IsEmpty()) return new MyStack(this);
            MyStack temp = this.GetReverseStack();
            MyStack retS = new MyStack(this.capacity);
            for (int i=0; i<temp.capacity; i++){
                  int val = temp.Pop();
                  if (val % 2 == 0){
                        retS.Push(val);
                  }
            }
            return retS;
      }

      public static void main(String[] args) {
            MyStack s = new MyStack(2);
            s.Push(5);
            s.Push(12); 
            s.Push(9);
            s.Push(2);

            System.out.println("--- MyStack Custom Functions ---");
            System.out.print("Original Stack: ");
            s.PrintStack();   

            MyStack rs = s.GetReverseStack();
            System.out.print("Reversed Stack: ");
            rs.PrintStack();
            
            MyStack ms = s.GetMaxStack();
            System.out.print("Max Stack: ");
            ms.PrintStack();

            MyStack es = s.GetEvenStack();
            System.out.print("Even Stack: ");
            es.PrintStack();

            System.out.println("\n--- Comparison with Java Stack ---");

            System.out.println("\n--- MyStack ---");
            MyStack myStack = new MyStack(4);
            myStack.Push(10);
            myStack.Push(20);
            myStack.Push(30);
            System.out.print("Initial state: ");
            myStack.PrintStack();
            System.out.println("Top(): " + myStack.Top());
            System.out.println("Pop(): " + myStack.Pop());
            System.out.print("After Pop(): ");
            myStack.PrintStack();
            System.out.println("IsEmpty(): " + myStack.IsEmpty());

            System.out.println("\n--- Java Stack ---");
            Stack<Integer> javaStack = new Stack<>();
            javaStack.push(10);
            javaStack.push(20);
            javaStack.push(30);
            System.out.println("Initial state (top to bottom): " + javaStack);
            System.out.println("peek(): " + javaStack.peek());
            System.out.println("pop(): " + javaStack.pop());
            System.out.println("After pop(): " + javaStack);
            System.out.println("isEmpty(): " + javaStack.isEmpty());
      }
}
