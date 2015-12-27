/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
 */



/**
 * 有可能陷入循环。如何判断一个数值已经存在了呢？ 可以使用hashmap，快速判断一个数值是否存在
 * 法1： hashmap
 *
 * 联想一个问题：单向链表中存在环的判断。用两个指针。
 * “环” 和 循环 是一样的，如果存在环，就退出，可以避免进入死循环。
 * 法2：快慢指针
 */

int digitSqurareSum(int n)
{
    int result = 0; 
    while(n)
    {
        int d = n % 10;
        result += d * d;
        n /= 10;
    }
    return result;
}

bool isHappy(int n) {

    int fast, slow;

    fast = slow = n;
    do {
        slow = digitSqurareSum(slow);
        fast = digitSqurareSum(fast);
        fast = digitSqurareSum(fast);
    }while(fast != slow);
    if(slow == 1) return true;
    else return false;
    
}
