#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Solution {

	public:

		string convert(string s, int nRows) 
		{
			if (s.empty()) return "";

			int nLen = s.length();
			if (nRows == 1 || nRows >= nLen) return s;

			string buff;
			int nStepSum = (nRows - 1) * 2;
			int nStep1, nStep2;
			nStep1 = nStep2 = 0;
			//char * p;
			string::iterator p;
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

				p = s.begin() + i;
				while(p < s.end()) 
				{
					//*q++ = *p;
					buff.append(1, *p);
					p += nStep1;
					if (p < s.end()) 
					{
						//*q++ = *p;
						buff.append(1, *p);
						p += nStep2;
					}
					else
					{
						break;
					}
				}

			}

			return buff;
		}

};

int main()
{
	Solution slt;

	cout << slt.convert("PAYPALISHIRING", 1) << endl;
	cout << slt.convert("PAYPALISHIRING", 2) << endl;
	cout << slt.convert("PAYPALISHIRING", 3) << endl;
	cout << slt.convert("PAYPALISHIRING", 4) << endl;
	cout << slt.convert("PAYPALISHIRING", 5) << endl;
	cout << slt.convert("PAYPALISHIRING", 15) << endl;

	return 0;
}
