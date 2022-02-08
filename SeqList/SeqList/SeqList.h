#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//统计数组中的元素
	int capacity; //数组实际能存储数据的空间容量是多大
}SL;


//接口函数 STL 命名风格
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, int x);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);


