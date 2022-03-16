#include"BinaryTree.h"

BTNode* CreateNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("CreateNode");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* nodeA = CreateNode('A');
	BTNode* nodeB = CreateNode('B');
	BTNode* nodeC = CreateNode('C');
	BTNode* nodeD = CreateNode('D');
	BTNode* nodeE = CreateNode('E');
	BTNode* nodeF = CreateNode('F');
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	return nodeA;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	int count = 0;
	//BinaryTreeSize(root, &count);
	//printf("BinaryTreeSize = %d\n",count);
	printf("BinaryTreeSize = %d", BinaryTreeSize(root));
	return 0;
}
