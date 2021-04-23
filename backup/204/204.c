/*

Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

 */



// 正确解法
// 一个素数只能被1和它自己整除。如果 i < n,  i<=j<n, 但是  i * j < n 的，那么i就不是小于n的素数

int countPrimes(int n) {
    if (n <= 2) return 0;

    int result = 1;
    bool * check = (bool *)malloc(n * sizeof(bool));

    for (int i = 2; i < n; i++)
    {
        check[i] = true;
    }

    for(int i = 2; i * i < n; i++)
    {
        for (int j = i; i * j < n; j ++)
            check[i * j] = false; // 该位置不是素数
    }

    for (int i = 2; i < n; i++)
    {
        if (check[i]) result ++;
    }
    free(check);
    return result;

}

// 找到所有小于n，大于0的素数
// 什么是素数: 只能被1和自己整除的数字
//

/// 法1 Time Limit Exceeded.
bool isPrimeNum(int n)
{
    for (int i = 2; i*i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) 
    {
        if (isPrimeNum(i))
            count ++;
    }
    return count;
}

/// 法2 使用hashset保存计算过的素数
int g_hashset[1500000] = {0};
int g_count[1500000] = {0};

/// Time Limit Exceeded.
bool isPrimeNum(int n)
{
    if (g_hashset[n] == 1)
        return true;
    else if (g_hashset[n] == -1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) {
            g_hashset[n] = -1;
            return false;
        }
    }
    g_hashset[n] = 1;
    return true;
}

int countPrimes(int n) {
    if(n <= 2) return 0;
    int count = 0;
    if (g_count[n-1] != 0) {
        count = g_count[n-1] + isPrimeNum(n);
        return g_count[n] = count;
    }

    for (int i = 2; i < n; i++) 
    {
        if (isPrimeNum(i))
            count ++;
    }
    return g_count[n] = count;
}

