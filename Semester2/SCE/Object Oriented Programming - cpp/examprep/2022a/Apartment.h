class Apartment {
      private:
            int apartmentNum;
            int floor;
            double territorySize;
      public:
            Apartment(int apartmentNum, int floor, double territorySize);
            Apartment();
            ~Apartment();
            virtual int getPrice();
            virtual void printApp();

            int Apartment::getApartmentNum() {
                  return apartmentNum;
            }

            int Apartment::getFloor() {
                  return floor;
            }

            double Apartment::getTerritorySize() {
                  return territorySize;
            }
};