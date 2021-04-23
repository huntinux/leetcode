
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

// 暴力解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if (len2 == 0) return 0;
        if (len1 < len2) return -1;
        for (int i = 0; i < len1; ++i) {
            if ((len1 - i) < len2) return -1;
            int j, k;
            for (j = i, k = 0; j < len1 && k < len2; ++j, ++k) {
                if (haystack[j] != needle[k]) break;
            }
            if (k == len2) return i;
        }
        return -1;
    }
};

//
// 其他算法KMP： http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
// 此算法值得理解思想
