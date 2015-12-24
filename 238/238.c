
/*

   Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

   For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/


void moveZeroes(int* nums, int numsSize) {

    int nStep = 0;
    int i = 0;
    while(i < numsSize)
    {
        // find first zero
        while(i < numsSize && nums[i] != 0){
            i++;
        }
        if (i >= numsSize)
            return;

        // find first non-zero number
        while(i < numsSize && nums[i] == 0){
            i++;
            nStep++;
        }
        if (i >= numsSize)
            return;

        // move until reach a zero 
        do {
            nums[i- nStep] = nums[i];
            nums[i] = 0;
            i++;
        }while(i < numsSize && nums[i] != 0);

    }
}
