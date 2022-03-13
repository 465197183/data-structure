#include"Heap.h"

int main()
{
	int a[] = {15,18,19,25,28,34,65,49,27,37,10 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&hp,a[i]);
	}
	HeapPrint(&hp);
	return 0;
}