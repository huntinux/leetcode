/*
f[i] 表示以i结尾的最大子序列之和
f[i+1] = max(f[i] + a[i+1], a[i+1])
f[i]中最大的就是结果
*/

int maxSubArray(int* nums, int numsSize) {
    //if(!nums || numsSize <= 0) return 0;
    
    int f, result;
    f = result = nums[0];
    
    for(int i = 1; i < numsSize; i++)
    {
        f = max(f + nums[i], nums[i]);
        if(f > result) result = f;
    }
    
    return result;
}

//[−2,1,−3,4,−1,2,1,−5,4]
