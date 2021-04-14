#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;  

void SListPushBack(SListNode** phead, SListDataType x);

void SListpopBack(SListNode** pphead);

void SListPushFront(SListNode** phead, SListDataType x);

void SListPopFront(SListNode** phead);

SListNode* SListFind (SListNode* phead, SListDataType x);

void SListInsertAfter(SListNode* pos,SListDataType x);

void SListEraseAfter(SListNode* pos);
void SListPrint(SListNode* phead);