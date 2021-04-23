

class Solution {

    // ÿ��ɾ��������ͬ��Ԫ�أ�ʣ�µľ��ǽ��
    int majorityElement(vector<int> & nums)
    {
        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)    
            {
                candidate = nums[i];
                count = 1;
            }
            else
            {
                if (nums[i] == candidate) 
                {
                    count++;
                }
                else
                {
                    count--;
                }

            }

        }
        return candidate;

    }

    // ������Ȼ�󷵻�n/2����Ԫ��
    int majorityElement(vector<int> & nums)
    {
        // sort, then return [n/2]
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

};
