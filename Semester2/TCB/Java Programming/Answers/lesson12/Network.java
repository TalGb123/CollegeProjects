public class Network {
    private College[] colleges;

    public Network(College[] colleges) {
        this.colleges = colleges;
    }

    public College[] FitColleges(String majorCode) {
        College[] fitColleges = new College[colleges.length];
        int count = 0;

        for (College college : colleges) {
            for (Major major : college.getMajors()) {
                if (!major.getCode().equals(majorCode) && college.getMajors().length >= 10) {
                    fitColleges[count++] = college;
                    break; 
                }
            }
        }
        College[] result = new College[count];
        System.arraycopy(fitColleges, 0, result, 0, count);
        if (fitColleges.length == 0) {
            return null; 
        }
        return result;
    }
}
