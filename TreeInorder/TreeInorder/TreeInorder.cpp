#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<int> inOrder;
public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> nodes;

		if (root == NULL)
			return inOrder;

		if (root != NULL && root->left == NULL)
		{
			inOrder.push_back(root->val);
			return inOrder;
		}


/*		if (root != NULL && root->left != NULL&& root->right == NULL)
		{
			inOrder.push_back(root->left->val);
			inOrder.push_back(root->val);
			return inOrder;
		}
*/
		nodes.push(root);

		while (!nodes.empty())
		{
			TreeNode *tmpNode = nodes.top();

			nodes.pop();

			if (tmpNode->right != NULL)
			{
				nodes.push(tmpNode->right);
			}
			
			nodes.push(tmpNode);

			if (tmpNode->left != NULL)
			{
				nodes.push(tmpNode->left);
			}

			if (tmpNode->left == NULL && tmpNode->right == NULL && tmpNode ->right->left == NULL && tmpNode ->right->right ==NULL)
				break;

		}

		while (!nodes.empty())
		{
			TreeNode *tmp = nodes.top();
			inOrder.push_back(tmp->val);
			nodes.pop();
		}

		return inOrder;

		}
};  // Above codes are all by myself....Bullshit...

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {

		stack<TreeNode*> nodes;
		vector<int> inOrder;
		//nodes.push(root);
		TreeNode *tmpNodes;
		if (root == NULL)
			return inOrder;
		tmpNodes = root;
		while (!nodes.empty() || tmpNodes)
		{
			while (tmpNodes)
			{
				nodes.push(tmpNodes);
				tmpNodes = tmpNodes->left;
			}
			if (!nodes.empty())
			{
				tmpNodes = nodes.top();
				inOrder.push_back(tmpNodes->val);
				nodes.pop();
				tmpNodes = tmpNodes->right; //太精巧了！ 如果左边到头了，考虑右子树。
			}
		}
		return inOrder;
	}
};