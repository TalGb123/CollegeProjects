public class Penthouse extends Apartment {
    private double balconySize;

    Penthouse(String name, int floor, double apartmentSize, int roomNum, double balconySize){
        this.setName(name);
        this.setFloor(floor);
        this.setApartmentSize(apartmentSize);
        this.balconySize=balconySize;
        this.setRoomNum(roomNum);
    }

    void setBalconySize(double balconySize){this.balconySize=balconySize;}
    double totalArea(){
        return this.balconySize + this.getApartmentSize();
    }

    @Override
    public String toString() {
        return super.toString() + ;
    }
}
