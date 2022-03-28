#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//插入排序
void InsertSort(int* a, int len);

//希尔排序
void ShellSort(int* a, int len);

//选择排序
void SelectSort(int* a, int len);

//堆排序
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int len);

//冒泡排序
void BubbleSort(int* a, int len);

//快速排序
int GetMidIndex(int* a, int left, int right);//三数取中
int Partion1(int* a, int left, int right);
int Partion2(int* a, int left, int right);
int Partion3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//快速排序非递归版本

//归并排序
void MergeSort(int* a, int len);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSortNonR(int* a, int len); //归并排序非递归版本

//计数排序
void CountSort(int* a, int len);
