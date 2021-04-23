

// 每个数字出现的次数为 1 2 3 ， 可以使用 2bit 表示 00 01 10 
// 那么状态转换时这样的 00 -> 01 -> 10 -> 00
// 
// 每个数字有32bit， 每个bit的状态也是三个 , 需要使用两个bit来表示
// 使用int firstbits 表示所有数字每个bit状态的第一位
// 使用int secondbits表示所有数字每个bit状态的第二位
//
// 下面需要做的就是怎么模拟状态转换
//
// 如果第一位状态为0，并且当前数字该位置为1时，那么第一位改为1; 如果第一位状态为0，并且当前数字该位置不是1时，继续保持0, 即： firstbits = firstbits ^ A[i]
// 同时， 如果第一位是1, 当第二位相应位置为1时，第一位要变为0,  整理后： firstbits = firstbits ^ A[i] & (~secondbits)
//
// 如果第一位状态为1， 并且第二位状态为0， 同时当前数字该位置为1时，第二位变为1 ; 如果第一位状态为0， 第二位为1， 同时当前数字该位置为1，第二为变为0；
// 总结为： secondbits = secondbits ^ A[i] & (~firstbits)
//
// 最后 firstbits 保存的就是只出现一个的数字


int singleNumber(int A[], int n) {
    int firstbits = 0x0;
    int secondbits= 0x0;

    for (int i = 0; i < n; i++)
    {
        firstbits = firstbits ^ A[i] & (~secondbits);
        secondbits= secondbits^ A[i] & (~firstbits);
    }
    return firstbits;
}



/*
The code seems tricky and hard to understand at first glance. However, if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

    For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

    Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'. Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is calculated later.

Here is another example. If a number appears 5 times at most, we can write a program using the same method. Now we need 3 bits and the loop is 000->100->010->110->001. The code looks like this:

int singleNumber(int A[], int n) {
    int na = 0, nb = 0, nc = 0;
    for(int i = 0; i < n; i++){
        nb = nb ^ (A[i] & na);
        na = (na ^ A[i]) & ~nc;
        nc = nc ^ (A[i] & ~na & ~nb);
    }
    return na & ~nb & ~nc;
}

Or even like this:

int singleNumber(int A[], int n) {
    int twos = 0xffffffff, threes = 0xffffffff, ones = 0;
    for(int i = 0; i < n; i++){
        threes = threes ^ (A[i] & twos);
        twos = (twos ^ A[i]) & ~ones;
        ones = ones ^ (A[i] & ~twos & ~threes);
    }
    return ones;
}

I hope all these above can help you have a better understand of this problem.
*/
