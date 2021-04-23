



class Solution(Object):
    def isAnagram(self, s, t):
        if len(s) == len(t):
            for char in set(s):
                if s.count(char) != t.count(char):
                    return False
            return True
        else:
            return False

