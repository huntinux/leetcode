


struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;

    dummy.next = head; // 假如额外节点，让对于头部的操作与其他位置操作一致
    int flag = 0, val; // flag记录是否有重复元素类，val记录重复元素的数值
    struct ListNode* prev, *cur;

    prev = &dummy;
    cur  = prev->next;

    while((cur && cur->next) || (flag == 1 && cur)) { // 第一个条件不难理解，第二个条件应对这个用例 [1,1,1]
        if(flag == 0) {
            if(cur->val == cur->next->val) { // 当前元素与后面元素值相同，删掉他们两个，并设置flag和val
                val = cur->val;
                flag = 1;
                prev->next = cur->next->next;
                free(cur);
                free(cur->next);
                cur = prev->next; 
            } else { // 当前元素与后面元素值不同，向后移动
                prev = cur;
                cur = cur->next;
            }
        } else { // 前面出现了重复元素，比较当前元素和val是否相同
            if(cur->val == val) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            } else { // 不相同时重置flag，然后进入下次循环即可
                flag = 0;
            }
        }
    }

    return dummy.next;
}