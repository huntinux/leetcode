#!/usr/bin/env python
# -*- coding: utf-8 -*-


class Solution(object):
	def convert(self, s, nRows):
		""" 
		: type s:str
		: type nRows:int 
		: rtype: str
		"""
		nLen = len(s)
		if nLen == 0:
		  print 'string is empty'
		  return ''
		if nRows == 1 or nRows >= nLen:
		  return s

		nStepSum = (nRows - 1) * 2
		nStep1 = nStep2 = 0

		result = ''
		for i in range(0, nRows):
			if i == 0 or i == (nRows - 1):
				nStep1 = nStep2 = nStepSum
			else:
				nStep2 = i * 2
				nStep1 = nStepSum - nStep2
				
			j = i	
			while j < nLen:
				result += s[j]
				j += nStep1
				if j < nLen:
					result += s[j]
					j += nStep2
				else:
					break;
					
		return result	


def main():
	slt=Solution()
	print slt.convert('PAYPALISHIRING', 1)
	print slt.convert('PAYPALISHIRING', 2)
	print slt.convert('PAYPALISHIRING', 3)
	print slt.convert('PAYPALISHIRING', 4)
	print slt.convert('PAYPALISHIRING', 5)
	print slt.convert('PAYPALISHIRING', 15)


if __name__ == '__main__':
	main()
