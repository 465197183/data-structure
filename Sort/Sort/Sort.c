#include"Sort.h"

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void InsertSort(int* a, int len)
{
	assert(a);
	for (int i = 0; i < len - 1; i++)
	{
		int end = i;
		int x = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = x;
	}
}

void ShellSort(int* a, int len)
{
	//����һ������
	int gap = len;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < len - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}
	}
	//ÿ��ֿ�����
	//for (int j = 0; j < gap; j++)
	//{
	//	for (int i = j; i < len - gap; i++)
	//	{
	//		int end = i;
	//		int x = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (a[end] > x)
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = x;
	//	}
	//}
}


void SelectSort(int* a, int len)
{
	int begin = 0;
	int end = len - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[begin],&a[min]);
		//begin==maxʱ��max�������ˣ�����һ��
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		begin++, end--;
	}
	
}

void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
			child++;
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


void HeapSort(int* a, int len)
{

}
