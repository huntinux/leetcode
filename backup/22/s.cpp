/**
  catalan number
http://blog.csdn.net/yutianzuijin/article/details/13161721

http://blog.sina.com.cn/s/blog_7064e7850100y1xf.html
http://blog.sina.com.cn/s/blog_7064e7850100y3l7.html
 */

class Solution {
	public:

		void generate(int leftnum, int rightnum, string s, vector<string> &result)
		{
			if(leftnum == 0 && rightnum == 0)
			{
				result.push_back(s);
			}

			if(leftnum > 0)
			  generate(leftnum-1, rightnum, s + '(', result);

			if(rightnum > 0 && leftnum < rightnum)
			{
				generate(leftnum, rightnum - 1, s + ')', result);
			}
		}


		vector<string> generateParenthesis(int n) {
			vector<string> result;
			generate(n, n, "", result);
			return result;
		}
};
