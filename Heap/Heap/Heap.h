#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* hp);
void HeapDestroy(HP* hp);
void HeapPush(HP* hp, HeapDataType x);
void HeapPop(HP* hp);
void AdjustDown(HeapDataType* a, int n, int parent);
void AdjustUp(int* a, int n, int child);
HeapDataType HeapTop(HP* hp);
void HeapPrint(HP* hp);
bool HeapEmpty(HP* hp);
int HeapSize(HP* hp);
void Swap(HeapDataType* px, HeapDataType* py);
