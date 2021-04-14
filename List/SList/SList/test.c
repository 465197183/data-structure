#include"SList.h"

//void TESTSList()
//{
//	SListNode* pList = NULL;
//	SListPushBack(&pList, 1);
//	SListPushBack(&pList, 2);
//	SListPushBack(&pList, 3);
//	SListPushBack(&pList, 4);
//	SListPrint(pList);
//	printf("\n");
//	SListpopBack(&pList);
//	SListpopBack(&pList);
//	SListpopBack(&pList);
//	SListpopBack(&pList);
//	SListpopBack(&pList);
//	SListPrint(pList);
//	printf("\n");
//	SListPushFront(&pList, 1);
//	SListPushFront(&pList, 2);
//	SListPushFront(&pList, 3);
//	SListPushFront(&pList, 4);
//	SListPushFront(&pList, 5);
//	SListPrint(pList);
//	printf("\n");
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPopFront(&pList);
//	SListPrint(pList);
//}

void TESTSList2()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	printf("\n");
	SListNode* pos = SListFind(pList,3);
	if (pos)
	{
		pos->data = 30;
	} 
	SListPrint(pList);
}
int main()
{
	TESTSList2();
	return 0;
}