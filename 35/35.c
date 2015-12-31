/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*/


// 二分查找，思想虽然简单，但是能够写对，需要仔细
int searchInsert(int* nums, int numsSize, int target) {
    
    int low = 0, high = numsSize - 1;


    while(low <= high)
    {
        int index = (low + high)/2;
        if (nums[index] == target)
        {
            return index;
        }
        else if (nums[index] > target)
        {
            high = index - 1;
        }
        else
        {
            low = index + 1;
        }
    }
    return low;
}


int searchInsert(int* nums, int numsSize, int target) {
    
    int low = 0, high = numsSize - 1;

    while(low <= high)
    {
        int index = (low + high)/2;
        if (nums[index] > target)
        {
            high = index - 1;
        }
        else if(nums[index] < target)
        {
            low = index + 1;
        }
        else
        {
            return index;
        }
    }
    return low;
}
