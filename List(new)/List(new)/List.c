#include"List.h"


LTNode* ListInit()
{
	//哨兵位的头结点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		perror("ListInit::");
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

LTNode* CreateListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("CreateListNode::");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}


void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = CreateListNode(x);
	newnode->data = x;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newnode = CreateListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
	tail = NULL;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);
	LTNode* next = phead->next;
	phead->next = phead->next->next;
	phead->next->prev = phead;
	free(next);
}

LTNode* ListFind(LTNode* phead,LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* newnode = CreateListNode(x);
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void ListDestroy(LTNode* phead) 
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur=next;
	}

	free(phead);
	phead = NULL;

}