// 콘솔 응용 프로그램 진입점 정의

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <stdio.h>
#include <iostream>
using namespace std;

struct list { int data; list* next; };

struct Sequence {
	int length;
	list* l;

	// Sequence 구조체와 관계된 함수들
	int size(void) { return length; }
	list* begin() { return l; }
	list* end() { return NULL; }
	list* next(list* p) { return p->next; }
	list* insert_next(list* ptr, int data) {
		if (ptr == end()) {
			cerr <<"ERROR: insert_next failure - ";
			cerr <<"pointer already at the end" <<endl;
			return end();
		}

		ptr->next = new list( { data, ptr->next } );
		++length;
		return ptr->next;
	}
	list* insert(list* ptr, int data) {
		if (ptr == begin()) {
			return push_front(data);
		}

		list* prev = begin();
		while (prev->next != ptr) { prev = next(prev); }
		// prev->next == ptr  after the while loop

		return insert_next(prev, data);
	}
	list* push_front(int data) {
		l = new list( { data, l } );
		++length;
		return l;
       	}
	list* push_back(int data) { return insert( end(), data ); }
};


int main(void)
{
	Sequence seq = { 0, NULL }; // legnth = 0, l = NULL 로 초기화

	seq.push_front(5);
	seq.push_front(4);
	seq.push_front(3);
	seq.push_front(2);
	seq.push_front(1);

	seq.push_back(6);



	cout <<"size: " <<seq.size() <<endl;
	cout <<"contents: ";
	for (list* p = seq.begin(); p != seq.end(); p = seq.next(p) ) {
		cout <<p->data <<" ";
	}
	cout <<endl;


#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
