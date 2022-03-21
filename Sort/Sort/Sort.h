#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int len);

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int len);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int len);

//∂—≈≈–Ú
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int len);
