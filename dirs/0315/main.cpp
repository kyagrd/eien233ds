#include "stdafx.h"

#include <iostream>
using namespace std;

#include <stdio.h>

#define N 5
// const int N = 5;

typedef int MyInt;

typedef int MyArray[3][4];

struct Point2D { float x; float y; };

int f(void) {
	int n = 3; // 4 byte

	Point2D p1 = { 3.4f, (float)5.6 };

	return 0;
}


int f2(void) {
	Point2D* p_point = new Point2D({3.4f, 5.6f});
	int* p = new int(3); // 4 byte
	int* p_array = new int[5]; // 배열 동적 할당


	return 0;
}

// struct Point2D { float x; float y; };
struct list { int val; list* next; };

int main(void)
{
	// { 1,2,3,4,5 } 배열은 이렇게 초기화 했었는데

	list* empty_list = NULL;
	// [ 1 ]
	list* l1 = new list({ 1, empty_list });
	// [ 2, 1 ]
	list* l2 = new list({ 2, l1 });
	// [ 3, 2, 1 ]
	list* l3 = new list({ 3, l2 });
	// [ 5, 3, 2, 1 ]
	list* l4 = new list({ 5, l3 });

	for (list *p = l4; p != NULL; p = p->next)
	{
		// printf("%d ", p->val);
		cout <<p->val << " ";
	}

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;


	Point2D p1 = { 3.4f, 5.6f };
	Point2D* p_point = new Point2D({3.4f, 5.6f});

	printf("p1 = { %f, %f } \n", p1.x, p1.y);
	cout << "p1 = ";
	cout <<"{" <<p1.x <<"," <<p1.y <<"}" <<endl;








	for (int i = 0; i < 10000; ++i) {
		// f();
		int n = 3;
	} // 메모리 사용량 변화 없음

	for (int i = 0; i < 10000; ++i) {
		// f2();
		int* p = new int(3);
	} // 40000 바이트 메모리를 계속 사용중


	MyInt n1 = 3; // int n = 3;

	MyArray arr2; // int arr[3][4];

	MyArray* p2 = new MyArray[N]; // 5 x 3 x 4


	int a[N] = { 9, 5, 4, 3, 2 };

	for (int i = 0; i < N; ++i) {
		// cout << a[i] << endl;
		cout << *(a + i) << endl;
	}

	cout <<"sizeof(a) = " <<sizeof(a) << endl;

	// int* p = a;
	int* p = new int[5];
	for (int i = 0; i < N; ++i) {
		// cout << *(p + i) << endl;
		p[i] = i;
	}

	for (int i = 0; i < N; ++i) {
		// cout << *(p + i) << endl;
		cout << p[i] << endl;
	}

	cout << "sizeof(p) = " << sizeof(p) << endl;


#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
