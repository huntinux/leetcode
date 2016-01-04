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
