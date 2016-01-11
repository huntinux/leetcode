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
    // 二叉树中序遍历-非递归
    // 将叶子节点看成是有两个左右子树的节点（只不过左右都为空）
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode * pcur;

        while(!s.empty() || pcur) // 非常精巧的条件
        {
            if (pcur)
            {   
                // 所有左侧节点都入栈
                s.push(pcur);
                pcur = pcur->left;
            }
            else
            {
                // 所有节点，在出栈时访问
                TreeNode * n = s.top();
                result.push_back(n->val); // 访问该节点
                s.pop();
                pcur = n->right; // 右边入栈
            }
        }

        return result;
    }
};
// Morris Traversal : 不使用栈
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
