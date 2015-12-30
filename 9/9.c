
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

// �Ż�
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

// �Ż� 2
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



// ����һ��˼·
// ��������������֣����Ƿ��ԭ����������ͬ
// ����Ч�ʲ���������㷨
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

