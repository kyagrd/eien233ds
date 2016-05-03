// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <limits.h>
#include <iostream>
using namespace std;

struct tree { int data; tree* left; tree* right; };

tree* node(int n, tree* tl, tree* tr) {
	return new tree({ n, tl, tr });
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

	if (t->left &&
		maxBST(t->left) >= t->data)
		return 0;

	if (t->right &&
		minBST(t->right) <= t->data)
		return 0;

	return isBST(t->left) && isBST(t->right);
}

void printBST(tree* t) {
	if (t == NULL) { cout << "{}"; }
	else {
		cout << t->data << " -> { ";
		printBST(t->left);
		cout << ", ";
		printBST(t->right);
		cout << "}";
	}
}

int searchBST(int n, tree* t) {
	if (t == NULL)
		return 0; // 없다
	else if (n < t->data)
		searchBST(n, t->left);
	else if (n > t->data)
		searchBST(n, t->right);
	else // if (n == t->data)
		return 1; // 있다
}

tree* insertBST(int n, tree* t) {
	if (t == NULL) return node(n,NULL,NULL);

	if (n < t->data) {
		if (t->left == NULL)
			t->left = node(n, NULL, NULL);
		else
			insertBST(n, t->left);

		return t;
	}

	if (n > t->data) {
		if (t->right == NULL)
			t->right = node(n, NULL, NULL);
		else
			insertBST(n, t->right);

		return t;
	}

	// if (n == t->data)
	return t;
}

int main()
{
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

	// sharelatex 에 붙여넣을 수 있는 형태 출력
	printBST(ttt);

	if (searchBST(4, ttt)) {
		cout << "found 4 in ttt" << endl;
	}

	ttt = insertBST(2, ttt);

	if (searchBST(2, ttt)) {
		cout << "found 2 in ttt" << endl;
	}

	// sharelatex 에 붙여넣을 수 있는 형태 출력
	printBST(ttt);


	getchar();
	return 0;
}
