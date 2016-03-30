// DS0330.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
const int N = 5;

struct list { int data; list* next; };

int main(void)
{
	// list 에 대한 반복문
	list* l0 = NULL; // 빈 리스트 l0
	list* l1 = new list({ 5, l0 });
	list* l2 = new list({ 4, l1 });
	list* l3 = new list({ 3, l2 });
	list* l4 = new list({ 2, l3 });
	list* l5 = new list({ 1, l4 });

	list* p = l5;
	cout << p->data << endl;
	p = p->next; // p가 l4와 같은 곳을 가리킴
	cout << p->data << endl;

	// 리스트에 대한 반복문
	for (list*p = l5; p != NULL; p = p->next) {
		cout << p->data <<" ";
	}
	cout << endl;


	int arr[N] = { 1,2,3,4,5 };

	// 1. index이용한 반복문
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl; // 줄바꿈

	// 2. 포인터 이용한 반복문
	for (int *p = arr; p < arr + N; ++p) {
		cout << *p << " ";
	}
	cout << endl;



	/*
	int* p = arr; // 배열의 첫번째 위치를 가리킴


	cout << arr << endl;
	cout << p << endl;
	cout << *p << endl;
	// cout << *(p + 3) << endl;

	p = p + 3;
	cout << *p << endl;
	++p; // p = p + 1;
	cout << *p << endl;

	*/





	int n = 3;
	// &n 레퍼런스 연산, (주소)참조 연산
	int* ptr = &n;
	// *ptr 디레퍼런스 연산, 역참조 연산
	// n == *(&n)
	// ptr == &(*ptr)

	cout << &n << endl;
	cout << ptr << endl;
	cout << *ptr << endl;


#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
