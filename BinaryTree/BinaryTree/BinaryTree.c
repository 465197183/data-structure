#include"BinaryTree.h"
#include"Queue.h"

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

//void BinaryTreeSize(BTNode* root,int *count)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	(*count)++;
//	BinaryTreeSize(root->left,count);
//	BinaryTreeSize(root->right,count);
//}

int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) 
		return 0;
	if (root->left == NULL && root->right == NULL) 
		return 1; 
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//root!=NULL&&k!=1,说明root这棵树的第k层结点在子树里面
	//转换成求左右子树的第k-1层的结点
	return BinaryTreeLevelKSize(root->left,k-1) + BinaryTreeLevelKSize(root->right,k-1);

}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	//return BinaryTreeDepth(root->left) > BinaryTreeDepth(root->right) ?
	//	BinaryTreeDepth(root->left) + 1 : BinaryTreeDepth(root->right)+1;
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* leftRet = BinaryTreeFind(root->left,x);
	if (leftRet != NULL) 
		return leftRet;
	BTNode* rightRet = BinaryTreeFind(root->right,x);
	if (rightRet != NULL)
		return rightRet;

	return NULL;
}

void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if(front->left)
			QueuePush(&q,front->left);
		if(front->right)
			QueuePush(&q,front->right);
	}
	printf("\n");
	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	//遇到空之后，检查剩下的节点
	//1.剩下的全是空，则为完全二叉树
	//2.剩下的存在非空，则不是完全二叉树
	while(!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{	
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;

}

void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}