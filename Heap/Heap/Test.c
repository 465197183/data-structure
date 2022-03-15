#include"Heap.h"

void HeapSort(int* a, int n)
{
	assert(a);
	//��a������С��
	//(1)
	//for (int i = 1; i < n; i++)//����ֱ�Ӵ�1��ʼ���Ƶ���
	//{
	//	AdjustUp(a, i);
	//}
	//(2)
	int parent = (n - 2) / 2;
	while (parent >= 0)
	{
		AdjustDown(a,n ,parent);
		parent--;
	}
	int flag = n - 1;
	while (flag)//
	{
		Swap(&a[flag], &a[0]);
		AdjustDown(a, flag, 0);
		flag--;
	}

}

int main()
{
	int a[] = { 70,56,30,25,15,10,75,33,50,69 };
	for (int  i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{	
		printf("%d ", a[i]);
	}
	printf("\n");

	HeapSort(a, sizeof(a) / sizeof(a[0]));

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

//int main()
//{
//	int a[] = {70,56,30,25,15,10,75,33,50,69 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp,a[i]);
//	}
//	HeapDestroy(&hp);
//	return 0;
//}
//void PrintTopK(int* a, int n, int k)
//{
//	HP hp;
//	HeapInit(&hp);
//	//����k������С��
//	for (int i = 0; i < k; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	//ʣ�µ�N-K������Ѷ����ݱȽϣ������ڶѶ��������滻�����ݽ���
//	for (int i = k; i < n; i++)
//	{
//		if (a[i] > HeapTop(&hp))
//		{
//			//(1)
//			//HeapPop(&hp);
//			//HeapPush(&hp, a[i]);
//			//(2)
//			hp.a[0] = a[i];
//			AdjustDown(hp.a, hp.size, 0);
//		}
//	}
//	HeapPrint(&hp);
//	//HeapDestroy(&hp);
//}
//
//void TestTopk()
//{
//	int n = 10000;
//	int* a = (int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	for (size_t i = 0; i < n; ++i)
//	{
//		a[i] = rand() % 1000000;
//	}
//	a[5] = 1000000 + 1;
//	a[1231] = 1000000 + 2;
//	a[531] = 1000000 + 3;
//	a[5121] = 1000000 + 4;
//	a[115] = 1000000 + 5;
//	a[2335] = 1000000 + 6;
//	a[9999] = 1000000 + 7;
//	a[76] = 1000000 + 8;
//	a[423] = 1000000 + 9;
//	a[3144] = 1000000 + 10;
//	PrintTopK(a, n, 10);
//}
//
//
//int main()
//{
//	TestTopk();
//	return 0;
//}

//int main()
//{
//	int a[] = {70,56,30,25,15,10,75 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp,a[i]);
//		HeapEmpty(&hp);
//	}
//	HeapPrint(&hp);
//	HeapPop(&hp);
//	HeapPrint(&hp);
//	HeapPop(&hp);
//	HeapPrint(&hp);
//	HeapPop(&hp);
//	HeapPrint(&hp);
//	return 0;
//}