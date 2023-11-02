package algo;

public class BruteForceStringMatch {
    public static void main(String[] args) {
        String string = "ABCABAB ABABABAABAC";
        String pattern = "ABABAABA";

        stringSearch(string, pattern);
    }

    // Brute-force string search method
    private static void stringSearch(String string, String pattern) {
        int sLen = string.length();
        int pLen = pattern.length();
        boolean found = false;
        int i;
        for(i = 0; i < sLen - pLen + 1; i++) {
            int j = 0;
            for (; j < pLen; j++) {
                if (string.charAt(i + j) != pattern.charAt(j))
                    break;
            }
            if (j == pLen) {       // If we have reached end of pattern, we have found the pattern in string
                found = true;
                break;
            }
        }
        if (found) {
            System.out.println("Found pattern at index: " + i);
        } else {
            System.out.println("Could not find pattern");
        }
    }
}

