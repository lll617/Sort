#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 简单选择排序
void SelectSort(int A[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {// 比较n-1趟
		min = i;// 记录最小元素的位置
		for (j = i + 1; j < n; j++)// 在A[i...n-1]中选择最小的元素
			if (A[j] < A[min])
				min = j;// 更新最小元素位置
		if (min != i)// 交换
			swap(A[min], A[i]);
	}
}


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;

// 简单选择排序（链表，交换数据域）
void SelectSort2(LinkList& L) {
	LNode* p,*q=L, * min;// p为工作指针
	int temp;
	while (q && q->next !=NULL) {
		p = q;// q记录每趟一个元素的最终位置
		min = p;
		while (p->next)// 找值最小结点
			if (p->next->data < p->data)
			min = p->next;
		if (min != q) {// 交换
			temp = q->data;
			q->data = min->data;
			min->data = temp;
		}
		q = q->next;// q后移
	}
}

// 简单选择排序（链表，不带头结点）
void SelectSort3(LinkList& L) {
	LNode* h = L, * p, * q, * max, * maxpre;
	// max记忆最大结点，maxpre为max前驱，p为工作指针，q为p前驱
	L = NULL;
	while (h != NULL) {
		p = max = h;
		q = maxpre = NULL;
		while (p != NULL) {// 找最大结点
			if (p->data > max->data) {
				maxpre = q;
				max = p;
			}
			q = p;
			p = p->next;
		}// while

		if (max == h)
			h = h->next;
		else
			maxpre->next = max->next;
		max->next = L;// 头插法，插入max
		L = max;
	}
}

//void SelectSort3(LinkList& L) {
//	LNode* p, * min,*minpre, * q,*qpre;
//	q = L;
//	while (q && q->next) {
//		p = q;// 每趟开始位置
//		min = p;
//		minpre = qpre;
//		while (p->next)
//			if (p->next->data < p->data) {
//				minpre = min;
//				min = p->next;// 记录min结点
//			}
//		if (min != q) {
//			if(minpre)// min不是头结点
//				minpre->next = min->next;// 摘下min结点
//			min->next = q;
//			if(qpre)//q不是头结点
//				qpre->next = min;
//		}
//		qpre = q;
//		q = q->next;
//	}
//}