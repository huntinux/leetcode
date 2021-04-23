/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/


int stoi(const char * start, const char * end)
{
    int result = 0;
    while(start < end)
        result = result * 10 + *start++ - '0';
    return result;
}

int compareVersion(char* version1, char* version2) {

    int pos1, pos2;
    pos1 = pos2 = 0;

    char * p, * q, * r, * s;
    p = q = version1;
    r = s = version2;

    while (true)
    {
        while( *q != '.' && *q != '\0')
            q++;
        pos1 = stoi(p, q);

        while( *s != '.' && *s != '\0')
            s++;
        pos2 = stoi(r, s);
        
        if (pos1 > pos2) return 1;
        else if(pos1 < pos2) return -1;
        else 
        {
            if (*q == '\0' && *s == '\0')
                return 0;
        }

        if ( *q == '.' )
        {
            p = ++q;
        }
        else
        {
            p = q;
        }
 
        if ( *s == '.' )
        {
            r = ++s;
        }
        else
        {
            r = s; // *s = *r = '\0';
        }
    }

}

// 错误解法，因为有可能包含多个'.'
int compareVersion(char* version1, char* version2) {

    int ver1high, ver1low, ver2high, ver2low;

    sscanf(version1, "%d.%d", &ver1high, &ver1low);
    sscanf(version2, "%d.%d", &ver2high, &ver2low);

    printf("ver1high=%d, ver1low=%d\n", ver1high, ver1low);
    printf("ver2high=%d, ver2low=%d\n", ver2high, ver2low);

    if (ver1high > ver2high) return 1;
    else if (ver1high < ver2high) return -1;
    else if (ver1low > ver2low) return 1;
    else if (ver1low < ver2low) return -1;
    else return 0;
}
