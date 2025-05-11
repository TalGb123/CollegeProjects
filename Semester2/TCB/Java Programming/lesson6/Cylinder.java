public class Cylinder extends Circle {
    private double height;

    Cylinder(double height){
        this.height = height;
        this.setRadius(1.0);
    }

    Cylinder(double radius, double height){
        this.setRadius(radius);
        this.height = height;
    }

    Cylinder(){
        this.height = 1.0;
        this.setRadius(1.0);
    }

    Cylinder(double radius, double height, String color){
        this.height = height;
        this.setRadius(radius);
        this.setColor(color);
    }

    void setHeight(double height){ this.height = height;}
    double getHeight() {return this.height;}

    double getVolume(){
        return this.getArea() * height;
    }


}
