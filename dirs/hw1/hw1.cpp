/*
 * 과제1 주어진 정수 배열의 평균값(mean), 중간값(median), 최빈값(mode)을 구하기
 * 제출기한: 2016년 3월20일 월요일 밤
 */

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <limits.h> // INT_MIN 등
#include <stdio.h> // printf, scanf 등 C 표준입출력
#include <stdlib.h> // srand, rand 등

#include <iostream> // cout, cin 등 C++ 표준입출력 
#include <algorithm> // sort를 불러다 쓰려고
using namespace std;

// 처음에는 작은 N으로 시작해 나중에는 좀더 더 큰 값으로 바꿔서 시험해 볼 것
const int N = 12;

void init(int* p, int n)
{
	srand(314); // 적당한 시드값을 줌
	// 참고로 시드값이 고정되면 항상 같은 순서로 값 생성
	for (int i = 0; i < n; ++i)
       	{
		p[i] = rand() % 10; // 0-9 사이의 수 생성
	}
}

void sort(int* p, int n) // 이건 내용은 몰라도 되고 그냥 갖다쓰면 됩니다
{
	std::sort(p, p+n); // 그냥 C++ 표준라이브러리 정렬함수 호출로 구현
}

int main(void)
{
	// 평균값은 나눗셈이 들어갈 것이므로 부동소수점 타입으로
	double mean = 0.0/0.0; // -nan 으로 초기화

	// 홀수인 경우는 정확히 중간에 오는 값으로
	// (예를 들어 1,2,3,4,5의 median은 3)
	// 배열의 개수가 짝수이면 둘 중 더 큰 값으로
	// (예를 들어 1,2,3,4 의 median은 3으로 간주)
	int median = INT_MIN; // 가장 작은 int 값으로 초기화

	// 최빈값이 하나만 있는 경우도 있지만
	// (예를 들어 1,2,2,2,4 의 경우는 2)
       	// 최빈값도 여러 개 있을 경우 그 중 가장 큰 값으로 하는 것으로 하자
	// (예를 들어 1,2,2,3,4,4 의 경우는 4)
	int mode = INT_MIN; // 가장 작은 int 값으로 초기화

	int a[N];
	init(a, N); // A를 초기화

	// 배열a에 들어있는 정수값들을 for문으로 돌려서 출력해줌
	for (int i=0; i<N; ++i)
       	{
	       	cout <<a[i] <<" ";
       	}
	cout <<endl <<endl;

	///////////////////////////////////////////////////

	////////////////////////////////////////////
	//
	// 여기에 자신의 프로그램 작성. 화이팅 !!!
	//
	////////////////////////////////////////////
	
	////////////////////////////////////////////////////

	cout <<"mean = " <<mean <<endl;
	cout <<"median = " <<median <<endl;
	cout <<"mode = " <<mode <<endl;

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
