public class HexaConvert {
      public static void main(String[] args) {
            int number = 41981;
            System.out.println(number + " -> " + convertToHex(number));
      }

      public static String convertToHex(int number) {
            if (number == 0) {
                  return "0h";
            }
            String hex = "";
            char[] hexChars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            while (number > 0) {
                  int remainder = number % 16;
                  hex = hexChars[remainder] + hex; 
                  number = number / 16;
            }
            if (hex.charAt(0) >= 'A' && hex.charAt(0) <= 'F') {
                  hex = "0" + hex;
            }
            return hex + "h";
      }
}
