#include"SeqList.h"

//˳�������
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//������Ŀ�������û�пռ�Ϳռ䲻���������зֱ���
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//��ӡ˳���
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//��ʼ��˳���
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//1.����˳���û�пռ�
//2.�ռ䲻��  ����
//3.�ռ��㹻��ֱ�Ӳ������ݼ���
void SeqListPushBack(SL* ps, SLDataType x)
{
	//û�пռ� �ռ䲻�������
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;//�ռ��㹻
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	//if (ps->size > 0)
	//{
	//	ps->size--;
	//}
	assert(ps->size > 0);
	//���ַ�ʽ����
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}