/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // 两个队列版本，感觉可读性更好
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> current, next;
        if (root) current.push(root);
        while (!current.empty()) {
            vector<int> sub_order;
            while (!current.empty()) {
                auto n = current.front();
                sub_order.push_back(n->val);
                current.pop();
                if (n->left) next.push(n->left);
                if (n->right) next.push(n->right);
            }
            std::swap(current, next);
            result.push_back(std::move(sub_order));
        }
        return result;
    }

    // 递归版本
    vector<vector<int>> levelOrder_v3(TreeNode* root) {
        vector<vector<int>> result;
        travel(root, 1, result);
        return result;
    }

    void travel(TreeNode* root, int level, vector<vector<int>>& result) {
        if (!root) return;
        if (result.size() < level) {
            result.push_back({});
        }
        result[level - 1].push_back(root->val);
        if (root->left) travel(root->left, level + 1, result);
        if (root->right) travel(root->right, level + 1, result);
    }


    // start: 22:34
    // end: 22:44
    vector<vector<int>> levelOrder_v2(TreeNode* root) {
        if (!root) return {};
        TreeNode* p = root;
        std::queue<TreeNode*> q;
        q.push(p);
        int n = 1;
        vector<vector<int>> results;
        while (!q.empty()) {
            vector<int> level_result;
            int next_level_n = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* n = q.front();
                level_result.push_back(n->val);
                q.pop();
                if (n->left) {
                    q.push(n->left);
                    next_level_n++;
                }
                if (n->right) {
                    q.push(n->right);
                    next_level_n++;
                }
            }
            n = next_level_n;
            results.emplace_back(std::move(level_result));
        }
        return results;
    }

    // start: 22:12
    // end: 22:21
    // 借助队列
    vector<vector<int>> levelOrder_v1(TreeNode* root) {
        vector<vector<int>> result;
        std::queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> sub_order;
            int node_num_in_current_level = q.size();
            while (node_num_in_current_level-- > 0) {
                auto node = q.front();
                q.pop();
                sub_order.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(std::move(sub_order));
        }
        return result;
    }
};
// @lc code=end

