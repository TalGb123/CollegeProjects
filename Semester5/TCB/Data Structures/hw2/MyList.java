public class MyList<T> {
    private Node<T> first;

    public MyList() {
        first = null;
    }

    public MyList(T val) {
        first = new Node<T>(val);
    }

    public T getFirst() {
        if (first == null) {
            return null;
        }
        return first.getValue();
    }

    public Node<T> getLastNode() {
        if (first == null) {
            return null;
        }
        Node<T> temp = first;
        while (temp.hasNext()) {
            temp = temp.getNext();
        }
        return temp;
    }

    public T getLast() {
        if (first == null) {
            return null;
        }
        return getLastNode().getValue();
    }

    public Node<T> getIndexNode(int index) {
        if (index < 0 || first == null) {
            return null;
        }
        Node<T> temp = first;
        for (int i=0; i<index; i++) {
            temp = temp.getNext();
            if (temp == null) return null;
        }
        return temp;
    }

    public T getIndex(int index) {
        Node<T> temp = getIndexNode(index);
        if (temp == null) return null;
        return temp.getValue();
    }

    public void insertFirst(T val) {
        Node<T> nf = new Node<T>(val);
        nf.setNext(first);
        first = nf;
    }

    public void insertLast(T val) {
        Node<T> nl = new Node<T>(val);
        Node<T> last = getLastNode();
        if (last == null) first = nl; 
        else last.setNext(nl); 
    }

    public void insertAt(int index, T val) {
        if (index == 0) {
            insertFirst(val);
            return;
        }
        Node<T> ni = new Node<>(val);
        Node<T> gi = getIndexNode(index - 1);
        if (gi == null) return;
        Node<T> gin = gi.getNext();
        gi.setNext(ni);
        ni.setNext(gin);
    }

    public T removeFirst() {
        if (first == null) return null;
        Node<T> second = first.getNext();
        T fval = first.getValue();
        first = second;
        return fval;
    }

    public T removeLast() {
        if (first == null || !first.hasNext()) return null;
        if (!first.hasNext()) {
            T val = first.getValue();
            first = null;
            return val;
        }
        Node<T> prev = first;
        Node<T> curr = first.getNext();
        while (curr.hasNext()) {
            prev = curr;
            curr = curr.getNext();
        }
        prev.setNext(null);
        return curr.getValue();
    }

    public T removeIndex(int index) {
        if (index < 0 || first == null) return null;
        if (index == 0) return removeFirst();
        Node<T> prev = getIndexNode(index - 1);
        if (prev == null || !prev.hasNext()) return null;
        Node<T> target = prev.getNext();
        prev.setNext(target.getNext());
        return target.getValue();
    }

    public boolean contains(T value) {
        if (first == null) return false;
        Node<T> temp = first;
        while (temp.hasNext()) {
            if (temp.getValue() == value) return true;
            else temp = temp.getNext();
        }
        return false;
    }

    public void reverse() {
        Node<T> temp = null;
        Node<T> newList = null; 
		while (first != null){
			temp = first; 
			first = first.getNext(); 
			temp.setNext(newList); 
			newList = temp; 
		}
		first = newList; 
    }
}


