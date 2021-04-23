/*************************************************************************
	> File Name: 80.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月03日 星期三 09时48分29秒
 ************************************************************************/

// 80. Remove Duplicates from Sorted Array II
/*Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>

// v1
// current_value记录当前的数值
// current_count记录当前数值的出现次数
// output_index表示下一个输出位置
int removeDuplicates(int* nums, int numsSize) {

    if(numsSize <= 2) return numsSize;

    int current_value = nums[0];
    int current_count = 1;
    int output_index = 1;

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == current_value)
        {
            if(current_count != 2)
            {
                current_count++;
                nums[output_index++] = nums[i]; // 输出
            }
            else
            {
                // 出现次数大于2，不输出该值
                continue;
            }
        }
        else
        {
            // 与当前值不同，重新计数
            current_count = 1;
            current_value = nums[i];
            nums[output_index++] = nums[i]; // 输出
        }
    }
    return output_index;
}

// v2 : 什么时候可以输出呢？ 1. 与前面元素不同  2. 与前面相同但是与后面不同
// 逆向思维：什么时候不输出  1. 与前后都相同时
// not fast but simple
int removeDuplicates(int* nums, int numsSize) {
    int index = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(i > 0 && i < numsSize - 1  // 保证索引有效性
                && nums[i] == nums[i-1] && nums[i] == nums[i+1])
            continue;

        nums[index++] = nums[i];
    }
    return index;
}

int main()
{
    return 0;
}

