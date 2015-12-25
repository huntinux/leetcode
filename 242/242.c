/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/



bool isAnagram(char* s, char* t) {

    int count[256] = {0};

    char * p = s, * q = t;

    while(*p != '\0')
        count[*p++]++;

    while(*q != '\0')
        if (--count[*q++] < 0)
            return false;

    for(int i = 0; i < 256; i++)
    {
        if(count[i] != 0)
            return false;
    }
    return true;
    
}
