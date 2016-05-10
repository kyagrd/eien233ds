
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

int searchBST(int n, tree* t) { // 반복문으로 작성
	while (t) // t!=NULL
	{
		if (n == t->data) return 1; // 있다

		if (n < t->data)
			t = t->left;
		else t = t->right;
	}
	return 0; // 못찾았다
	/*
	if (t == NULL) return 0; // 없다

	if (n < t->data) return searchBST(n, t->left);
	if (n > t->data) return searchBST(n, t->right);

	// if (n == t->data)
	return 1; // 있다
	*/
}

// 자습: 반복문으로 바꿔보기 (제출은 안해도 됨)
tree* insertBST(int n, tree* t) {
	if (t == NULL) return node(n, NULL, NULL);

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

tree* deleteBST(int n, tree* t) {
	if (t == NULL) return t;

	if (n == t->data) { // root를 지움
		if (t->right) { // 오른쪽의 최소값 가져오기
			int m = minBST(t->right);
			tree* rt = deleteBST(m, t->right);
			return node(m, t->left, rt);
		}
		else if (t->left) { // 왼쪽 최대값 가져오기
				int m = maxBST(t->left);
			tree* lt = deleteBST(m, t->left);
			return node(m, lt, t->right);
		} // t->left == NULL && t->right == NULL
		else return NULL;
	}
	else if (n < t->data) {
		t->left = deleteBST(n, t->left);
		return t;
	}
	else if (n > t->data) {
		t->right = deleteBST(n, t->right);
		return t;
	}
}

struct Set {
	tree* t;
	int t_size;
	int size() { return t_size; }
	int max() { return maxBST(t); }
	int min() { return minBST(t); }
	int member(int n) { return searchBST(n,t);  }
	int insert(int n) {
		if (searchBST(n, t)) return 0;
		t = insertBST(n, t);
		++t_size;
		return 1;
	}
	int remove(int n) {
		if (!searchBST(n, t)) return 0;
		t = deleteBST(n,t);
		--t_size;
		return 1;
	}
	// to_list // Set을 리스트로 변환해주는 함수
};

// Set union(Set a, Set b); // 합집합
// Set intersect(Set a, Set b); // 교집합
// Set minus(Set a, Set b); // 차집합


int main()
{
	Set s1 = { NULL, 0 };
	s1.insert(5);
	s1.insert(3);
	s1.insert(1);
	s1.insert(6);
	s1.insert(7);
	s1.insert(4);

	printBST(s1.t);
	cout << endl;
	cout << s1.size() << endl;

	s1.remove(3);

	printBST(s1.t);
	cout << endl;
	cout << s1.size() << endl;


	Set s2 = { NULL, 0 };
	s2.insert(1);
	s2.insert(2);
	s2.insert(3);
	s2.insert(4);
	s2.insert(5);
	s2.insert(6);

	printBST(s2.t);
	cout << endl;

	getchar();
	return 0;
	//////////////////////////////////////
	tree *t3 = node(3, node(1, NULL, NULL),
		               node(6, NULL, NULL));
	tree *t4 = node(7, node(4, NULL, NULL),
		               NULL);
	tree* tt = node(5, t3, t4);

	if (isBST(tt)) cout << "tt is BST." << endl;
	else cout << "tt is not BST." << endl;

	tree *t5 = node(3, node(1, NULL, NULL),
		               node(4, NULL, NULL));
	tree *t6 = node(7, node(6, NULL, NULL),
		               NULL);
	tree* ttt = node(5, t5, t6);

	if (isBST(ttt)) cout << "ttt is BST." << endl;
	else cout << "ttt is not BST." << endl;

	// sharelatex 에 붙여넣을 수 있는 형태 출력
	printBST(ttt);
	cout << endl;

	if (searchBST(4, ttt))
		cout << "found 4 in ttt" << endl;

	if (searchBST(2, ttt))
		cout << "found 2 in ttt" << endl;

	ttt = insertBST(2, ttt);

	if (searchBST(2, ttt))
		cout << "found 2 in ttt after insert" << endl;

	// sharelatex 에 붙여넣을 수 있는 형태 출력
	printBST(ttt);
	cout << endl;

	ttt = deleteBST(3, ttt);

	printBST(ttt);
	cout << endl;

	getchar();
	return 0;
}
