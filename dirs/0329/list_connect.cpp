
#include "stdafx.h"

#include <iostream>
using namespace std;

#include <stdio.h>

struct list { int data; list* next; };

list* cons(int n, list* l) {
	return new list({n,l});
}
void print_list(list* l) {
	for (list* p = l; p != NULL; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}
int main(void)
{
	list* l1 = cons(1,cons(2,cons(3,NULL)));
	list* l2 = cons(4,cons(5,cons(6,NULL)));

	print_list(l1);
	print_list(l2);

	// 이어붙이기
	// l1->next->next->next = l2;
	list* p = l1;
	while (p->next != NULL) { p = p->next; }
	// while 끝나면 p->next == NULL
	p->next = l2;

	print_list(l1); // 6개
	print_list(l2); // 3개

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}
