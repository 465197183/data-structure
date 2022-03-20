#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 6,1,7,4,9,3,5,0,8 };
	int len = sizeof(a) / sizeof(a[0]);
	InsertSort(a, len);
	printf("InsertSort:: ");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

int main()
{
	TestInsertSort();
	return 0;
}