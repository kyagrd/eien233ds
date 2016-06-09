// insertion sort

#include "stdafx.h"
#include <iostream>
using namespace std;
// const int N = 10;

#define N 10

// k를 a에 삽입
void insert(int k, int a[], int n) {
	for (int i=n-1; i>=0; --i) {
		if (i==0) { a[0] = k; break; }
		else if (a[i-1] <= k) { a[i] = k; break; }
		else { a[i] = a[i-1]; }
	}
	/*
	int i;
	for (i = 0; i < n-1; ++i) {
		if (k <= a[i]) break;
	}
	for (int j = n-1; j > i; --j) {
		a[j] = a[j - 1];
	}
	a[i] = k;
	*/
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

