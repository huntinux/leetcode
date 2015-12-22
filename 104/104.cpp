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

#if 1
        /**
         * 非递归（借助stack, stack中的元素包含节点的指针和该节点的深度）
         */
        int maxDepth(TreeNode* root) 
        {
            if (root == nullptr) return 0;

            int result = 0;
            stack<pair<TreeNode *, int>> s;
            s.push(make_pair(root, 1));
            while(!s.empty())
            {
                auto node  = s.top().first;
                auto depth = s.top().second;
                s.pop();

                if(node->left == nullptr && node->right == nullptr)
                {
                    result = max(result, depth);
                }

                if(node->right) s.push(make_pair(node->right, depth + 1));
                if(node->left)  s.push(make_pair(node->left , depth + 1));
            }

            return result;
        }
#endif

#if 0
        /**
         * BFS 层次遍历二叉树(借助queue)，每当访问完一层时，深度加1
         */
        int maxDepth(TreeNode* root) 
        {
            int depth = 0; // 记录树的深度
            int count = 0; // 记录当前层上的节点个数

            queue<TreeNode *> treeNodeQueue;
            if(root) 
            {
                treeNodeQueue.push(root);
                count++;
            }

            while(!treeNodeQueue.empty())
            {

                queue<TreeNode *>::value_type n = treeNodeQueue.front();
                if(n->left) treeNodeQueue.push(n->left);
                if(n->right) treeNodeQueue.push(n->right);
                treeNodeQueue.pop();
                count--; // 表示已经访问了当前层的一个元素


                // 当前层访问完毕，深度加1
                if (count == 0)
                {
                    depth++;
                    count = treeNodeQueue.size(); // 下一层的节点个数
                }
            }

            return depth;
        }

#endif

};
