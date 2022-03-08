#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>	
#include<assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();

LTNode* CreateListNode(LTDateType x);

void ListPushBack(LTNode* phead,LTDateType x);

void ListPrint(LTNode* phead);

void ListPushFront(LTNode* phead,LTDateType x);

void ListPopBack(LTNode* phead);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead,LTDateType x);

void ListInsert(LTNode* pos,LTDateType x);

void ListErase(LTNode* phead);

void ListDestroy(LTNode* phead);