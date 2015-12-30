/*
   Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
   For example:
   Given the below binary tree and sum = 22,

   5
   / \
   4   8
   /   / \
   11  13  4
   /  \      \
   7    2      1

   return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
   */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* root, int cursum, int sum)
{
    if (root == NULL) return false;

    int localsum = cursum + root->val;
    if (root->left==NULL && root->right==NULL)
        return localsum == sum;

    if (helper(root->left, localsum, sum))
        return true;
    else if (helper(root->right, localsum, sum))
        return true;
}

bool helper(struct TreeNode* root, int cursum, int sum)
{
    if (root == NULL) return false;
    int localsum = cursum + root->val;
    if (root->left==NULL && root->right==NULL)
        return localsum == sum;
    return helper(root->left, localsum, sum) || helper(root->right, localsum, sum);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    return helper(root, 0, sum) ;
}
