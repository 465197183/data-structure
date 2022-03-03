#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead,SLTDateType x);
void SListPushFront(SLTNode** phead, SLTDateType x);
SLTNode* CreateListNode(SLTDateType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

//��posλ��֮ǰ����һ����㣬��SListFind��pos
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDateType x);
//��posλ��֮�����
void SListInsertAfter(SLTNode* pos, SLTDateType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);//ɾ��posλ�õ���һ��λ��
void SListDestory(SLTNode** pphead);
