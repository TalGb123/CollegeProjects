class TrickTrack
{
    private Node<String> drivers;
    private Node<Integer> cars;
    private Node<Payment>[] payments;

    public TrickTrack(Node<String> drivers, Node<Integer> cars, Node<Payment>[] payments) {
        this.drivers = drivers;
        this.cars = cars;
        this.payments = payments;
    }

    public Node<String> getDrivers() {
        return drivers;
    }

    public Node<Integer> getCars() {
        return cars;
    }

    public Node<Payment>[] getPayments() {
        return payments;
    }

    public boolean existDriver(String name) {
        Node<String> current = drivers;
        while (current != null) {
            if (current.getValue().equals(name)) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

    public boolean existCar(int num) {
        Node<Integer> current = cars;
        while (current != null) {
            if (current.getValue() == num) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

    public boolean worked(String name, int day) {
        if (day < 0 || day >= payments.length) {
            return false;
        }
        Node<Payment> current = payments[day]; 
        while (current != null) {
            Payment payment = current.getValue();
            if (payment.getName().equals(name)) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

    public boolean addPayment(int day, int num, String name, double fuel) {
        if (day < 1 || day > 30) {
            return false;
        }
        if (!this.existDriver(name)) {
            return false;
        }
        if (!this.existCar(num)) {
            return false;
        }
        if (fuel < 0) {
            return false;
        }
        Payment newPayment = new Payment(name, num, fuel);
        Node<Payment> newNode = new Node<>(newPayment);
        newNode.setNext(this.payments[day]);
        this.payments[day] = newNode;
        return true;
    }

    public double totalFuel(int num) {
        double total = 0.0;
        for (int i = 1; i <= 30; i++) {
            Node<Payment> current = this.payments[i];
            while (current != null) {
                Payment p = current.getValue();
                if (p.getNum() == num) {
                    total += p.getFuel();
                }
                current = current.getNext();
            }
        }
        return total;
    }

    public void printWorkDays() {
        Node<String> currentDriver = this.drivers;
        while (currentDriver != null) {
            String driverName = currentDriver.getValue();
            int workDaysCount = 0;
            for (int day = 1; day <= 30; day++) {
                if (this.worked(driverName, day)) {
                    workDaysCount++;
                }
            }
            System.out.println("Driver: " + driverName + " worked " + workDaysCount + " days.");
            currentDriver = currentDriver.getNext();
        }
    }
}

