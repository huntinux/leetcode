public class Solution {
    public boolean isValid(String s) {

        Stack<Character> stk = new Stack<Character>();
        char[] carr = s.toCharArray();
        for(char c : carr)
        {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else{
                if(!stk.empty()) {
                    char cinstk = stk.pop();

                    if( cinstk == '(' && c != ')') return false;
                    else if (cinstk == '{' && c != '}') return false;
                    else if (cinstk == '[' && c != ']') return false;
                }else{
                    return false;
                }

            }

        }

        return stk.empty();

    }
}
