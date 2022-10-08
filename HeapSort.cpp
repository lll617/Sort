#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void BuildMaxHeap(int A[], int len) {
	for (int i = len/2; i >0; i--){// �Ӻ���ǰ�������з�֧���
		HeadAdjust(A, i, len);
	}
}

// ����kΪ������������Ϊ�����
void HeadAdjust(int A[], int k, int len) {
	A[0] = A[k];		// A[0]�ݴ������ĸ����
	for (int i = 2 * k; i <= len; i *= 2) {// ��key�ϴ���ӽ������ɸѡ
		if (i < len && A[i] < A[i + 1])
			i++;		// ȡkey�ϴ���ӽ���±�
		if (A[0 >= A[i]])	// ɸѡ����
			break;
		else {
			A[k] = A[i];	// ��A[i]��ֵ������˫�׽����
			k = i;			// �޸�kֵ���Ա��������ɸѡ
		}
	}
	A[k] = A[0];		// ��ɸѡ�Ľ���������λ��
}

// ������
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);		// ��ʼ����
	for (int i = len; i > 1; i--) {		// n-1�˽����ͽ��ѹ���
		swap(A[i], A[1]);		// �Ѷ�Ԫ�غͶѵ�Ԫ�ؽ���
		HeadAdjust(A, 1, i - 1);		// ��ʣ��Ĵ�����Ԫ������ɶ�
	}
}

// ����ѵĲ���
void HeapInsert(int A[], int len, int k) {
	A[++len] = k;// ��Ԫ�طŵ���β���ѵ�), ����һ
	
	int n = len;
	while (A[n] > A[n / 2]) {// ���ȸ��ڵ��������
		swap(A[n], A[n / 2]);
		n /= 2;
	}
}


// �ѵ�ɾ��
void HeapDelete(int A[], int &len, int n) {
	swap(A[n], A[len]);// ��ɾ��Ԫ���ñ�β���ѵף�Ԫ�����
	len--;// ����-1

	HeadAdjust(A, n, len);// ���Ԫ����׹
}