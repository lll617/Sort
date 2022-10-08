#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 直接插入排序

void InsertSort(int A[], int n)
{
	int i, j, temp;
	for ( i = 1; i < n; i++)// 将各元素插入已排好序的序列中(第一个元素看作有序）
	{
		if (A[i]<A[i-1])// 若A[i]关键字小于前驱
		{
			temp = A[i];// temp暂存A[i]
			for ( j = i-1; j>=0&&A[j]>temp; j--)// 检查前面所有排好序的元素
			{
				A[j+1] = A[j];// 所有大于temp元素都往后移
			}
			A[j + 1] = temp;// 复制到插入位置
		}
	}
}


// 直接插入排序（带哨兵）
void InsertSort2(int A[], int n) {
	int i, j;
	for ( i = 2; i < n; i++)// 依次将A[2]-A[n]插入到前面有序序列
	{
		if (A[i]<A[i-1])// 若A[i]关键字小于前驱，则插入有序表
		{
			A[0] = A[i];// 复制为哨兵，A[0]不存放元素
			for ( j = i-1; A[j]>A[0]; j--)// 从后往前查找待插入位置
			{
				A[j + 1] = A[j];// 大于哨兵的往后挪
			}
			A[j + 1] = A[0];// 复制到插入位置
		}
	}
}


// 折半插入排序
void InsertSort3(int A[], int n)
{
	int i, j, low, high, mid;
	for ( i = 2; i < n; i++)// 依次将A[2]-A[n]插入到前面有序表
	{
		A[0] = A[i];// 哨兵，A[0]暂存A[i]
		low = 1; high = i - 1;// 设置折半查找的范围
		while (low <=high)// 折半查找（默认递增有序）
		{
			mid = (low + high) / 2;// 取中间点
			if (A[mid] > A[0])
				high = mid - 1;// 查左半表
			else// 隐含A[mid]<=A[0]
				low = mid + 1;// 查右半表
		}
		for ( j = i-1; j>=low; j--)
		{
			A[j + 1] = A[j];// 统一后移元素，空出插入位置
		}
		A[low] = A[0];// 插入操作
	}
}


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

// 对链表进行插入排序
LNode* InsertSort3(LinkList &L){
	if (L == NULL)
		return L;
	// 哑结点
	LNode* dummy = (LNode*)malloc(sizeof(LNode));
	dummy->next = L;
	LNode* cur = L;
	LNode* insert, * prehead;
	while (cur->next) {
		// 找到非升序的结点cur->next
		if (cur->data <= cur->next->data)
			cur = cur->next;
		else {
			// 摘下insert = cur->next
			insert = cur->next;
			cur->next = insert->next;
			prehead = dummy;
			// 从头结点找到insert插入位置（第一个比insert大的）
			while (prehead->next->data < insert->data)
				prehead = prehead->next;
			// 插入
			insert->next = prehead->next;
			prehead->next = insert;
		}
	}
	return dummy->next;// 返回头结点

}


// 希尔排序
void ShellSort(int A[], int n) {
	int d, i, j;
	// A[0]只是暂存单元，不是哨兵，当j<=0时，已到插入位置
	for(d=n/2; d>=1; d=d/2)
		for(i=d+1; i<=n; i++)// 交替处理子表
			if (A[i] < A[i - d]) {// 将A[i]插入有序增量子表
				A[0] = A[i];// 暂存A[i]在A[0]
				for (j = i - d; j >= 0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];// 记录后移，跳出时j+d为插入位置（j位置比A[0]小）
				A[j + d] = A[0];// 插入
			}
}

void ShellSort2(int A[], int n) {
	int d, i, j,k;
	// A[0]只是暂存单元，不是哨兵，当j<=0时，已到插入位置
	for (d = n / 2; d >= 1; d = d / 2)
		for (i = d + 1; i <= n; i++)
			for(k=i; k<=n; k+=d)// 一个一个处理子表
				if (A[k] < A[k - d]) {// 将A[i]插入有序增量子表
					A[0] = A[k];// 暂存A[i]在A[0]
					for (j = k - d; j >= 0 && A[0] < A[j]; j -= d)
						A[j + d] = A[j];// 记录后移，跳出时j+d为插入位置（j位置比A[0]小）
					A[j + d] = A[0];// 插入
				}
}