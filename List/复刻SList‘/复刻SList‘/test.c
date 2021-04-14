#include"SList.h"

int main()
{
	SListNode* pList=NULL;
	SListPushBack(&pList, 1);
	//SListNode* x = BuySListNode(2);
	SListPrint(pList);
	return 0;
}