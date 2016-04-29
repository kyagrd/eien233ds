// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <limits.h>
#include <iostream>
using namespace std;

struct tree { int data; tree* left; tree* right; };

tree* node(int n, tree* tl, tree* tr) {
	return new tree({ n, tl, tr });
}

struct list { tree* data; list* next; };

list* cons(tree* t, list* l) {
	return new list({ t,l });
}

struct List {
	list* begin;
	list* end;
	int empty() { return begin == end; }
	tree* pop_front() {
		if (empty()) {
			cout << "List empty" << endl;
			return NULL;
		}
		tree* t = begin->data;
		begin = begin->next;
		return t;
	}
	void push_front(tree* t) {
		begin = cons(t, begin);
	}
	void push_back(tree* t) {
		list* newend = cons(NULL, NULL); // 새로운 end 를 만든다
		end->data = t;
		end->next = newend;
		end = newend;
	}
};

struct Queue {
	List lis;
	int empty() { return lis.empty(); }
	void addq(tree* t) {
		return lis.push_back(t);
	}
	tree* deleteq() {
		return lis.pop_front();
	}
};

void printList(List l) {
	for (list* p = l.begin; p != l.end; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}

void levelorder(tree* t) {
	if (t == NULL) return;

	list* l = cons(NULL, NULL);
	List lis = { l, l };
	Queue q = { lis }; // 빈 큐를 만들었다

	q.addq(t);

	while (! q.empty()) {
		tree* p = q.deleteq();
		cout << p->data << " ";
		if (p->left) q.addq(p->left);
		if (p->right) q.addq(p->right);
	}
}

int minBST(tree* t) {
	if (t == NULL) return INT_MAX;
	tree* p = t;
	while (p->left) p = p->left;
	return p->data;
}

int maxBST(tree* t) {
	if (t == NULL) return INT_MIN;
	tree* p = t;
	while (p->right) p = p->right;
	return p->data;
}

int isBST(tree* t) {
	if (t == NULL) return 1;

	// 바로 아래 값들과만 비교하는 잘못된 구현
	/*
	if (t->left &&
		t->left->data >= t->data)
		return 0;
	if (t->right &&
		t->right->data <= t->data)
		return 0;
	*/

	if (t->left &&
		maxBST(t->left) >= t->data)
		return 0;
	if (t->right &&
		minBST(t->right) <= t->data)
		return 0;

	return isBST(t->left) && isBST(t->right);
}


int main()
{
	tree *t1 = node(2, node(3, NULL, NULL),
		               node(4, NULL, NULL));
	tree *t2 = node(5, NULL,
		               node(6, NULL, NULL));
	tree* t = node(1, t1, t2);

	levelorder(t);
	// 1 2 5 3 4 6
	cout << endl; cout << endl;

	tree *t3 = node(3, node(1, NULL, NULL),
		               node(6, NULL, NULL));
	tree *t4 = node(7, node(4, NULL, NULL),
		               NULL);
	tree* tt = node(5, t3, t4);

	if (isBST(tt)) {
		cout << "tt is BST." << endl;
	}
	else {
		cout << "tt is not BST." << endl;
	}

	tree *t5 = node(3, node(1, NULL, NULL),
		               node(4, NULL, NULL));
	tree *t6 = node(7, node(6, NULL, NULL),
		               NULL);
	tree* ttt = node(5, t5, t6);

	if (isBST(ttt)) {
		cout << "ttt is BST." << endl;
	}
	else {
		cout << "ttt is not BST." << endl;
	}

	getchar();
    return 0;
}
