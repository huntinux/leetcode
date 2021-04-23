#include <iostream>


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    explicit RandomListNode(int l) : label(l) {}
};

void PrintList(RandomListNode* h)
{
    RandomListNode *p;

    for(p = h; p != NULL; p = p->next) {
        std::cout << p->label << ":" << std::endl
                  << "next:" << ((p->next != NULL) ? (p->next->label) : (0)) << std::endl
                  << "random:" << p->random->label << std::endl;
    }
}

// see: https://www.cnblogs.com/TenosDoIt/p/3387000.html
// 1->1'->2->2'->3->3'->null
// 把新建节点插在后面，那么新建节点的random就是老节点random的next域
// 最后将链表拆成两个即可
// 注意random有可能为null的情况
// 时间O(n) 空间O(1)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(head == NULL) return NULL;

        RandomListNode *p, *q, *r, *new_head;

        p = head;
        while(p != NULL) {
            RandomListNode* n = new RandomListNode(p->label);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }

        p = head;
        while(p != NULL) {
            q = p->next;
            q->random = (p->random != NULL) ? (p->random->next) : (NULL);
            p = p->next->next;
        }

        new_head = head->next;
        p = head;
        while(p->next != NULL) {
            r = p->next;
            p->next = r->next;
            p = r;
        }

        return new_head;
    }
};


int main()
{
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);

    n1.next = &n2;
    n1.random = &n3;
    n2.next = &n3;
    n2.random = &n1;
    n3.next = NULL;
    n3.random = &n2;

    PrintList(&n1);

    Solution s;
    RandomListNode* h = s.copyRandomList(&n1);
    PrintList(h);
}
