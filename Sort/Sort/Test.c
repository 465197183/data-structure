#include"Sort.h"

void TestShellSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	ShellSort(a, len);
	printf("ShellSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestInsertSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	InsertSort(a, len);
	printf("InsertSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestSelectSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	SelectSort(a, len);
	printf("SelectSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestHeapSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	HeapSort(a, len);
	printf("HeapSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);

}

void TestBubbleSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, len);
	printf("BubbleSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestQuickSort()
{
	int a[] = { 6,2,5,3,9,4,8,5,1,7 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0,len-1);
	printf("QuickSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}
void TestQuickSortNonR()
{
	int a[] = { 6,2,5,3,9,4,8,5,1,7 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, len - 1);
	printf("QuickSortNonR:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	int len = sizeof(a) / sizeof(a[0]);
	MergeSort(a, len);
	printf("TestMergeSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);

}
void TestMergeSortNonR()
{
	int a[] = { 10,6,7,1,3,9,4,2,4,3,1,0,1 };
	int len = sizeof(a) / sizeof(a[0]);
	MergeSortNonR(a, len);
	printf("TestMergeSortNonR:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}
void TestCountSort()
{
	int a[] = { 9,9,8,8,7,7,6,6,5,5,4,4,3,3,2,2,1,1,0,0,0 };
	int len = sizeof(a) / sizeof(a[0]);
	CountSort(a, len);
	printf("TestCountSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//BubbleSort(a5, N);
	int end5 = clock();

	//int begin5 = clock();
	//QuickSortNonR(a6, 0, N - 1);
	//int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	QuickSort(a7, 0, N - 1);
	int end7 = clock();

	printf("InsertSort::%d\n", end1 - begin1);
	printf("ShellSort::%d\n", end2 - begin2);
	printf("SelectSort::%d\n", end3 - begin3);
	printf("HeapSort::%d\n", end4 - begin4);
	printf("BubbleSort::%d\n", end5 - begin5);
	printf("QuickSort::%d\n", end6 - begin6);
	printf("MergeSort::%d\n", end7 - begin7);




	free(a1);
	free(a2);
	free(a3);
	free(a4); 
	free(a5);
	free(a6);
	free(a7);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	//TestCountSort();
	TestOP();
	return 0;
}