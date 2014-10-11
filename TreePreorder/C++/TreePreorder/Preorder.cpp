#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
	vector<int> preOrder;

public:
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> nodes;

		if (root == NULL) // incase the input is empty
			return preOrder;
			
		nodes.push(root);

		while (!nodes.empty())
		{
			TreeNode *tmpNode = nodes.top();

			//push the root's value into a vector

			preOrder.push_back(tmpNode->val);
			nodes.pop();

			if (tmpNode->right !=NULL)
			{
				nodes.push(tmpNode->right);
			}
			if (tmpNode->left != NULL)
			{
				nodes.push(tmpNode->left);
			}
		}
		return preOrder;
	}
};

//Ĭд״̬
vector<int> preorderTraversal(TreeNode *root)
{
	stack<TreeNode*>nodes;
	vector<int> result;

	if (root == NULL)
	{
		return result;
	}

	nodes.push(root);

	while (!nodes.empty())
	{
		TreeNode *tmp = nodes.top();
		result.push_back(tmp->val);
		nodes.pop();
		if (tmp->right != NULL) nodes.push(tmp->right);
		if (tmp->left != NULL) nodes.push(tmp->left);
	}

	return result;

}