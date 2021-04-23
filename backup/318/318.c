/*
 Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:

Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words. 
*/

// 如何判断两个字符串有没有公共字母
// 想法： 对于每一个字符串，有一个hashmap，key为字符串中的字母, value为该字母有没有出现过
// 那么比对两个字符串的hashmap是否一样即可。
// 但是如果使用常规的hashmap，那么比对hashmap的过程也是一层循环。
//
// 题目指出，字符串只包含小写字母，那么总共26个。 并且字符串内部没有重复字母
// 可以使用一个int(32bits)模拟hash。
// 相应比特0：表示没有出现，1表示出现了。
// 查看是否有相同元素： &
// 那么比对hashmap是否相同可以直接使用 '=='


// 36ms， 击败了所有解法
int hash(const char * str)
{
    int result = 0;
    while(*str) result |= (1 << (*str++ - 'a')); 
    return result;
}

bool haveCommonChar(int hasha, int hashb)
{
    return hasha & hashb != 0;
}

int maxProduct(char** words, int wordsSize) {

    int result = 0;
    int * strhash = (int *) calloc (wordsSize, sizeof(int));
    int * strlens = (int *) calloc (wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) 
    {
        strhash[i] = hash(words[i]);
        strlens[i] = strlen(words[i]);
        //printf("%s,hash=%d,len=%d\n", words[i], strhash[i], strlens[i]);
    }

    for (int i = 0; i < wordsSize; i ++)
    {
        //for (int j = 0; j < wordsSize; j ++)
        for (int j = i + 1; j < wordsSize; j ++)
        {
            //if (i != j && ((strhash[i] & strhash[j]) == 0))
            if ((strhash[i] & strhash[j]) == 0)
            {
                int product = strlens[i] * strlens[j];
                if (product > result)
                    result = product;
            }
        }
    }

    free(strhash);
    free(strlens);
    return result;
}
