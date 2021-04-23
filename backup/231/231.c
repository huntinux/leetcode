
//Given an integer, write a function to determine if it is a power of two.

// 只有一个1
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return n & (n - 1)  == 0;
}


// 联想，统计一个数字的二进制中 1的个数
// n = n & (n-1)  会去掉n中的一个1
