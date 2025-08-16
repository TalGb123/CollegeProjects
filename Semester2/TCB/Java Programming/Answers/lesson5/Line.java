public class Line {
    Point p1;
    Point p2;

    public Line(Point p1, Point p2){
        this.p1 = p1;
        this.p2 = p2;
    }

    public Line(int x1, int x2, int y1, int y2){
        this.p1.x = x1;
        this.p1.y = y1;
        this.p2.x = x2;
        this.p2.y = y2;
    }

    public Point GetP1(){
        return this.p1;
    }

    public Point GetP2(){
        return this.p2;
    }

    private double computeA() {
        if (this.p2.x == this.p1.x) {
            return 0;
        }
        return (double)(this.p2.y - this.p1.y) / (this.p2.x - this.p1.x);
    }

    private double computeB() {
        double a = computeA();
        return this.p1.y - a * this.p1.x;
    }

    public String getEquation() {
        double a = computeA();
        double b = computeB();
        if (a == 0) {
            return "y = " + b;
        }
        return "y = " + a + "x + " + b;
    }

    public double distance() {
        return Math.sqrt(Math.pow(this.p2.x - this.p1.x, 2) + Math.pow(this.p2.y - this.p1.y, 2));
    }
}
