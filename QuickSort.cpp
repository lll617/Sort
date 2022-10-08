#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ��������
void QuickSort(int A[], int low, int high) {
	if (low < high) {// �ݹ���������
		int pivotpos = Partition(A, low, high);// ����
		QuickSort(A, low, pivotpos - 1);// �������ӱ�
		QuickSort(A, pivotpos + 1, high);// �������ӱ�
	}
}

int Partition(int A[], int low, int high) {
	int pivot = A[low];// ��һ��Ԫ����Ϊ����
	while (low < high) {// ��low��high�������������λ��
		while (low < high && high >= pivot) --high;
		A[low] = A[high];// ������С��Ԫ���ƶ������
		while (low < high && low <= pivot) ++low;
		A[high] = A[low];// ��������Ԫ���ƶ����Ҷ�
	}
	A[low] = pivot;// ����Ԫ�ش�ŵ�����λ��
	return low;// ���ش�����������λ��
}
