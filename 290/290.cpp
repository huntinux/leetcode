/*
   Given a pattern and a string str, find if str follows the same pattern.

   Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/

// hashmap


class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            map<char, string> dict;
            map<string, char> dictReverse;
            stringstream values(str);
            char k;
            string v;
            for(int i = 0; i < pattern.length(); i++)
            {
                // get key, value
                k = pattern[i];
                if( !(values >> v) ) return false;

                if (dict.find(k) != dict.end())
                {
                    if (v != dict[k])
                        return false;
                }
                else
                {
                    if (dictReverse.find(v) != dictReverse.end())
                        return false;
                    dict.insert(make_pair(k,v));
                    dictReverse.insert(make_pair(v,k));
                }
            }
            
            return values.eof();
        }
};

