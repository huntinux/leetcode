

class Solution(Object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = [];
        for c in s:
            if c in ['(', '{', '[']:
                stk.append(c)
            else:
                if len(stk) != 0:
                    cinstk = stk.pop()
                    if cinstk == '(' and c != ')':
                        return False
                    elif cinstk == '{' and c != '}':
                        return False
                    elif cinstk == '[' and c != ']':
                        return False
                else:
                    return False

        return len(stk) == 0

    # nice code
    def isValid2(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        dict = {"]":"[","}":"{",")":"("}
        for c in s:
            if c in dict.values():
                stack.append(c)
            elif c in dict.keys():
                if stack == [] or dict[c] != stack.pop():
                    return False
            else:
                return False

        return stack == []

