public class GroundAp extends Apartment {
    private double gardenSize;
    private boolean diffEntry;

    GroundAp(String name, double apartmentSize, int roomNum, boolean diffEntry, double gardenSize){
        this.diffEntry=diffEntry;
        this.gardenSize=gardenSize;
        this.setName(name);
        this.setFloor(1);
        this.setApartmentSize(apartmentSize);
        this.setRoomNum(roomNum);
    }

    boolean getDiffEntry(){return this.diffEntry;}
    double getGardenSize(){return this.gardenSize;}

    @Override
    double totalArea(){
        return this.getApartmentSize() + this.gardenSize;
    }
}
