// insertion sort

#include "stdafx.h"
// const int N = 10;

#define N 10

// k를 a에 삽입
void insert(int k, int a[], int n) {
	int i;
	for (i = 0; i < n-1; ++i) {
		if (k <= a[i]) break;
	}
	for (int j = n-1; j > i; --j) {
		a[j] = a[j - 1];
	}
	a[i] = k;
}

void isort(int a[], int n) {
	for (int m = 1; m < n; ++m) {
		int k = a[m];
		insert(k, a, m+1);
	}
}

int main()
{
	int a[N] = {5,7,2,8,4,6,9,1,3,0};
	isort(a, N);
	for (int i = 0; i < N; ++i)
		printf("%d ", a[i]);
	getchar();
	return 0;
}

