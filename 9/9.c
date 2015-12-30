
bool isPalindrome(int x) {

    if (x < 0) return false;
    int low, high;
    int len = 0;

    int n = x;
    while(n) {
        n/=10;
        len++;
    }

    int i = 0, j = len -1;
    while(j > i)
    {
        low = x / (int)pow(10, i) % 10;
        high= x / (int)pow(10, j) % 10;
        if (low != high)
            return false;
        i++; j--;
    }
    return true;
    
}

// 优化
bool isPalindrome(int x) {

    if (x < 0) return false;
    int low, high;
    int len = 0;

    int n = x;
    while(n) {
        n/=10;
        len++;
    }

    int lowdivider = 1;
    int highdivider= pow(10, len-1);
    while(highdivider > lowdivider)
    {
        low = x / lowdivider % 10;
        high= x / highdivider % 10;
        if (low != high)
            return false;
        lowdivider *= 10;
        highdivider/=10;
    }
    return true;
    
}

// 优化 2
bool isPalindrome(int x) {

    if (x < 0) return false;
    int low, high;

    int lowdivider = 1;
    int highdivider= 1;
    int n = x;
    while(n/10) {
        n/=10;
        highdivider *= 10;
    }

    while(highdivider > lowdivider)
    {
        low = x / lowdivider % 10;
        high= x / highdivider % 10;
        if (low != high)
            return false;
        lowdivider *= 10;
        highdivider/=10;
    }
    return true;
    
}



// 另外一种思路
// 逆序生成这个数字，看是否和原来的数字相同
// 但是效率不如上面的算法
bool isPalindrome(int x) {
    if (x < 0) return false;
    int y = 0;
    int t = x;

    while(t)
    {
        y = y * 10 + t % 10;
        if (y > x) return false;
        t /=10;
    }
    return y == x;
}

