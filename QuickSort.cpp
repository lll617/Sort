#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 快速排序
void QuickSort(int A[], int low, int high) {
	if (low < high) {// 递归跳出条件
		int pivotpos = Partition(A, low, high);// 划分
		QuickSort(A, low, pivotpos - 1);// 划分左子表
		QuickSort(A, pivotpos + 1, high);// 划分右子表
	}
}

int Partition(int A[], int low, int high) {
	int pivot = A[low];// 第一个元素作为枢轴
	while (low < high) {// 用low、high搜索枢轴的最终位置
		while (low < high && high >= pivot) --high;
		A[low] = A[high];// 比枢轴小的元素移动到左端
		while (low < high && low <= pivot) ++low;
		A[high] = A[low];// 比枢轴大的元素移动到右端
	}
	A[low] = pivot;// 枢轴元素存放到最终位置
	return low;// 返回存放枢轴的最终位置
}
