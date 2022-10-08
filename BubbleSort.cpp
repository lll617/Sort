#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ����
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = a;
}

// ð������
void BubbleSort(int A[], int n) {
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++) {// ��n-1��ð��
		flag = false;// ��Ǳ���ð���Ƿ�������
		for (j = n - 1; j >= i; j--)// һ��ð�ݹ���
			if (A[j - 1] > A[j]) {// ������
				swap(A[j - 1], A[j]);// ����
				flag = true;
			}
		if (flag == false)// ���˱���û�з���������˵�����Ѿ�����
			return;
	}
}

void BubbleSort2(int A[], int n) {
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++) {// n-1��ð��
		flag = false;
		for(j = 0;j<n-1-i;i++)// ÿ��ð��
			if (A[j] > A[j + 1]) {// ������
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

// ����ð�����򣨽���������
void LinkListBubble(LinkList& L) {
	LNode* p, * q;
	LNode* tail = L;
	int temp;
	bool flag;
	while (tail->next != NULL)// tailָ�����һ�����
		tail = tail->next;
	while (L != tail) {// ÿ��ð�����Σ���tailָ����ǰ��Ľ�㣬tail=Lʱ����
		flag = false;
		p = L;
		while (p != tail) {// ��p==tailʱ��p->next������
			if (p->data > p->next->data) {// �����򽻻�
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
				flag = true;
			}
			q = p;// q��¼tailǰ��Ľ��λ��
			p = p->next;
		}
		if (flag == false)// δ�����������Ѿ�����
			return;
		tail = q;// tailָ��ǰ���һ�����
	}
}


// ����ð�����򣨽���������
void LinkListBubble(LinkList& L) {
	LNode* p, * q,*pre;// pΪ����ָ�룬preΪpǰ����qΪp���
	LNode* tail = L;
	bool flag;
	while (tail->next != NULL)// tailָ�����һ�����
		tail = tail->next;
	while (L != tail) {// ÿ��ð�����Σ���tailָ����ǰ��Ľ�㣬tail=Lʱ����
		flag = false;
		p = L;
		q = p->next;
		while (p != tail) {// ��p==tailʱ��p->next������
			if (p->data > q->data) {// �����򽻻�
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
			pre = q;// pre��¼tailǰ��Ľ��λ��
			p = p->next;
			q = p->next;
		}
		if (flag == false)// δ�����������Ѿ�����
			return;
		tail = pre;// tailָ��ǰ���һ�����
	}
}