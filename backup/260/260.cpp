
class Solution
{
    public:
        vector<int> singleNumber(vector<int>& nums)
        {
            vector<int> result;
            int a = 0, b = 0;

            int xorsum= 0;
            vector<int>::const_iterator it;
            for ( it = nums.begin(); it < nums.end(); it++)
            {
                xorsum^= *it; 
            }

            int mask = (xorsum & (xorsum - 1)) ^ xorsum;
            for ( it = nums.begin(); it < nums.end(); it++)
            {
                if ( *it & mask )
                    a ^= *it;
                else
                    b ^= *it;
            }
            result.insert(a);
            result.insert(b);
            return result;
        }


};
