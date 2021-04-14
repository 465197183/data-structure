#include"SList.h"

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPrint(SListNode* phead)
{
	while (phead!= NULL)
	{
		printf("%d->", phead->data);
		phead=phead->next;
	}
}

void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}