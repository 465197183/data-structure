#include"SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur!=NULL)
	{
		if (cur->next == NULL)
			printf("%d->NULL", cur->data);
		else
			printf("%d->", cur->data);
		cur = cur->next;
	}
}

void SListPushBack(SLTNode** phead, SLTDateType x)
{
	SLTNode* newnode = (SLTDateType)malloc(sizeof(SLTNode));
	newnode->next = NULL;
	newnode->data = x;
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
