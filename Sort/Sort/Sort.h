#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//��������
void InsertSort(int* a, int len);

//ϣ������
void ShellSort(int* a, int len);

//ѡ������
void SelectSort(int* a, int len);

//������
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int len);

//ð������
void BubbleSort(int* a, int len);

//��������
int GetMidIndex(int* a, int left, int right);//����ȡ��
int Partion1(int* a, int left, int right);
int Partion2(int* a, int left, int right);
int Partion3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//��������ǵݹ�汾

//�鲢����
void MergeSort(int* a, int len);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSortNonR(int* a, int len); //�鲢����ǵݹ�汾

//��������
void CountSort(int* a, int len);
