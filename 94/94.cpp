/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
	二叉树遍历： 中序非递归
	中序遍历： left->root->right
	所以基本思想是利用栈的后进先出的性质。

	左子树依次入栈
	当左子树为空时，弹栈（p），访问该元素，然后p移动到它的右子树

	可以这么认为， 在弹栈时，访问元素， 然后转到右子树。
	那么根节点呢？ 其实一个节点的左右节点也可以看成左右子树的根节点。
	左子树就是被当作根节点进行访问了。

	先序非递归： problem 144

NOTE: 一般在出栈时访问元素，因此控制入栈的顺序是解决问题的关键
而且要将节点都看成具有相同地位的节点，他们都可以是根节点。

*/

class Solution {
	public:
		   vector<int> inorderTraversal(TreeNode* root) {
			   vector<int> result;
			   stack<TreeNode *> s;
			   TreeNode * p = root;
			   while(!s.empty() || p)
			   {
				   if (p)	
				   {
					   // push left child into the stack
					   cout << p->val << endl;
					   s.push(p); // only here push node (take the node as root))
					   p = p->left;
				   }
				   else
				   {
					   // all the left in current path are in stack
					   // pop one, access it , then push its right
					   // into the stack
					   p = s.top();
					   s.pop();
					   result.push_back(p->val);
					   p = p->right;
				   }
			   }
			   return result;
		   }
};
