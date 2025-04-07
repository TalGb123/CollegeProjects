public class Main {
    public static void AsciiCounter(String str) {
        int chCounter = 0;
        int numCounter = 0;
        int symCounter = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                chCounter++;
            }
            else if (c >= '0' && c <= '9') {
                numCounter++;
            }
            else {
                symCounter++;
            }
        }
        System.out.println("Amount of chars: " + chCounter);
        System.out.println("Amount of digits: " + numCounter);
        System.out.println("Amount of symbols: " + symCounter);
    }

    public static String StarReplacer(String str) {
        StringBuilder newStr = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c >= '0' && c <= '9') {
                int numStars = Character.getNumericValue(c);
                for (int j = 0; j < numStars; j++) {
                    newStr.append("*");
                }
            }
            else {
                newStr.append(c);
            }
        }
        return newStr.toString();
    }

    public static void SenStarter(String str, char ch) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                System.out.println(str.substring(i));
            }
        }
    }

    public static int TwoDigNum(String str){
        for (int i=0; i<str.length()-1; i++){
            if (str.charAt(i) >= '0' && str.charAt(i) <= '9' && str.charAt(i+1) >= '0' && str.charAt(i+1) <= '9'){
                return 10 * Character.getNumericValue(str.charAt(i)) + Character.getNumericValue(str.charAt(i+1));
            }
        }
        return -1;
    }

    public static String OddSpot(String str){
        String result = "";
        int start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '*') {
                String sub = str.substring(start, i);
                if (sub.length() % 2 == 1) {
                    int middleIndex = sub.length() / 2;
                    result += sub.charAt(middleIndex);
                }
                start = i + 1;
            }
        }
        String lastSub = str.substring(start);
        if (lastSub.length() % 2 == 1) {
            int middleIndex = lastSub.length() / 2;
            result += lastSub.charAt(middleIndex);
        }
        return result;
    }

    public static void main(String[] args) {
        String ex1 = "C+2A<3N321C2aaa";
        String ex2 = "a2b3";
        String ex3 = "Java is a good language!";
        String ex4 = "1sdc23qe";
        String ex5 = "abc*nssj*x*abc*aaaaa";
        //AsciiCounter(ex1);
        //System.out.println(StarReplacer(ex2));
        //SenStarter(ex3, 'a');
        //System.out.println(TwoDigNum(ex4));
        //System.out.println(OddSpot(ex5));

    }
}
