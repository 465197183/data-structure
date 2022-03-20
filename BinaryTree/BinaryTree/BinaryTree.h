#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	int data;
}BTNode;

//前序遍历
void PreOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//求节点个数
//void BinaryTreeSize(BTNode* root, int* count)
int  BinaryTreeSize(BTNode* root);
//求叶子节点的个数
int BinaryTreeLeafSize(BTNode* root);
//求第K层的节点个数
int BinaryTreeLevelKSize(BTNode* root,int k);
//求二叉树的高度(深度)
int BinaryTreeDepth(BTNode* root);
//查找二叉树中值为X的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
//判断是否为完全二叉树
bool BinaryTreeComplete(BTNode * root);
//销毁二叉树
void BinaryTreeDestroy(BTNode* root);