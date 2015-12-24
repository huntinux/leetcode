
#include <stdio.h>
#include <limits.h>


// use bitmap : 0-not exist 1-exist
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize < 2) return false;
    
    unsigned char bitarr[1500000];

    memset(bitarr,0,sizeof(bitarr));
    for(int i = 0; i < numsSize; i++)
    {
        int n = nums[i];
        int whichByte = n/8;
        int bitInByte = n%8;
        unsigned char mask = (1U << bitInByte);
        if ((bitarr[whichByte] & mask) == 0)
        {
            bitarr[whichByte] |= mask;
        }
        else
        {
            return true;
        }

    }

    return false;
}


int main()
{
    //int count = 0;
    //for(int i = INT_MIN; i <= INT_MAX; i++)
    //{
    //    if(count++ < 10) 
    //        printf("i = %u, %d\n", i, i);
    //    else
    //        break;
    //}

    bool result = false;
    unsigned int bitnum = (2<<32);
    unsigned char * bitarr = malloc(bitnum/8);

    for(int i = 0; i < numsSize; i++)
    {
        unsigned int index = nums[i];
        unsigned int whichByte = nums[i]/8;
        unsigned int locInByte = nums[i]%8;
        if (bitarr[whichByte] & (1<<locInByte) == 0)
        {
            bitarr[whichByte] |= (1<<locInByte);
        }
        else
        {
            result = true;
            break;
        }

    }

    free(bitarr);
    return result;
}
