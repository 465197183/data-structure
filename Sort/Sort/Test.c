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


void TestOP()
{
	srand(time(0));
	const int N = 100000000;
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


	printf("InsertSort::%d\n", end1 - begin1);
	printf("ShellSort::%d\n", end2 - begin2);
	printf("SelectSort::%d\n", end3 - begin3);
	printf("HeapSort::%d\n", end4 - begin4);







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
	TestOP();
	return 0;
}