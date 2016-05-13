// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <limits.h>
#include <iostream>
using namespace std;

struct entry {
	int key; // 학번
	char* value; // 이름
};

struct tree { entry* data; tree* left; tree* right; };

tree* node(entry* e, tree* tl, tree* tr) {
	return new tree({ e, tl, tr });
}

entry* minBST(tree* t) {
	if (t == NULL) return NULL;
	tree* p = t;
	while (p->left) p = p->left;
	return p->data;
}

entry* maxBST(tree* t) {
	if (t == NULL) return NULL;
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
/*
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
*/
entry* searchBST(int n, tree* t) {
	if (t == NULL) return NULL; // 없다

	if (n < t->data->key)
		return searchBST(n, t->left);
	if (n > t->data->key)
		return searchBST(n, t->right);

	// if (n == t->data)
	return t->data;  // 있다
}

tree* insertBST(entry* e, tree* t) {
	if (t == NULL) return node(e,NULL,NULL);

	if (e->key < t->data->key) {
		if (t->left == NULL)
			t->left = node(e, NULL, NULL);
		else
			insertBST(e, t->left);

		return t;
	}

	if (e->key > t->data->key) {
		if (t->right == NULL)
			t->right = node(e, NULL, NULL);
		else
			insertBST(e, t->right);

		return t;
	}

	// if (n == t->data)
	return t;
}


struct Map { // 학번을 이름에 대응
	tree* t;
	entry* find(int k) {
		return searchBST(k);
	}
	entry* update(int k, char* data);
	// entry* remove(int k);
};

// 아직 update 작업중

int main(int argc, char **argv)
{
	getchar();
	return 0;
}


