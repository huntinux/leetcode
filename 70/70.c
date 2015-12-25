

int climbStairs(int n)
{
    int p = 0, q = 1, r = 0, i = 1;

    while(i <= n) 
    {
        r = p + q;
        p = q;
        q = r;
        i++;
    }

    return r; 
}
