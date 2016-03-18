/*
 * 과제2 주어진 정수 리스트의 순서를 거꾸로 뒤집은 리스트 만들기
 * 제출기한: 2016년 3월27일 월요일 밤
 */

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <stdio.h> // printf, scanf 등 C 표준입출력
#include <stdlib.h> // srand, rand 등

#include <iostream> // cout, cin 등 C++ 표준입출력 
using namespace std;

// 처음에는 작은 N으로 시작해 나중에는 좀더 더 큰 값으로 바꿔서 시험해 볼 것
const int N = 12;


struct list { int data; list* next; };

list* cons_many(list* l, int n)
{
	list* p = l;

	srand(314); // 적당한 시드값을 줌
	// 참고로 시드값이 고정되면 항상 같은 순서로 값 생성
	for (int i = 0; i < n; ++i)
       	{
		p = new list( { rand() % 10, p } );
	}

	return p;
}

void init(int* p, int n)
{
	srand(314); // 적당한 시드값을 줌
	// 참고로 시드값이 고정되면 항상 같은 순서로 값 생성
	for (int i = 0; i < n; ++i)
       	{
		p[i] = rand() % 10; // 0-9 사이의 수 생성
	}
}

int* next(int* p) { return p+1; };
list* next(list* p) { return p->next; }

int main(void)
{
	int arr[N];
	init(arr, N); // arr 초기화

	{ //////////////////////////// array block begin
	int* begin = arr;
	int* end = arr+N; // 1 next last element
	// for (int* p = arr; p != arr+N; ++p)
	for (int* p = begin; p != end; p = next(p))
	{
	       	cout <<*p <<" ";
	}
	cout <<endl <<endl;
	} //////////////////////////// array block end


	list* l1 = cons_many(NULL, N); // l1 초기화

	{ /////////////////////////// list block begin
	list* begin = l1;
	list* end = NULL;
	// for (list* p = l1; p != NULL; p = p->next)
	for (list* p = begin; p != end; p = next(p))
       	{
	       	cout <<p->data <<" ";
       	}
	cout <<endl <<endl;
	} //////////////////////////// list block end

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
