#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 归并排序
#define n 100// n为数组A表长

int* B = (int*)malloc(n * sizeof(int));// 辅助数组B

// A[low...mid]和A[mid+1...high]各自有序，将两部分归并
void Merge(int A[], int low, int mid, int high) {
	int i, j, k;
	for (k = low; k <= high; k++)
		B[k] = A[k];	//将A中所有元素复制到B中
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j])
			A[k] = B[i++];	// 将较小值复制到A中
		else
			A[k] = B[j++];
	}// for
	while (i <= mid) A[k++] = B[i++];// 将剩余表复制
	while (j <= high) A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;		// 从中间划分
		MergeSort(A, low, mid);		// 归并左半部分
		MergeSort(A, mid + 1, high);	// 归并右半部分
		Merge(A, low, mid,high);	// 归并
	}
}