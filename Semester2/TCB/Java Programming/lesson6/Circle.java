public class Circle {
    private double radius;
    private String color;

    Circle(double radius, String color){
        this.radius = radius;
        this.color = color;
    }

    Circle(double radius){
        this.radius = radius;
        this.color = "red";
    }

    Circle() {
        this.radius = 1.0;
        this.color = "red";
    }

    String getColor() {return this.color;}
    double getRadius() {return this.radius;}
    void setColor(String color) {this.color = color;}
    void setRadius(double radius) {this.radius = radius;}

    double getArea(){
        return radius * 2 * 3.14;
    }

    String ToString(){
        return "Circle[radius=" + this.radius + ",color=" + this.color + "]";
    }


}
