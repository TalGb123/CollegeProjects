class College {
    private String name;
    private String location;
    private Major[] majors; 

    public College(String name, String location, Major[] majors) {
        this.name = name;
        this.location = location;
        this.majors = majors;
    }

    public String getName() {
        return name;
    }

    public String getLocation() {
        return location;
    }

    public Major[] getMajors() {
        return majors;
    }
}