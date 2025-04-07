public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public Time(Time other) {
        this.hour = other.hour;
        this.minute = other.minute;
        this.second = other.second;
    }

    public int GetHour() {
        return hour;
    }
    public int GetMinute() {
        return minute;
    }
    public int GetSecond() {
        return second;
    }
    public void SetHour(int hour) {
        if (hour < 24) {
            this.hour = hour;
        }
    }
    public void SetMinute(int minute) {
        if (minute < 60) {
            this.minute = minute;
        }
    }
    public void SetSecond(int second) {
        if (second < 60) {
            this.minute += second;
        }
    }
    public String Print() {
        return String.format("%02d:%02d:%02d", hour, minute, second);
    }

}
