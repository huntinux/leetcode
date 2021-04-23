public class Solution {
    public boolean isPalindrome(String s) {
        String lowerStr = s.toLowerCase();
        int i = 0, j = s.length() - 1;

        while(i < j)
        {
            if (! isAlphanumeric(lowerStr.charAt(i)))  i++;
            else if (! isAlphanumeric(lowerStr.charAt(j))) j--;
            else if ( lowerStr.charAt(i) != lowerStr.charAt(j)) return false;
            else {i++; j--;}
        }

        return true;
    }
}
