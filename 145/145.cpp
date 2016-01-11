
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 后续遍历 非递归
    // stack<TreeNode *, int> 
    // 其中int表示该节点的状态 
    // 1 : 表示第一次进入栈
    //     push(cur, 2) , 更新状态
    //     判断有没有right，如果有，就push(right, 1);
    //     判断有没有left，如果有，就push(left, 1)
    // 2 : 表示第二次入栈
    //     此时，左右孩子都访问完了， 终于可以访问自己了
    
    vector<int> postorderTraversal(TreeNode* root) {

        stack<pair<TreeNode *, int>> s;
        vector<int> result;

        if (root) s.push(make_pair(root, 1));
        else return result;

        while(!s.empty())
        {
            auto p = s.top().first;
            auto v = s.top().second;
            s.pop();

            if (v == 1)
            {
                s.push(make_pair(p, 2));
                if (p->right) s.push(make_pair(p->right, 1));
                if (p->left) s.push(make_pair(p->left, 1));
            }
            else
            {
                result.push_back(p->val);
            }
        }
        return result;
        
    }
};
