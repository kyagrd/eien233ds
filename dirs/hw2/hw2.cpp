/*
 * 과제2 주어진 정수 리스트의 순서를 거꾸로 뒤집은 리스트 만들기
 * 제출기한: 2016년 3월28일 월요일 밤
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

int main(void)
{
	list* l1 = cons_many(NULL, N); // A를 초기화

	// 리스트 l1에 들어있는 정수값들을 for문으로 돌려서 출력해줌
	for (list* p = l1; p != NULL; p = p->next)
       	{
	       	cout <<p->data <<" ";
       	}
	cout <<endl <<endl;

	///////////////////////////////////////////////////

	list* l2 = NULL; // 필요하다면 초기값을 다른 것으로 수정해도 됨

	////////////////////////////////////////////
	//
	// 여기에 자신의 프로그램 작성. 화이팅 !!!
	//
	////////////////////////////////////////////
	
	// 리스트 l2에 들어있는 정수값들을 for문으로 돌려서 출력해줌
	for (list* p = l2; p != NULL; p = p->next)
       	{
	       	cout <<p->data <<" ";
       	}
	cout <<endl <<endl;

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
