# Definition for singly-linked list.

# class ListNode(object):

#     def __init__(self, x):

#         self.val = x

#         self.next = None



class Solution(object):

    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node == None or node.next == None:
            return

        cur = node
        pre = None

        while(cur.next != None):
            cur.val = cur.next.val
            pre = cur
            cur = cur.next

        pre.next = None
        del cur

