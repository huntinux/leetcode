class Solution 
{
    public:
        // using hashmap: set int c++ STL
        int digitSqurareSum(int n)
        {
            int result = 0; 
            while(n)
            {
                int d = n % 10;
                result += d * d;
                n /= 10;
            }
            return result;
        }

        int isHappy(int n)
        {
            set<int> s;

            while(true)
            {
                n = digitSqurareSum(n);
                if( !s.insert(n).second )
                    break;
            }
            return n == 1;
        }


        // fast and slow pointer
        bool isHappy(int n) {

            int fast, slow;

            fast = slow = n;
            do {
                slow = digitSqurareSum(slow);
                fast = digitSqurareSum(fast);
                fast = digitSqurareSum(fast);
            }while(fast != slow);
            return fast == 1;
        }
};
