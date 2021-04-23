public class Solution {
    private int digitSquareSum(int n)
    {
        int result = 0; 
        while(n != 0)
        {
            int t = n % 10;
            result += t * t;
            n /= 10;
        }
        return result;

    }
    public boolean isHappy(int n) {

        HashSet<Integer> hashset = new HashSet<Integer>();
        while(true)
        {
            n = digitSquareSum(n);
            if (!hashset.add(n))
                break;
        }
        return n == 1;

    }    


    public boolean isHappy(int n) {
        int fast, slow;

        fast = slow = n;
        do {
            slow = digitSqurareSum(slow);
            fast = digitSqurareSum(fast);
            fast = digitSqurareSum(fast);
        }while(fast != slow);
        return fast == 1;
    }

}
