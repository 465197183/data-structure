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
	//多组一起排序
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
	//每组分开排序
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
		//begin==max时，max被换走了，修正一下
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
	//建堆O(N)
	for (int i = (len - 1 - 1 / 2); i >= 0; i--)
	{
		AdjustDown(a, len, i);
	}
	//O(N×logN)
	int end = len - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end - 1, 0);
		end--;
	}
}

void BubbleSort(int* a, int len)
{
	for (int j = 0; j < len-1; j++)
	{
		int flag = 0;
		for (int i = 0; i < len - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0) 
			break;
	}
}

int GetMidIndex(int* a, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + ((right - left) >> 1);//写法都可以
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

int Partion(int* a, int left, int right)
{
	//三数取中
	int min = GetMidIndex(a, left, right);
	Swap(&a[min], &a[left]);
	int keyi = left;
	while (left < right)
	{
		//右边先走，找小于key的
		while (a[right] >= a[keyi] && left < right)
		{
			right--;
		}
		//停下来之后，左边走，找大于key的
		while (a[left] <= a[keyi] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}
void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	int keyi = Partion(a, left, right);
	//[left,keyi-1] keyi [keyi+1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}