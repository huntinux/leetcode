/*
   Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

   For example,
   "A man, a plan, a canal: Panama" is a palindrome.
   "race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/

// 判断是否为回文

bool isPalindrome(char* s) {

    if (s == NULL || s[0] == '\0') return true;

    const char * head, * tail;
    head = tail = s;

    while( *(tail + 1) != '\0')
        tail++;

    while(head < tail)
    {
        if ( !isalnum(*head) ) head++;
        else if ( !isalnum(*tail) ) tail--;
        else if ( tolower(*head) != tolower(*tail) ) return false;
        else { head++; tail--; }
    }
    return true;
}
