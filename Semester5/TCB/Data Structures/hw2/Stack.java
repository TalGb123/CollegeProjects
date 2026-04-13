public class Stack<T> {
    private T[] storage;
    private int topIndex;
    private int currentCapacity;

    public Stack() {
        this.currentCapacity = 4;
        this.topIndex = -1;
        this.storage = (T[]) new Object[currentCapacity];
    }

    public void push(T item) {
        if (topIndex == currentCapacity - 1) {
            grow();
        }
        storage[++topIndex] = item;
    }

    public T pop() {
        T item = storage[topIndex];
        storage[topIndex] = null;
        topIndex--;
        return item;
    }

    public T top() {
        return storage[topIndex];
    }

    private void grow() {
        int newCapacity = currentCapacity * 2;
        T[] newStorage = (T[]) new Object[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            newStorage[i] = storage[i];
        }
        this.storage = newStorage;
        this.currentCapacity = newCapacity;
        System.out.println("LOG: Stack expanded to " + newCapacity);
    }

    public boolean isEmpty() {
        return topIndex == -1;
    }

    public int size() {
        return topIndex + 1;
    }
}

