/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3]. 
*/

// 二叉树先序遍历，非递归, 借助stack
// 访问根，然后右孩子入栈，左孩子入栈 , 那么出栈时， left先出栈，因此访问顺序是 (root->left->right)
// 每个节点都可以看成根节点，地位相同
// 在出展时，访问元素
// 因此，关键在于按照什么顺序将元素入栈，达到想要的访问次序
// 中序遍历非递归： problem 94
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode *> s;

            if (root) s.push(root);
            while(!s.empty())
            {
                auto node = s.top();
                result.push_back(node->val);
                s.pop();

                if (node->right) s.push(node->right);
                if (node->left) s.push(node->left);
            }

            return result;
        }
};
