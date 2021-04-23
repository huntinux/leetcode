
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
        /**
         * 非递归：借助栈，栈中的每个元素包含节点指针和深度,因此定义为一个pair
         */

        int minDepth(TreeNode* root) 
        {
            if(root == nullptr) return 0;

            int result = INT_MAX;
            stack<pair<TreeNode *, int>> s;
            s.push(make_pair(root, 1));

            while(!s.empty())
            {
                auto node  = s.top().first;
                auto depth = s.top().second;
                s.pop();

                // 到达叶子节点, 计算结果
                if (node->left == nullptr && node->right == nullptr)
                {
                    result = min(result, depth);
                }

                // 剪枝： 如果当前深度大于或等于 当前结果， 则没有必要在该分支继续进行计算
                if (node->left && depth < result)
                    s.push(make_pair(node->left, depth + 1));
                if (node->right && depth < result)
                    s.push(make_pair(node->right, depth + 1));

            }

            return result;
        }

};
