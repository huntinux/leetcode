

class Solution {

    // 每次删除两个不同的元素，剩下的就是结果
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

    // 先排序，然后返回n/2处的元素
    int majorityElement(vector<int> & nums)
    {
        // sort, then return [n/2]
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

};
