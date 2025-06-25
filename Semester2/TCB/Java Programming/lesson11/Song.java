class Song {
    private String name;
    private String performer;
    private int length;

    public Song(String name, String performer, int length) {
        this.name = name;
        this.performer = performer;
        this.length = length;
    }

    public String Status() {
        return this.performer + "/" + this.name + ":" + this.length;
    }
}