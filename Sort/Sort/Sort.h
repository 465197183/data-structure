#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

//��������
void InsertSort(int* a, int len);

//ϣ������
void ShellSort(int* a, int len);

//ѡ������
void SelectSort(int* a, int len);

//������
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int len);
