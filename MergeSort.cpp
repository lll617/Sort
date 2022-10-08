#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// �鲢����
#define n 100// nΪ����A��

int* B = (int*)malloc(n * sizeof(int));// ��������B

// A[low...mid]��A[mid+1...high]�������򣬽������ֹ鲢
void Merge(int A[], int low, int mid, int high) {
	int i, j, k;
	for (k = low; k <= high; k++)
		B[k] = A[k];	//��A������Ԫ�ظ��Ƶ�B��
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j])
			A[k] = B[i++];	// ����Сֵ���Ƶ�A��
		else
			A[k] = B[j++];
	}// for
	while (i <= mid) A[k++] = B[i++];// ��ʣ�����
	while (j <= high) A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;		// ���м仮��
		MergeSort(A, low, mid);		// �鲢��벿��
		MergeSort(A, mid + 1, high);	// �鲢�Ұ벿��
		Merge(A, low, mid,high);	// �鲢
	}
}