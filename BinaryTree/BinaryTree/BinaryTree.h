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

//ǰ�����
void PreOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//��ڵ����
//void BinaryTreeSize(BTNode* root, int* count)
int  BinaryTreeSize(BTNode* root);
//��Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafSize(BTNode* root);
//���K��Ľڵ����
int BinaryTreeLevelKSize(BTNode* root,int k);
//��������ĸ߶�(���)
int BinaryTreeDepth(BTNode* root);
//���Ҷ�������ֵΪX�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//�������
void BinaryTreeLevelOrder(BTNode* root);
//�ж��Ƿ�Ϊ��ȫ������
bool BinaryTreeComplete(BTNode * root);
//���ٶ�����
void BinaryTreeDestroy(BTNode* root);