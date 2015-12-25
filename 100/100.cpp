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
    // 非递归方法
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> s;
        
        s.push(p);
        s.push(q);

        while(!s.empty())
        {
            auto r = s.top(); s.pop();
            auto n = s.top(); s.pop();

            if (!r && !n) continue;
            if (!r || !n) return false;
            if (r->val != n->val) return false;

            s.push(r->left);
            s.push(n->left);
            s.push(r->right);
            s.push(n->right);
        }

        return true;

    }
};
