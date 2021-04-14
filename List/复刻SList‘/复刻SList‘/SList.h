#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SListDataType x);

void SListPrint(SListNode* phead);

void SListPushBack(SListNode** pphead, SListDataType x);
