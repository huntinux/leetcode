
class Solution(Object):

    # sort and return n/2
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)/2]

    def majorityElement(self, nums):
        candidate = 0
        count = 0
        for n in nums:
            if count == 0:
                candidate = n
                count = 1
            else:
                if n == candidate:
                    count = count + 1
                else:
                    count = count - 1
        return candidate


    # using hashmap (dict in python is a hashmap)
    def majorityElement(self, nums):
        size = len(nums)
        hashmap = {}
        for n in nums:
            count = hashmap.get(n, 0) + 1;
            if count > size/2:
                return n;
