/*
* 과제3
*  (1) list에 대한 copy를 재귀함수로 구현
*  (2) 두 list를 연결한 새로운 리스트를 만드는
*      append 재귀함수 구현
*  (3) tree를 list로 변환하는 함수 3가지
*      preorder, postorder, inorder
*      재귀함수로 구현
* 제출기한: 2016년 4월12일 월요일 밤
*/

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <stdio.h> // printf, scanf 등 C 표준입출력
#include <stdlib.h> // srand, rand 등

#include <iostream> // cout, cin 등 C++ 표준입출력 
using namespace std;

// 처음에는 작은 N, H으로 시작해 나중에는 좀더 더 큰 값으로 바꿔서 시험해 볼 것
const int N = 12; // 리스트 길이
const int H = 3; // 트리 높이

struct list { int data; list* next; };
struct tree { int data; tree* left; tree* right; };

list* cons_many(list* l, int n)
{
	list* p = l;

	// 참고로 시드값이 고정되면 항상 같은 순서로 값 생성
	for (int i = 0; i < n; ++i)
	{
		p = new list({ rand() % 10, p });
	}

	return p;
}

tree* gen_tree(int h)
{
	if (h < 1) return NULL;

	tree* lt = gen_tree(h - 1);
	tree* rt = gen_tree(h - 1);
	return new tree({ rand() % 100, lt, rt });
}

void print_list(list* l) {
	for (list* p = l; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

list* copy(list* l) {
	////////////////////////////////////////////
	//
	// 3-(1) 여기에 자신의 프로그램 작성
	//
	////////////////////////////////////////////
	if (l == NULL) {
		return NULL;
	}
	else {
		// 길이 1 이상인 리스트
		list* p = copy(l->next); // 맨앞 뺀 나머지 복사
		return new list({l->data, p});
		// return new list({l->data,copy(l->next)});
	}
}

list* append(list* l1, list* l2) {
	////////////////////////////////////////////
	//
	// 3-(2) 여기에 자신의 프로그램 작성
	//
	////////////////////////////////////////////
	return NULL; // dummy return
}

list* preorder(tree* t) {
	////////////////////////////////////////////
	//
	// 3-(3) 여기에 자신의 프로그램 작성
	//
	////////////////////////////////////////////
	return NULL; // dummy return
}

list* postorder(tree* t) {
	////////////////////////////////////////////
	//
	// 3-(3) 여기에 자신의 프로그램 작성
	//
	////////////////////////////////////////////
	return NULL; // dummy return
}

list* inorder(tree* t) {
	////////////////////////////////////////////
	//
	// 3-(3) 여기에 자신의 프로그램 작성
	//
	////////////////////////////////////////////
	return NULL; // dummy return
}

int main(void)
{
	srand(314); // 적당한 시드값을 줌

	list* l1 = cons_many(NULL, N); // l1를 초기화
	list* l2 = cons_many(NULL, N); // l2를 초기화
	cout << "l1:" << endl;
	print_list(l1);
	cout << "l2:" << endl;
	print_list(l2);
	cout << endl;
	///////////////////////////////////////////////////

	list* l1copy = copy(l1);
	cout << "l1:" << endl;
	print_list(l1);
	cout << "l1copy:" << endl;
	print_list(l1copy);
	cout << endl;
	///////////////////////////////////////////////////

	list* l3 = append(l1, l2);
	cout << "l1:" << endl;
	print_list(l1);
	cout << "l2:" << endl;
	print_list(l2);
	cout << "l3:" << endl;
	print_list(l3);
	cout << endl;
	///////////////////////////////////////////////////

	tree* t = gen_tree(H);

	list* lpre = preorder(t);
	cout << "lpre:" << endl;
	print_list(lpre);
	cout << endl;

	list* lpost = postorder(t);
	cout << "lpost:" << endl;
	print_list(lpost);
	cout << endl;

	list* lin = inorder(t);
	cout << "lin:" << endl;
	print_list(lin);
	cout << endl;

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress Enter key to exit ...");
	getchar();
#endif

	return 0;
}

