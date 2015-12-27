public class Solution {
    // 3ms: using toCharArray
    public int titleToNumber(String s) {
        char[] charr = s.toCharArray();
        int sum = 0;
        for(int i = 0; i < charr.length; i++)
        {
            sum *= 26;
            sum += charr[i] - 'A' + 1; 
        }
        return sum;

    }

    // 3ms
    private static int[] dict = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
    };

    public int titleToNumber(String s) {

        char[] charr = s.toCharArray();

        int sum = 0;
        for(int i = 0; i < charr.length; i++)
        {
            sum *= 26;
            sum += dict[charr[i]]; 
        }
        return sum;

    }


    // 2ms best: using charAt
    public int titleToNumber(String s) {

        int result = 0;
        for (int i = 0; i < s.length(); result = result * 26 + (s.charAt(i) - 'A' + 1), i++);
        return result;
    }
}
