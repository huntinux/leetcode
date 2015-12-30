/*
   Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

   For example:

   Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * 首先将所有数字进行XOR，假设要找到的两个数字分别为a和b， 那么得到的结果为 a^b = c (根据异或的性质， 重复出现两次的数字被去掉了)
 * c的二进制中是1的就是说a 和 b 该位置不一样。可以利用这个位置，将数组分成两组。
 * 对两组再次进行异或，得到结果就是 a 和 b
 */


typedef bool (*pFunc)(int num);

void showarr(const int * start, const int * end)
{
    while(start <= end)
    {
        printf("%d,", *start++);
    }
    printf("\n");
}

int xorsum(const int * start, const int * end)
{
    if (start == NULL || end == NULL)
        return 0;

    int result = 0;
    while(start <= end)
        result ^= *start++;
    return result; 
}

int getmask(int val)
{
    int pos = 0;
    while( (val & (1 << pos)) == 0)  // 找到二进制中左边第一个为1的位置
        pos++;
    return (1 << pos);
}

int mask = 1;
bool testbit(int val)
{
    return val & mask;
}

bool testpositive(int val)
{
    return val > 0;
}

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// 根据mask，将数组分成两部分，与一趟快速排序相同
// 非常好用的函数，可以根据函数func的返回值，将数组分成两部分。
int divide(int * nums, int numsSize, pFunc func)
{
    int low = 0, high = numsSize - 1; 

    while(low < high)
    {
        while(low < high && func(nums[high])) high--;
        while(low < high && !func(nums[low])) low++;
        if (low < high) {
            //swap(nums + low, nums + high);
            //int tmp    = nums[low];
            //nums[low]  = nums[high];
            //nums[high] = tmp;
            int tmp = nums[low] ^ nums[high];
            nums[low]  = nums[high];
            nums[high] = tmp ^ nums[low];
            
        }
    }
    return high; // 返回分界位置
}

int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int * retval = (int *) malloc (2 * sizeof(int));
    int ret1 = xorsum(nums, nums + numsSize - 1); // ret1 = a ^ b
    mask = getmask(ret1); // 得到a 与 b 左边起，第一个不同的位置(二进制)
    int edge = divide(nums, numsSize, testbit); // 根据mask， 将数组分成两组
    retval[0] = xorsum(nums, nums + edge); // 对两组分别求xorsum， 既可以得到最终结果
    retval[1] = xorsum(nums + edge + 1, nums + numsSize-1);
    *returnSize = 2;
    return retval;
}

// 优化
int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int * retval = (int *) malloc (2 * sizeof(int));
    int ret1 = xorsum(nums, nums + numsSize - 1); // ret1 = a ^ b
    //mask = getmask(ret1); // 得到a 与 b 左边起，第一个不同的位置(二进制)
    mask = (ret1 & (ret1 - 1)) ^ ret1; // nice idear : trick： n & (n-1) 能够去掉最后面的一个1.
    int edge = divide(nums, numsSize, testbit); // 根据mask， 将数组分成两组
    if (edge < numsSize / 2) {
        retval[0] = xorsum(nums, nums + edge); 
        retval[1] = ret1 ^ retval[0];
    }
    else{
        retval[1] = xorsum(nums + edge + 1, nums + numsSize-1);
        retval[0] = ret1 ^ retval[1];
    }
    *returnSize = 2;
    return retval;
}

// 优化
int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int * retval = (int *) calloc (2 * sizeof(int), 1);
    int ret1 = xorsum(nums, nums + numsSize - 1); // ret1 = a ^ b
    //mask = getmask(ret1); // 得到a 与 b 左边起，第一个不同的位置(二进制)
    mask = (ret1 & (ret1 - 1)) ^ ret1; // nice idear : trick： n & (n-1) 能够去掉最后面的一个1.

    int * p = nums;
    while(p < nums + numsSize)
    {
        if(testbit(*p)) 
            retval[0] ^= *p;
        else 
            retval[1] ^= *p;
        p++;
    }
    *returnSize = 2;
    return retval;
}


// 优化
int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int * retval = (int *) calloc (2 * sizeof(int), 1);

    int ret1 = 0;
    int * p = nums;
    while(p < nums + numsSize)
        ret1 ^= *p;

    mask = (ret1 & (ret1 - 1)) ^ ret1; // nice idear : trick： n & (n-1) 能够去掉最后面的一个1.

    p = nums;
    while(p < nums + numsSize)
    {
        if(testbit(*p)) 
            retval[0] ^= *p;
        else 
            retval[1] ^= *p;
        p++;
    }
    *returnSize = 2;
    return retval;
}


// 优化
int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int * retval = (int *) calloc (2 * sizeof(int), 1);

    int ret1 = 0;
    int * p = nums;
    while(p < nums + numsSize)
        ret1 ^= *p;

    mask = (ret1 & (ret1 - 1)) ^ ret1; // nice idear : trick： n & (n-1) 能够去掉最后面的一个1.
    p = nums;
    while(p < nums + numsSize)
    {
        if(*p & mask) 
            retval[0] ^= *p;
        else 
            retval[1] ^= *p;
        p++;
    }
    *returnSize = 2;
    return retval;
}





/*
   Once again, we need to use XOR to solve this problem. But this time, we need to do it in two passes:

   In the first pass, we XOR all elements in the array, and get the XOR of the two numbers we need to find. Note that since the two numbers are distinct, so there must be a set bit (that is, the bit with value '1') in the XOR result. Find out an arbitrary set bit (for example, the rightmost set bit).

   In the second pass, we divide all numbers into two groups, one with the aforementioned bit set, another with the aforementinoed bit unset. Two different numbers we need to find must fall into thte two distrinct groups. XOR numbers in each group, we can find a number in either group.

Complexity:

Time: O (n)

Space: O (1)

*/
