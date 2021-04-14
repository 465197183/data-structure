#include"List.h"

void TestList1()
{
	//ListNode* phead = NULL;
	//ListInit(&phead);
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPushFront(phead, 1);
	ListPoPFront(phead);
	ListPoPFront(phead);
	ListPrint(phead);
}

int main()
{
	TestList1();
	return 0;
}