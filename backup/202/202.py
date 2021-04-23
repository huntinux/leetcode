class Solution(object):

    def digitSquareSum(self, n):
        result = 0
        while n != 0:
            t = n % 10
            result += t * t
            n /= 10
        return result

    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        hashmap = set()
        while True:
            n = digitSquareSum(n)
            if n in hashmap:
                break
            hashmap.add(n)

        return n == 1

