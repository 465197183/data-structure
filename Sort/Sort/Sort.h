#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

//²åÈëÅÅĞò
void InsertSort(int* a, int len);

//Ï£¶ûÅÅĞò
void ShellSort(int* a, int len);

//Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int len);

//¶ÑÅÅĞò
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int len);

//Ã°ÅİÅÅĞò
void BubbleSort(int* a, int len);

//¿ìËÙÅÅĞò
int GetMidIndex(int* a, int left, int right);//ÈıÊıÈ¡ÖĞ
int Partion1(int* a, int left, int right);
int Partion2(int* a, int left, int right);
int Partion3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

