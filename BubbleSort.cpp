#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 交换
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = a;
}

// 冒泡排序
void BubbleSort(int A[], int n) {
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++) {// 共n-1趟冒泡
		flag = false;// 标记本趟冒泡是否发生交换
		for (j = n - 1; j >= i; j--)// 一趟冒泡过程
			if (A[j - 1] > A[j]) {// 若逆序
				swap(A[j - 1], A[j]);// 交换
				flag = true;
			}
		if (flag == false)// 本趟遍历没有发生交换，说明表已经有序
			return;
	}
}

void BubbleSort2(int A[], int n) {
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++) {// n-1趟冒泡
		flag = false;
		for(j = 0;j<n-1-i;i++)// 每趟冒泡
			if (A[j] > A[j + 1]) {// 若逆序
				swap(A[j], A[j + 1]);
				flag = true;
			}
		if (flag == false)
			return;
	}
}

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;

// 链表冒泡排序（交换数据域）
void LinkListBubble(LinkList& L) {
	LNode* p, * q;
	LNode* tail = L;
	int temp;
	bool flag;
	while (tail->next != NULL)// tail指向最后一个结点
		tail = tail->next;
	while (L != tail) {// 每次冒泡依次，让tail指向它前面的结点，tail=L时结束
		flag = false;
		p = L;
		while (p != tail) {// 当p==tail时，p->next无意义
			if (p->data > p->next->data) {// 逆序则交换
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
				flag = true;
			}
			q = p;// q记录tail前面的结点位置
			p = p->next;
		}
		if (flag == false)// 未发生交换，已经有序
			return;
		tail = q;// tail指向前面的一个结点
	}
}


// 链表冒泡排序（交换结点）
void LinkListBubble(LinkList& L) {
	LNode* p, * q,*pre;// p为工作指针，pre为p前驱，q为p后继
	LNode* tail = L;
	bool flag;
	while (tail->next != NULL)// tail指向最后一个结点
		tail = tail->next;
	while (L != tail) {// 每次冒泡依次，让tail指向它前面的结点，tail=L时结束
		flag = false;
		p = L;
		q = p->next;
		while (p != tail) {// 当p==tail时，p->next无意义
			if (p->data > q->data) {// 逆序则交换
				if (p == L) {
					p->next = q->next;
					q->next = p;
					pre = q;
				}
				else {
					p->next = q->next;
					q->next = p;
					pre->next = q;
				}
				flag = true;
			}
			pre = q;// pre记录tail前面的结点位置
			p = p->next;
			q = p->next;
		}
		if (flag == false)// 未发生交换，已经有序
			return;
		tail = pre;// tail指向前面的一个结点
	}
}
