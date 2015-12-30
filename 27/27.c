/*
   Given an array and a value, remove all instances of that value in place and return the new length.

   The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
   */

// 关于移动数组元素的思考：可以动态统计当前元素需要移动的次数，然后一次到位
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;    
    int * p = nums, * end = nums + numsSize;

    while(p < end)
    {
        if (*p == val)
        {
            count++;
        }
        else if (count > 0)
        {
            *(p - count) = *p;
        }
        p++;
    }

    return numsSize - count;
}

// 逆向思维： 只拷贝 != val 的元素。
int removeElement(int* nums, int numsSize, int val) {
    
    int result = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[result++] = nums[i];
        }
    }
    return result;
}

int removeElement(int* nums, int numsSize, int val) {

    int result = 0;
    int * p = nums, * q = nums, * end = nums + numsSize;
    while(p < end)
    {
        if (*p != val)
        {
            *q++ = *p;
        }
        p++;
    }
    return q - nums;
}
