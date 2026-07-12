public class ForeignCurrency {
    private String name;
    private Node<Double> rates;

    public ForeignCurrency(String name, double val) {
        this.name = name;
        this.rates.setValue(val);
    }

    public String getName() {
        return name;
    }

    public Node<Double> getRates() {
        return rates;
    }

    public void addRate(double rate) {
        Node<Double> curr = new Node<>(rate);
        curr.setNext(rates);
        rates = curr;
    }

    public boolean recordRate() {
        if (rates == null) return false;
        double val = rates.getValue();
        Node<Double> temp = rates.getNext();
        while (temp != null) {
            if (temp.getValue() > val) {
                return false;
            }
            temp = temp.getNext();
        }
        return true;
    }

    public boolean worthInvest() {
        if (recordRate()) return false;
        Node<Double> temp = rates.getNext();
        double val = rates.getValue();
        for (int i=0; i<4; i++) {
            if (temp.getValue() >= val) {
                return false;
            }
            val = temp.getValue();
            temp = temp.getNext();
        }
        return true;
    }
}
