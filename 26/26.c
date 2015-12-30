/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
*/


// 联想 27 , 不同之处在于要删除的元素也是动态变化的, 但是数组是已经排序好的。
int removeDuplicates(int* nums, int numsSize) {

    if (numsSize <= 1) return numsSize;

    int movestep = 0, result = 1, curval = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == curval) 
        {
            movestep ++; 
        }
        else
        {
            nums[i - movestep] = nums[i]; // 移动元素 
            curval = nums[i];             // 更新要删除的元素
            result++;                     // 统计结果长度
        }
    }
    return result;
}

// 做了优化
int removeDuplicates(int* nums, int numsSize) {

    if (numsSize <= 1) return numsSize;

    int movestep = 0, result = 1, curval = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == curval) 
        {
            movestep ++; 
        }
        else
        {
            curval = nums[i];             // 更新要删除的元素
            nums[result++] = curval;      // 移动元素 + 统计结果长度
        }
    }
    return result;
}



int removeDuplicates(int* nums, int numsSize) {

    if (numsSize <= 1) return numsSize;

    int movestep = 0, result = 1, curval = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == curval) 
        {
            movestep ++; 
        }
        else
        {
            nums[result++] = curval = nums[i];      // 更新要删除的元 + 素移动元素 + 统计结果长度
        }
    }
    return result;
}


// best
int removeDuplicates(int* nums, int numsSize) {

    if (numsSize <= 1) return numsSize;

    int result = 1, curval = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != curval) 
        {
            curval = nums[result++] = nums[i];      // 更新要删除的元素 + 移动元素到最终位置 + 统计结果长度
        }
    }
    return result;
}
