/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // start: 22:18
    // end: 22:28
    // copy list
    // map[oldnode] = newnode
    Node* copyRandomList(Node* head) {
        Node* new_head = nullptr, *new_tail = nullptr;
        Node* curr = head;
        std::unordered_map<Node*, Node*> dict;
        std::unordered_map<Node*, Node*> reverse_dict;

        while (curr) {
            Node* node = new Node(curr->val);
            if (new_head) {
                new_tail->next = node;
                new_tail = node;
            } else {
                new_head = new_tail = node;
            }
            dict[curr] = node;
            reverse_dict[node] = curr;
            curr = curr->next;
        }

        dict[nullptr] = nullptr;
        reverse_dict[nullptr] = nullptr;

        curr = new_head;
        while (curr) {
            curr->random = dict[reverse_dict[curr]->random];
            curr = curr->next;
        }
        return new_head;
    }
};
// @lc code=end

