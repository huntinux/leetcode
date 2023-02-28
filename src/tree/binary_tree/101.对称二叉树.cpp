/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // start: 22:54
    // end: 
    // 方法1: 层次遍历，每一层是对称的
    bool isSymmetric_v1(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            std::queue<TreeNode*> next;
            std::vector<int> seq;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                seq.push_back(node ? node->val : INT_MAX);
                if (node) next.push(node->left);
                if (node) next.push(node->right);
            }
            // check seq is symmetric
            for (int i = 0; i < seq.size() / 2; ++i) {
                if (seq[i] != seq[seq.size() - 1 - i]) return false;
            }
            q.swap(next);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (left && !right) return false;
        if (!left && right) return false;
        return (left->val == right->val) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
// @lc code=end

