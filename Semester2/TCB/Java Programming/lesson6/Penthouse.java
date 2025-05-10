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
    
    @Override
    double totalArea(){
        return this.getApartmentSize() + this.balconySize;
    }
}
