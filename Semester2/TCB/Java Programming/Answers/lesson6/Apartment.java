public class Apartment {
    private String name;
    private int floor;
    private double apartmentSize;
    private double roomNum;

    Apartment(String name, int floor, double apartmentSize, int roomNum){
        this.name = name;
        this.floor = floor;
        this.apartmentSize = apartmentSize;
        this.roomNum = roomNum;
    }
    Apartment(){
        this.name = "tal";
        this.floor = 1;
        this.apartmentSize = 111;
        this.roomNum = 3;
    }
    void setName(String name){this.name=name;}
    void setFloor(int floor){this.floor=floor;}
    void setApartmentSize(double apartmentSize){this.apartmentSize=apartmentSize;}
    void setRoomNum(int roomNum){this.roomNum=roomNum;}
    double getApartmentSize() { return this.apartmentSize;}

    double totalArea() {
        return this.apartmentSize;
    }

    @Override
    public String toString() {
        return getClass().getSimpleName() + " total area: " + totalArea();
    }
}
