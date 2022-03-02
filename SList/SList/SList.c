#include"SList.h"

SLTNode* CreateListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("CreateListNode::malloc");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur!=NULL)
	{
		if (cur->next == NULL)
			printf("%d->NULL\n", cur->data);
		else
			printf("%d->", cur->data);
		cur = cur->next;
	}
}

void SListPushBack(SLTNode** phead, SLTDateType x)
{
	SLTNode* newnode = CreateListNode(x);
	if (*phead == NULL)//Á´±íÎª¿ÕÊ±
	{
		*phead = newnode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = CreateListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	//if (*pphead == NULL)
	//{
	//	return;
	//}
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
	
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
}

SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = CreateListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}