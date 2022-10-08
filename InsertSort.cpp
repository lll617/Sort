#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ֱ�Ӳ�������

void InsertSort(int A[], int n)
{
	int i, j, temp;
	for ( i = 1; i < n; i++)// ����Ԫ�ز������ź����������(��һ��Ԫ�ؿ�������
	{
		if (A[i]<A[i-1])// ��A[i]�ؼ���С��ǰ��
		{
			temp = A[i];// temp�ݴ�A[i]
			for ( j = i-1; j>=0&&A[j]>temp; j--)// ���ǰ�������ź����Ԫ��
			{
				A[j+1] = A[j];// ���д���tempԪ�ض�������
			}
			A[j + 1] = temp;// ���Ƶ�����λ��
		}
	}
}


// ֱ�Ӳ������򣨴��ڱ���
void InsertSort2(int A[], int n) {
	int i, j;
	for ( i = 2; i < n; i++)// ���ν�A[2]-A[n]���뵽ǰ����������
	{
		if (A[i]<A[i-1])// ��A[i]�ؼ���С��ǰ��������������
		{
			A[0] = A[i];// ����Ϊ�ڱ���A[0]�����Ԫ��
			for ( j = i-1; A[j]>A[0]; j--)// �Ӻ���ǰ���Ҵ�����λ��
			{
				A[j + 1] = A[j];// �����ڱ�������Ų
			}
			A[j + 1] = A[0];// ���Ƶ�����λ��
		}
	}
}


// �۰��������
void InsertSort3(int A[], int n)
{
	int i, j, low, high, mid;
	for ( i = 2; i < n; i++)// ���ν�A[2]-A[n]���뵽ǰ�������
	{
		A[0] = A[i];// �ڱ���A[0]�ݴ�A[i]
		low = 1; high = i - 1;// �����۰���ҵķ�Χ
		while (low <=high)// �۰���ң�Ĭ�ϵ�������
		{
			mid = (low + high) / 2;// ȡ�м��
			if (A[mid] > A[0])
				high = mid - 1;// ������
			else// ����A[mid]<=A[0]
				low = mid + 1;// ���Ұ��
		}
		for ( j = i-1; j>=low; j--)
		{
			A[j + 1] = A[j];// ͳһ����Ԫ�أ��ճ�����λ��
		}
		A[low] = A[0];// �������
	}
}


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

// ��������в�������
LNode* InsertSort3(LinkList &L){
	if (L == NULL)
		return L;
	// �ƽ��
	LNode* dummy = (LNode*)malloc(sizeof(LNode));
	dummy->next = L;
	LNode* cur = L;
	LNode* insert, * prehead;
	while (cur->next) {
		// �ҵ�������Ľ��cur->next
		if (cur->data <= cur->next->data)
			cur = cur->next;
		else {
			// ժ��insert = cur->next
			insert = cur->next;
			cur->next = insert->next;
			prehead = dummy;
			// ��ͷ����ҵ�insert����λ�ã���һ����insert��ģ�
			while (prehead->next->data < insert->data)
				prehead = prehead->next;
			// ����
			insert->next = prehead->next;
			prehead->next = insert;
		}
	}
	return dummy->next;// ����ͷ���

}


// ϣ������
void ShellSort(int A[], int n) {
	int d, i, j;
	// A[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ���ѵ�����λ��
	for(d=n/2; d>=1; d=d/2)
		for(i=d+1; i<=n; i++)// ���洦���ӱ�
			if (A[i] < A[i - d]) {// ��A[i]�������������ӱ�
				A[0] = A[i];// �ݴ�A[i]��A[0]
				for (j = i - d; j >= 0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];// ��¼���ƣ�����ʱj+dΪ����λ�ã�jλ�ñ�A[0]С��
				A[j + d] = A[0];// ����
			}
}

void ShellSort2(int A[], int n) {
	int d, i, j,k;
	// A[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ���ѵ�����λ��
	for (d = n / 2; d >= 1; d = d / 2)
		for (i = d + 1; i <= n; i++)
			for(k=i; k<=n; k+=d)// һ��һ�������ӱ�
				if (A[k] < A[k - d]) {// ��A[i]�������������ӱ�
					A[0] = A[k];// �ݴ�A[i]��A[0]
					for (j = k - d; j >= 0 && A[0] < A[j]; j -= d)
						A[j + d] = A[j];// ��¼���ƣ�����ʱj+dΪ����λ�ã�jλ�ñ�A[0]С��
					A[j + d] = A[0];// ����
				}
}