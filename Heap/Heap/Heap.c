#include"Heap.h"

void HeapInit(HP* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

HeapDataType HeapTop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}


void AdjustUp(int* a,int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0) 
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//void AdjustUp(HeapDataType* a, int child)
//{
//	assert(a);
//	int parent = (child - 1) / 2;
//	while (a[child] > a[parent]) 
//	{
//		Swap(&a[child], &a[parent]);
//		child = parent;
//		parent = (child - 1) / 2;
//	}
//}

void AdjustDown(HeapDataType* a, int n, int parent)
{
	assert(a);
	int child = 2*parent + 1;
	//���µ���ʱѡ���ӽ������С�ĺ��ӽ��н�������ֹ�����Ժ������������һ��û�б������ĺ���
	while (child<n)
	{
		//ѡ�����Һ�������С����һ��   child+1<n��ֹ�Һ���
		if (child+1<n&&a[child + 1] < a[child]) child++;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void Swap(HeapDataType* px, HeapDataType* py)
{
	HeapDataType tmp = *px;
	*px = *py;
	*py = tmp;
}

void HeapPrint(HP* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ",hp->a[i]);
	}
	printf("\n");
}
void HeapPush(HP* hp,HeapDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HeapDataType* tmp = realloc(hp->a, newCapacity*sizeof(HeapDataType));
		if (tmp == NULL)
		{
			perror("HeapDestroy::");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}
bool HeapEmpty(HP* hp)
{
	assert(hp);
	return hp->size == 0;
}
int HeapSize(HP* hp)
{
	return hp->size;
}
//ɾ���Ѷ�������
void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}