#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//ListInit(ListNode** pphead);

ListNode* ListInit();

void ListPrint(ListNode* phead);

ListNode* BuyListNode(LTDataType x);

void ListPushBack(ListNode* phead, LTDataType x);

void ListPopBack(ListNode* phead);

void ListPushFront(ListNode* phead,LTDataType x);

void ListPoPFront(ListNode* phead);

void ListFind(ListNode* phead, int x);

void ListInsert(ListNode* pos, LTDataType data);

void ListErase(ListNode* pos);