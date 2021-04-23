
// 二分查找，利用已经排序好这个性质，每次排除一些不可能的元素。
// low，high，mid
// 如果nums[mid] > nums[high] 那么结果在右边(不包含mid) low = mid + 1
// 如果nums[mid] < nums[high] 那么结果在左边（包含mid） high = mid 
// 如果nums[mid] = nums[high] 那么结果不能确定在哪边, 但是可以将nums[high]删除 high = high - 1 
int findMin(int* nums, int numsSize) 
{
    int low = 0, high = numsSize - 1, mid = 0;

    while(low < high)
    {
        mid = (low + high) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high -= 1;
    }

    return nums[low];
}

