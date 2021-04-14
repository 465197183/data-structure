#include"List.h"

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;

	return node;
}

ListNode* ListInit()
{
	ListNode * phead = BuyListNode(0);
	phead->next = phead;
	phead->prev= phead;

	return phead;
}
//ListInit(ListNode** pphead)
//{
//	*pphead = BuyListNode(0);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

void ListPushBack(ListNode* phead, LTDataType x)
{
	
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;

}

void ListPopBack(ListNode* phead)
{
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* frist = phead->next;
	ListNode* newNode = BuyListNode(x);
	phead->next = newNode;
	newNode->next = frist;
	newNode->prev = phead;
	frist->prev = newNode;
}

void ListPoPFront(ListNode* phead) 
{
	ListNode* frist = phead->next;
	ListNode* second = frist->next;
	phead->next = second;
	second->prev = phead;
	free(frist);
	frist = NULL;

}

void ListFind(ListNode* phead, int x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType data)
{

}