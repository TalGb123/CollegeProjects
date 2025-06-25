public class Time {
    private int hours;
    private int minutes;

    public Time(int hours, int minutes) {
        this.hours = hours;
        this.minutes = minutes;
    }

    public boolean before(Time t) {
        if (this.hours < t.hours) {
            return true;
        } else if (this.hours == t.hours) {
            return this.minutes < t.minutes;
        }
        return false;
    }

    public int getHours() {
        return this.hours;
    }

    public int getMinutes() {
        return this.minutes;
    }
}
