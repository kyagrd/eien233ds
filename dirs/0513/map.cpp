// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
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
		return searchBST(k, t);
	}
	entry* update(int k, char* data) {
		entry* p = find(k);
		if (p) p->value = data;
		else {
			p = new entry({k,data});
			t = insertBST(p,t);
		}
		return p;
	}
	// entry* remove(int k);
};

int main(void)
{
	Map m = { NULL };
	m.update(1998010101,"김동성");
	m.update(2009000000,"김연아");
	m.update(1972000111,"차범근");
	m.update(1988000111,"서정원");
	m.update(1999000111,"차두리");
	m.update(2000999999,"이천수");
	m.update(1990999999,"김수녕");
	
	entry* p1 = m.find(2009000000);
	if (p1) cout <<p1->value <<endl;
	else cout <<2009000000 <<" not found" <<endl;

	entry* p2 = m.find(2007010101);
	if (p2) cout <<p2->value <<endl;
	else cout <<2007010101 <<" not found" <<endl;

	m.update(2007010101,"김자인");

	entry* p3 = m.find(2007010101);
	if (p3) cout <<p3->value <<endl;
	else cout <<2007010101 <<" not found" <<endl;

	getchar();
    return 0;
}
