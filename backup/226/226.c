/*
    Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

    */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {

    if ( root == NULL )
        return NULL;

    // leaf node
    if ( root->left == NULL && root->right == NULL) {
        return root;
    }
    struct TreeNode * cachenode = root->left;
    root->left  = invertTree(root->right);
    root->right = invertTree(cachenode);
    return root;
}


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
    // non-recursion : using queue
    if (root == nullptr) return nullptr;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode * n = q.front();
        q.pop();

        TreeNode * cachenode = n->left;
        n->left = n->right;
        n->right = cachenode;

        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
             
    }
};
