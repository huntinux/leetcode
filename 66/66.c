/*
   Given a non-negative number represented as an array of digits, plus one to the number.

   The digits are stored such that the most significant digit is at the head of the list.
   */


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int * retdigits = (int *) malloc (digitsSize * sizeof(int));
    memcpy(retdigits, digits, digitsSize * sizeof(int));
    *returnSize = digitsSize; 

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        retdigits[i] += 1;
        if (retdigits[i] == 10)
        {
            retdigits[i] = 0;
            if (i == 0)
            {
                // 需要增加一个空间
                retdigits = (int *)realloc( retdigits, sizeof(int) * (digitsSize + 1));
                for(int j = digitsSize - 1; j >= 0; j --)
                {
                    retdigits[j + 1] = retdigits[j];
                }
                retdigits[0] = 1;
                *returnSize = digitsSize + 1;
            }
        }
        else
        {   
            // 没有进位了，结束程序
            break; 
        }
    }

    return retdigits;
}
