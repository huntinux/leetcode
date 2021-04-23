/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
*/


// memcpy : 不能处理overlap的情况，但是memmove可以, 详见man page
// memcpy, memmove 是以字节为单位的！如果以int为单位，需要 *sizeof(int)
void show(int * arr, int size)
{
    for (int i = 0; i < size; i ++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
void rotate(int* nums, int numsSize, int k) {

    int realk = k % numsSize;
    if (realk == 0) return;
    printf("realk = %d\n", realk);

    int sec1len = numsSize - realk;
    int sec2len = realk;
    
    int * sectmp = (int * ) malloc ( sec2len * sizeof (int));
    //show(nums, numsSize);
    memcpy(sectmp, nums + sec1len, sec2len * sizeof(int));
    //show(sectmp, sec2len);
    memmove(nums + realk, nums, sec1len * sizeof(int));
    //show(nums, numsSize);
    memcpy(nums, sectmp, sec2len * sizeof(int));
    //show(nums, numsSize);
    
    free(sectmp);
}

