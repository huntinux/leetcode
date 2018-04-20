
/**
 * string to lower
 *      left - right
 *
 */


bool isPalindrome(String s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = prev(s.end());
    while(left < right)
    {
        if(!::isalnum(*left)) left++;
        else if(!::isalnum(*right)) right--;
        else if(*left != *right) return false;
        else {left++; right--;}
    }
    return true;
}



// 要熟悉STL中算法的运用，这里使用了transform, prev
// STL算法和迭代器结合使用

class Solution {
public:

    /*
    bool isPalindrome(string str) {
        const char* s = str.c_str();
        if (!s) return true;

        int len = strlen(s);
        int low = 0, high = len - 1;
        while (low < high) {
            if (!isalnum(s[low])) low++;
            else if (!isalnum(s[high])) high--;
            else if (tolower(s[low]) != tolower(s[high])) return false;
            else { low++; high--; }
        }
        return true;
    }
    */

    bool isPalindrome(string s) {
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto low = s.begin(), high = prev(s.end());
        while (low < high) {
            char l = *low;
            char h = *high;
            if (!::isalnum(l)) low++;
            else if (!::isalnum(h)) high--;
            else if (::tolower(l) != ::tolower(h)) return false;
            else { low++; high--; }
        }
        return true;
    }
    /*
    bool isPalindrome(string s) {
        if (s.empty()) return true;

        int low = 0, high = s.length() - 1;
        while(low < high) {
            if (!isalnum(s[low])) {
                low++;
                continue;
            }
            if (!isalnum(s[high])) {
                --high;
                continue;
            }
            if (tolower(s[low]) != tolower(s[high]))
                return false;
            low++;
            --high;
        }
        return true;
    }
    */
};

