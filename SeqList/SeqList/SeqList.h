#pragma once
#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType a[N];
	int size;//统计数组中的元素
}SL;


//接口函数
void SeqListPushBack(SL* ps, int x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

