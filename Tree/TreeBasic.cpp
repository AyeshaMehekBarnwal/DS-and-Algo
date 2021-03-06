#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

TreeNode *getNode(int newData)
{
	TreeNode *newNode = new TreeNode();
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int main()
{
	TreeNode *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);

	return 0;
}
