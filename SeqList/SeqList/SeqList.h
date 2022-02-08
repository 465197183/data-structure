#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//ͳ�������е�Ԫ��
	int capacity; //����ʵ���ܴ洢���ݵĿռ������Ƕ��
}SL;


//�ӿں��� STL �������
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, int x);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);


