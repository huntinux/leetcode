

import java.util.HashMap;
import java.util.Iterator;

public class Solution {

    // count array

    public boolean isAnagram(String s, String t) {

        int slen = s.length(), tlen = t.length();
        if(slen != tlen) return false;
        int[] count = new int[256];
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        for(int i  = 0; i < slen; i++) count[sarr[i]] ++;
        for(int i  = 0; i < tlen; i++) if (--count[tarr[i]] < 0) return false;
        for(int c : count) if (c!= 0) return false;
        return true;
    }

    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        int[] count = new int[26];
        for(int i  = 0; i < s.length(); i++) count[s.charAt(i) - 'a'] ++;
        for(int i  = 0; i < t.length(); i++) if (count[t.charAt(i) - 'a'] -- < 0) return false;
        for(int c : count) if (c!= 0) return false;
        return true;
    }

    public boolean isAnagram(String s, String t) {
        int[] count = new int[26];
        for(int i  = 0; i < s.length(); i++) count[s.charAt(i) - 'a'] ++;
        for(int i  = 0; i < t.length(); i++) count[t.charAt(i) - 'a'] --;
        for(int c : count) if (c!= 0) return false;
        return true;
    }

    

    // using HashMap
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
        char[] charArr = s.toCharArray();

        for (int i = 0; i < charArr.length; i++)
        {
            
            if(hashMap.containsKey(charArr[i]))
            {
                int count = hashMap.get(charArr[i]);
                count ++;
                hashMap.put(charArr[i], count);
            }
            else
            {
                hashMap.put(charArr[i], 1);
            }

        }

        char[] charArrT = t.toCharArray();
        for(int i = 0; i < charArrT.length; i++)
        {
            if(hashMap.containsKey(charArrT[i]))
            {
                int count = hashMap.get(charArrT[i]);
                count --;
                if(count < 0)
                    return false;
                else
                    hashMap.put(charArrT[i], count);
            }
            else
            {
                return false;

            }

        }

        Iterator it = hashMap.values().iterator();
        while(it.hasNext())
        {
           if((it.next()) != (Integer)0) 
               return false;
        }
        return true;
    }

    public static void main(String[] args)
    {
        Solution slt = new Solution();
        boolean result = slt.isAnagram("a", "b");
        System.out.println(result);
    }
}
