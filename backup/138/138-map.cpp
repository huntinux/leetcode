#include <iostream>
#include <unordered_map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    explicit RandomListNode(int l) : label(l), next(NULL), random(NULL) {}
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

// 使用hash map记录新节点指针与旧节点指针的对应关系
// 时间O(n) 空间O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(head == NULL) return NULL;

        RandomListNode *p, *q, *r, *new_head, *tail;

        typedef RandomListNode* OldNodePointer;
        typedef RandomListNode* NewNodePointer;

        std::unordered_map<OldNodePointer, NewNodePointer> m;

        p = head;
	new_head = tail = NULL;
        while(p != NULL) {
            RandomListNode* n = new RandomListNode(p->label);
	    m.insert(std::make_pair(p, n));
	    if(new_head != NULL) {
		tail->next = n;	
		tail = n;
            } else {
	    	new_head = tail = n;
	    }
            p = p->next;
        }
	
	p = head; q = new_head;
	while(p != NULL) {
	    q->random = m[p->random];
	    p = p->next;
	    q = q->next;
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


