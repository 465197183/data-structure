#include"Sort.h"
#include"Stack.h"

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
	//����O(N)
	for (int i = (len - 1 - 1 / 2); i >= 0; i--)
	{
		AdjustDown(a, len, i);
	}
	//O(N��logN)
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
	int mid = left + ((right - left) >> 1);//д��������
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

//hoare�汾
int Partion1(int* a, int left, int right)
{
	//����ȡ��
	int min = GetMidIndex(a, left, right);
	Swap(&a[min], &a[left]);
	int keyi = left;
	while (left < right)
	{
		//�ұ����ߣ���С��key��
		while (a[right] >= a[keyi] && left < right)
		{
			right--;
		}
		//ͣ����֮������ߣ��Ҵ���key��
		while (a[left] <= a[keyi] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

//�ڿӷ�
int Partion2(int* a, int left, int right)
{
	int min = GetMidIndex(a, left, right);
	Swap(&a[min], &a[left]);
	int key = a[left];
	int pivot = left;
	while (left < right)
	{
		//�ұ���С,�ŵ�������
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[pivot] = a[right];
		pivot = right;


		//����Ҵ󣬷ŵ��ұߵĿ�����
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[pivot] = a[left];
		pivot = left;

	}
	a[pivot] = key;
	return pivot;
}

//����3�ı��ʣ�cur��С����С������߻���prev�Ѵ�����ұ���
int Partion3(int* a, int left, int right)
{
	int min = GetMidIndex(a, left, right);
	Swap(&a[min], &a[left]);
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
		//while��while���ܻ�ʹ����while���������㣬�����ڲ��whileҪ��������while����
		//while (cur <= right && a[cur] >= a[keyi]) 
		//	cur++;
		//if (cur <= right)
		//{
		//	Swap(&a[cur], &a[++prev]);
		//	cur++;
		//}
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}



void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	//С�����Ż���
	//���ָС����ʱ,�����õݹ�ָ��˼·�����ٵݹ����
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, left - right + 1);
	}
	else
	{
		int keyi = Partion3(a, left, right);
		//[left,keyi-1] keyi [keyi+1,right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}

void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int keyi = Partion3(a, begin, end);
		//[begin,keyi-1] keyi [keyi+1,end]
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}

		if (begin < keyi - 1)
		{
			StackPush(&st,begin);
			StackPush(&st, keyi-1);
		}

	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//[left,mid] [mid+1,right] ����
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//tmp�����ֵ������aȥ
	for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	if (tmp == NULL)
	{
		perror("MergeSort_malloc:");
		exit(-1);
	}
	_MergeSort(a, 0, len - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	if (tmp == NULL)
	{
		perror("MergeSort_malloc:");
		exit(-1);
	}

	int gap = 1;
	while (gap < len)
	{
		for (int i = 0; i < len; i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap,i+2*gap-1] 
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			//endԽ��
			if (end1 >= len|| begin2 >= len)
			{
				break;
			}
			if (end2 >= len)
			{
				end2 = len - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			//�ѹ鲢���鿽����ԭ����
			for (int j = i; j <= end2; j++)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

//void MergeSortNonR(int* a, int len)
//{
//	int* tmp = (int*)malloc(sizeof(int) * len);
//	if (tmp == NULL)
//	{
//		perror("MergeSort_malloc:");
//		exit(-1);
//	}	
//
//	int gap = 1;
//	while (gap<len)
//	{
//		for (int i = 0; i < len; i += 2 * gap)
//		{
//			// [i,i+gap-1] [i+gap,i+2*gap-1] 
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i+gap, end2 = i + 2*gap - 1;
//			int index = i;
//			//endԽ��
//			if (end1 >= len)
//			{
//				end1 = len - 1;
//			}
//			if (begin2 >= len)
//			{
//				begin2 = len;//�����ɲ����ڵ����䣬��������㲻���ٽ���ѭ����
//				end2 = len - 1;
//			}
//			if (end2 >= len)
//			{
//				end2 = len - 1;
//			}
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//		}
//		//�ѹ鲢���鿽����ԭ����
//		for (int i = 0; i < len; i++)
//		{
//			a[i] = tmp[i];
//		}
//		gap *= 2;
//	}
//	free(tmp);
//	tmp = NULL;
//}

void CountSort(int* a, int len)
{
	int max = a[0], min = a[0];
	for (int i = 1; i < len; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("CountSort_malloc:");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);
	//ͳ�ƴ���
	for (int i = 0; i < len; i++)
	{
		count[a[i] - min]++;
	}
	//���ݴ�������
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}