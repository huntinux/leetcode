/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    // 102 的基础上 reverse
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> results;
        std::queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            std::vector<int> sub_order;
            int node_num_in_current_level = q.size();
            while (node_num_in_current_level-- > 0) {
                TreeNode* n = q.front();
                sub_order.push_back(n->val);
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            //results.insert(results.begin(), std::move(sub_order));
            results.push_back(std::move(sub_order));
        }
        std::reverse(results.begin(), results.end());
        return results;
    }
};
// @lc code=end

