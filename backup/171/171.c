
/*
 Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 */

// 8ms
int titleToNumber(char* s) {
    int sum = 0;
    while(*s)
    {
        sum *= 26;
        sum += *s++ - 'A' + 1;
    }
    return sum; 
}

// 4ms
int titleToNumber(char* s) {
    int sum = 0;
    int dict[256] = {0};
    for(int i = 'A'; i <= 'Z'; i++)
    {
        dict[i] = i - 'A' + 1;
    }
    while(*s)
    {
        sum *= 26;
        sum += dict[*s++];
    }
    return sum; 
}

// ms
int dict['Z' + 1] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,  //0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};
int titleToNumber(char* s) {
    int sum = 0;
//    int dict[256] = {0};
//    for(int i = 'A'; i <= 'Z'; i++)
//    {
//        dict[i] = i - 'A' + 1;
//    }
//    for(int i = 0; i < 256; i++)
//    {
//        printf("%3d,", dict[i]);
//        if ((i + 1) % 16 == 0)
//            printf("\n");
//    }

    while(*s)
    {
        sum *= 26;
        sum += dict[*s++];
    }
    return sum; 
}
