public class Grade {
    private String cid;
    private int s1g;
    private int s2g;

    public Grade(String cid, int s1g, int s2g) {
        this.cid = cid;
        this.s1g = s1g;
        this.s2g = s2g;
    }

    public void setCid(String cid) { this.cid = cid; }
    public void setS1g(int s1g) { this.s1g = s1g; }
    public void setS2g(int s2g) { this.s2g = s2g; }

}
