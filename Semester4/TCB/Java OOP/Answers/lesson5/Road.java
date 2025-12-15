public class Road {
      private final Junction start;
      private final Junction end;
      private final double length;

      public Road(Junction start, Junction end) {

            if (start == end) {
                  end = new Junction();  
                  System.out.println(
                        "Road can not connect a junction to itself, the end junction has been replaced with " 
                        + end.toString().replace(" at Point", "")
                  );
            }
            this.start = start;
            this.end = end;
            this.length = start.CalcDistance(end);

            start.GetExitingRoads().add(this);
            end.GetEnteringRoads().add(this);

            System.out.printf("Creating Road from %s to %s, length: %.2f\n", start, end, length);
      }

      public Junction GetStart() { return start; }
      public Junction GetEnd() { return end; }
      public double GetLength() { return length; }

      @Override
      public String toString() {
            return "Road from " + this.start + " to " + this.end;
      }
}
