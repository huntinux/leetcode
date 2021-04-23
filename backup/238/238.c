
/*
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question
*/

// 动态规划
// 状态：
// left[i]  0,1,..,i-1 的元素的乘积
// right[i] i+1,...,n 的元素的乘积
// result[i] 位置为i的结果
// 递推关系
// left[i] = nums[i-1] * left[i-1]
// right[i]= nums[i+1] * right[i+1]
// result[i] = left[i] * right[i]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int * left  = (int *)calloc(numsSize, sizeof(int));
    int * right = (int *)calloc(numsSize, sizeof(int));
    int * result= (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    left[0] = 1;
    for(int i = 1; i < numsSize; i++)
    {
        left[i] = nums[i-1] * left[i-1];
    }

    right[numsSize-1] = 1;
    for(int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = nums[i + 1] * right[i+1];
    }

    for(int i = 0; i < numsSize; i++)
    {
        result[i] = left[i] * right[i];
    }
    free(left);
    free(right);
    return result;
}
