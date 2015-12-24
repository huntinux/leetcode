#include <stack>
#include <string>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            string::iterator it;
            for (it = s.begin(); it != s.end(); it++) {
                if(*it == '(' || *it == '{' || *it == '[') 
                    st.push(*it);
                else {
                    if (!st.empty()) {
                        char c = st.top();
                        st.pop();
                        if( c == '(' && *it != ')') return false;
                        else if (c == '{' && *it != '}') return false;
                        else if (c == '[' && *it != ']') return false;
                    }
                    else {
                        return false;
                    }
                }

            }
            return st.empty();
        }
};
