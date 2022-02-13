#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include<stdio.h>
#include<stdlib.h>	
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead,SLTDateType x);