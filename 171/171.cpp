class Solution {
    public:
        // 14ms
        int titleToNumber(string s) {
            int result = 0;
            for (int i = 0; i < s.length(); i++)
            {
                result = result * 26 + s[i] - 'A' + 1;
            }
            return result;
        }

        // 8ms
        int titleToNumber(string s) {
            const char * p = s.c_str();
            int result = 0;
            while(*p)
            {
                result = result * 26 + *p++ - 'A' + 1;
            }
            return result;
        }

        // 8ms
        int titleToNumber(string &s) {
            const char * p = s.c_str();
            int sum = 0;
            int dict[256] = {0};
            for(int i = 'A'; i <= 'Z'; i++)
            {
                dict[i] = i - 'A' + 1;
            }
            while(*p)
            {
                sum *= 26;
                sum += dict[*p++];
            }
            return sum; 
        }

        // 8ms
        int titleToNumber(string &s) {
            char * p = const_cast<char *>(s.c_str()); // 使用const_cast 去掉const属性
            //char * p = (char *)s.c_str();
            // char * p = s.c_str();
            int sum = 0;
            int dict[256] = {0};
            for(int i = 'A'; i <= 'Z'; i++)
            {
                dict[i] = i - 'A' + 1;
            }
            while(*p)
            {
                sum *= 26;
                sum += dict[*p++];
            }
            return sum; 
        }

};
