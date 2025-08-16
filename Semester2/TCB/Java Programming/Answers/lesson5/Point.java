public class Point {
    int x;
    int y;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public Point(Point p){
        this.x = p.x;
        this.y = p.y;
    }

    public int GetX() {
        return this.x;
    }

    public int GetY() {
        return this.y;
    }

    public void SetX(int x) {
        this.x = x;
    }

    public void SetY(int y) {
        this.y = y;
    }

    public boolean Equals(Point other){
        return this.x == other.x && this.y == other.y;
    }

    @Override
    public String toString(){
        return "(" + Integer.toString(this.x) + ", " + Integer.toString(this.y) + ")";
    }
}
