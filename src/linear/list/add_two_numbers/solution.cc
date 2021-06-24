#include "solution.h"

// 分析
//  既然list中的元素是逆序存放的，链表头为最低位，设置两个指针同时扫描即可
//  如果l1和l2长度不同，可以认为较短的list中的缺少的元素为0即可
//  还要注意当进位不是0时，也需要继续创建新节点
//
// 下面的代码不是一次写成的，会根据testcase做一些调整，让代码更整洁
// 坚持对问题进行详细分析，分析好了再编码，然后测试驱动开发，重构
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *head, *tail;
  head = tail = nullptr;
  int carry = 0;
  while (l1 || l2 || (carry != 0)) { // 任意list不为空，且仅为也不为空时，进入循环
    int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // 新元素的值为list对应元素相加，再加上进位
    int val = n % 10; // 计算进位和真正的val
    carry = n / 10;
    ListNode* node = new ListNode(val);

    // 尾插法, 无dummy头节点
    if (tail) {
      tail->next = node;
      tail = tail->next;
    } else {
      head = tail = node;
    }

    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
  }

  return head;
}
