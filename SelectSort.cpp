#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ��ѡ������
void SelectSort(int A[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {// �Ƚ�n-1��
		min = i;// ��¼��СԪ�ص�λ��
		for (j = i + 1; j < n; j++)// ��A[i...n-1]��ѡ����С��Ԫ��
			if (A[j] < A[min])
				min = j;// ������СԪ��λ��
		if (min != i)// ����
			swap(A[min], A[i]);
	}
}


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;

// ��ѡ��������������������
void SelectSort2(LinkList& L) {
	LNode* p,*q=L, * min;// pΪ����ָ��
	int temp;
	while (q && q->next !=NULL) {
		p = q;// q��¼ÿ��һ��Ԫ�ص�����λ��
		min = p;
		while (p->next)// ��ֵ��С���
			if (p->next->data < p->data)
			min = p->next;
		if (min != q) {// ����
			temp = q->data;
			q->data = min->data;
			min->data = temp;
		}
		q = q->next;// q����
	}
}

// ��ѡ��������������ͷ��㣩
void SelectSort3(LinkList& L) {
	LNode* h = L, * p, * q, * max, * maxpre;
	// max��������㣬maxpreΪmaxǰ����pΪ����ָ�룬qΪpǰ��
	L = NULL;
	while (h != NULL) {
		p = max = h;
		q = maxpre = NULL;
		while (p != NULL) {// �������
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
		max->next = L;// ͷ�巨������max
		L = max;
	}
}

//void SelectSort3(LinkList& L) {
//	LNode* p, * min,*minpre, * q,*qpre;
//	q = L;
//	while (q && q->next) {
//		p = q;// ÿ�˿�ʼλ��
//		min = p;
//		minpre = qpre;
//		while (p->next)
//			if (p->next->data < p->data) {
//				minpre = min;
//				min = p->next;// ��¼min���
//			}
//		if (min != q) {
//			if(minpre)// min����ͷ���
//				minpre->next = min->next;// ժ��min���
//			min->next = q;
//			if(qpre)//q����ͷ���
//				qpre->next = min;
//		}
//		qpre = q;
//		q = q->next;
//	}
//}