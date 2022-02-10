#include"SeqList.h"

void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListInsert(&sl, 0, 1);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 1, 2);
	SeqListPrint(&sl);
	SeqListInsert(&sl, SeqListFind(&sl,5), 2);
	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
}

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);


	SeqListPrint(&sl);
	
	SeqListDestory(&sl);
}
void menu()
{
	printf("***************************************");
	printf("*             ��ѡ����Ĳ���           *");
	printf("*             1.ͷ��                               *");
	printf("*             2.ͷɾ                          *");
	printf("*                                     *");
	printf("***************************************");
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}
