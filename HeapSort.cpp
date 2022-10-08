#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void BuildMaxHeap(int A[], int len) {
	for (int i = len/2; i >0; i--){// 从后往前调整所有分支结点
		HeadAdjust(A, i, len);
	}
}

// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
	A[0] = A[k];		// A[0]暂存子树的根结点
	for (int i = 2 * k; i <= len; i *= 2) {// 沿key较大的子结点向下筛选
		if (i < len && A[i] < A[i + 1])
			i++;		// 取key较大的子结点下标
		if (A[0 >= A[i]])	// 筛选结束
			break;
		else {
			A[k] = A[i];	// 将A[i]的值调整到双亲结点上
			k = i;			// 修改k值，以便继续向下筛选
		}
	}
	A[k] = A[0];		// 被筛选的结点放入最终位置
}

// 堆排序
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);		// 初始建堆
	for (int i = len; i > 1; i--) {		// n-1趟交换和建堆过程
		swap(A[i], A[1]);		// 堆顶元素和堆底元素交换
		HeadAdjust(A, 1, i - 1);		// 把剩余的待排序元素整理成堆
	}
}

// 大根堆的插入
void HeapInsert(int A[], int len, int k) {
	A[++len] = k;// 新元素放到表尾（堆底), 表长加一
	
	int n = len;
	while (A[n] > A[n / 2]) {// 若比父节点大，则上升
		swap(A[n], A[n / 2]);
		n /= 2;
	}
}


// 堆的删除
void HeapDelete(int A[], int &len, int n) {
	swap(A[n], A[len]);// 被删除元素用表尾（堆底）元素替代
	len--;// 长度-1

	HeadAdjust(A, n, len);// 替代元素下坠
}