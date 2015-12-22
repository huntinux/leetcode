/*
   Given a binary tree, find its maximum depth.
   The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {

    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
