public class Client {
    private String fname;
    private String sname;
    private int age;
    private int gender;
    private int payment;
    private int days;

    public Client(String fname, String sname, int age, int gender, int payment,
                  int days){
        this.fname=fname;
        this.sname=sname;
        this.age=age;
        this.gender=gender;
        this.payment=payment;
        this.days=days;
    }
    public Client(Client other){
        this.fname=other.fname;
        this.sname=other.sname;
        this.age=other.age;
        this.gender=other.gender;
        this.payment=other.payment;
        this.days=other.days;
    }

    public double Pay(double dollar){
        double total= this.payment*dollar*40*1.18;
        if (this.age < 21){
            total = total*1.2;
        }
        return total;
    }

    public double Discount(){
        int discount=0;
        if (this.age >= 40){
            discount+=50;
        }
        if (this.payment==1){
            discount+=20;
        }
        else if (this.payment==2){
            discount+=10;
        }
        return discount;
    }

    public String Print(){
        return "[" + this.fname + " " + this.sname + " " + this.age + " " + this.gender + "]";
    }
}
