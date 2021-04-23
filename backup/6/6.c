
/*

   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R

   And then read line by line: "PAHNAPLSIIGYIR"

   Write the code that will take a string and make this conversion given a number of rows:

   string convert(string text, int nRows);

   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 


 */


#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * convert( char * s, int nRows)
{
	if(!s) return NULL;

	int nLen = strlen(s);
	if (nRows == 1 || nRows >= nLen) return s;

	char * buff = (char *)malloc(nLen + 1);
	if(!buff) 
	{
		return NULL;	
	}
	else
	{
		buff[nLen] = '\0';
	}

	int nStepSum = (nRows - 1) * 2;
	const char * p = NULL;
	const char * pStrEnd = s + nLen;
	char * q = buff;
	int nStep1, nStep2;
	nStep1 = nStep2 = 0;
	for (int i = 0; i < nRows ; i++) 
	{
		if (i == 0 || i == (nRows - 1))
		{
			nStep1 = nStep2 = nStepSum;
		}
		else
		{
			nStep2 = i * 2;
			nStep1 = nStepSum - nStep2;
		}

		p = s + i;
		while(p < pStrEnd) 
		{
			*q++ = *p;
			p += nStep1;
			if (p < pStrEnd) 
			{
				*q++ = *p;
				p += nStep2;
			}
			else
			{
				break;
			}
		}

	}

	strcpy(s, buff);
	free(buff);
	return s;
}

int main()
{
	char s3[] = "PAYPALISHIRING";
	printf("%s\n", convert(s3, 1));
	char s2[] = "PAYPALISHIRING";
	printf("%s\n", convert(s2, 2));
	char s1[] = "PAYPALISHIRING";
	printf("%s\n", convert(s1, 3));
	char s4[] = "PAYPALISHIRING";
	printf("%s\n", convert(s4, 4));
	char s5[] = "PAYPALISHIRING";
	printf("%s\n", convert(s5, 5));
	char s6[] = "PAYPALISHIRING";
	printf("%s\n", convert(s6, 15));
	return 0;
}
