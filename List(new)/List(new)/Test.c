#include"List.h"

//void TestList1()
//{
//	LTNode* plist = NULL;
//	plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 4);
//	ListPushBack(plist, 5);
//	ListPrint(plist);
//	ListPopBack(plist);
//	ListPopBack(plist);
//	ListPopBack(plist);
//	ListPopBack(plist);
//	ListPrint(plist);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//	ListPushFront(plist, 4);
//	ListPushFront(plist, 5);
//	ListPushFront(plist, 6);
//	ListPrint(plist);
//	ListPrint(plist);
//}

void TestList2()
{
	LTNode* plist = NULL;
	plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	TestList2();
	return 0;
}