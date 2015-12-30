
uint32_t reverseBits(uint32_t n) {
    int result = 0;
    int count = 32;
    while(count--)
    {
        result = (result * 2) + (n % 2);
        n /= 2;
    }
    return result; 
}

uint32_t reverseBits(uint32_t n) {
    int result = 0;
    int count = 32;
    while(count--)
    {
        result = (result << 2) + (n & 1);
        n >>= 1;
    }
    return result; 
}

