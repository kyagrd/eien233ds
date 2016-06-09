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
}
// top down
void isort(int a[], int n) {
	if (n<2) return;

	isort(a, n-1);
	insert(a[n-1], a, n);
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

