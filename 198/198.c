
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Subscribe to see which companies asked this question
*/

// 动态规划
// 1. 归纳问题 , 对状态进行抽象
// 2. 总结出状态的递推公式

// 1. maxmoney[i] 表示 到达i，最大的收益
// 2. maxmoney[i] = max( maxmoney[i-2] + nums[i], maxmoney[i-1])

int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    //if (numsSize == 2) return max(nums[0], nums[1]);

    int result = 0;
    int * maxmoney = (int *)calloc(numsSize, sizeof(int));
    maxmoney[0] = nums[0];
    maxmoney[1] = max(nums[0], nums[1]);
    result = maxmoney[1];
    for (int i = 2; i < numsSize; i++)
    {
        maxmoney[i] = max(maxmoney[i-2] + nums[i], maxmoney[i-1]);
        if (maxmoney[i] > result)
            result = maxmoney[i];
    }

    free(maxmoney);
    return result;
}
