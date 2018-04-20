/*
 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:

    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/


//一些测试用例：
// ececabbacec true
// cupuupucu   true


class Solution {
public:

    bool validPalindrome(string str) {
        const char* s = str.c_str();
        if (!s) return true;

        int chance = 1;
        int len = strlen(s);
        int low = 0, high = len - 1;
        while (low < high) {
            char l = (s[low]), h = (s[high]);
            if (l != h)
            {
                char l1 = (s[low+1]), h1 = (s[high-1]);
                char l2 = (s[low+2]), h2 = (s[high-2]);
                if (chance != 0) {
                    chance--;
                    if (l1 != h && l != h1) {
                        return false;
                    }
                    if (l1 == h && l == h1) {
                        if (l2 != h1) {
                            low++;
                            high -= 2;
                        } else {
                            low += 2;
                            high -= 1;
                        }
                    } else if (l1 == h) {
                        low += 2; high--;
                    } else if (l == h1) {
                        high -= 2; low++;
                    } else {
                        return false;
                    }

                } else {
                    return false;
                }
            }
            else { low++; high--; }

        }
        return true;
    }

};

class Solution {
public:

    bool validPalindrome(string str) {
        const char* s = str.c_str();
        if (!s) return true;

        int chance = 1;
        int len = strlen(s);
        int low = 0, high = len - 1;
        while (low < high) {
            if (!isalnum(s[low])) low++;
            else if (!isalnum(s[high])) high--;
            else if (tolower(s[low]) != tolower(s[high])) {
                if (chance != 0) {
                    chance--;
                    if (tolower(s[low+1]) != tolower(s[high]) &&
                        tolower(s[low]) != tolower(s[high-1])) {
                        return false;
                    }
                    if (tolower(s[low+1]) == tolower(s[high]) &&
                        tolower(s[low]) == tolower(s[high-1])) {
                        if (tolower(s[low+2]) != tolower(s[high - 1])) {
                            low++;
                            high -= 2;
                        } else {
                            low += 2;
                            high -= 1;
                        }
                    } else if (tolower(s[low+1]) == tolower(s[high])) {
                        low += 2; high--;
                    } else if (tolower(s[low]) == tolower(s[high-1])) {
                        high -= 2; low++;
                    } else {
                        return false;
                    }

                } else {
                    return false;
                }

            } else { low++; high--; }
        }
        return true;
    }

};
