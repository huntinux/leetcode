/*
 *Given an array of integers, every element appears twice except for one. Find that single one.
 */


// 使用异或
int singleNumber(int* nums, int numsSize) {
    int result = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}
