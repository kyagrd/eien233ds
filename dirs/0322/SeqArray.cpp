// 콘솔 응용 프로그램 진입점 정의

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 128;

struct Sequence {
	int length;
	int arr[N];

	// Sequence 구조체와 관계된 함수들
	int size(void) { return length; }
	int* begin() { return arr; }
	int* end() { return arr+length; }
	int* next(int* p) { return p+1; }
	int* insert(int* ptr, int data) {
		if (length < N) {
			for(int* p=end(); p != ptr; --p) { *p = *(p-1); }
			*ptr = data;
			++length;
		} else {
		       	cerr <<"ERROR: insert failure - ";
			cerr <<"Sequence already reached its maximun size " <<N;
			cerr <<endl;
		}
	}
	int* push_front(int data) { insert( begin(), data ); }
	int* push_back(int data) { insert( begin()+length, data ); }
};


int main(void)
{
	Sequence seq = { 0 }; // legnth = 0 으로 초기화
	seq.push_back(5);
	seq.push_back(4);
	seq.push_back(3);
	seq.push_back(2);
	seq.push_back(1);

	cout <<"size: " <<seq.size() <<endl;
	cout <<"contents: ";
	for ( int* p = seq.begin(); p != seq.end(); p = seq.next(p) ) {
		cout <<*p <<" ";
	}
	cout <<endl;


#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
