public class Action {
    private String name;

    public Action(String name) {
        this.name = name;
    }

    public boolean Equals(Object other) {
        if (other == null || !other.getClass().equals(this.getClass())){
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return name;
    }
}
