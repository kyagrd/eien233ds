// ConsoleApplication4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int choose(int n, int k) {
	if (n < k) return 0;
	if (k < 1) return 1; // k==0
	return choose(n -1 , k - 1) + choose(n - 1, k);
}

int fact(int n) {
	if (n < 1) return 1;
	return n * fact(n-1);
}

int ch(int n, int k) { // 공식으로 구한 choose
	// n! / (n-k)! k!
	return fact(n) / (fact(n - k)*fact(k));
}

int main()
{
	printf("%d\n", choose(10, 5));
	printf("%d\n", ch(10, 5));
	getchar();
    return 0;
}

