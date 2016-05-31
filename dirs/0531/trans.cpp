#include "stdafx.h"
#include <limits.h>
#include <iostream>
using namespace std;

struct edge { int x; int y; };
// 크기비교 x를 우선 비교하고 같은 경우는 y를 비교
bool operator == (edge e1, edge e2) {
	return e1.x == e2.x && e1.y == e2.y;
}
bool operator < (edge e1, edge e2) {
	if (e1.x < e2.x) return true;
	if (e1.x == e2.x) return e1.y < e2.y;

	return false;
}
bool operator > (edge e1, edge e2) {
	if (e1.x > e2.x) return true;
	if (e1.x == e2.x) return e1.y > e2.y;

	return false;
}
bool operator <= (edge e1, edge e2) {
	return e1 < e2 || e1 == e2;
}
bool operator >= (edge e1, edge e2) {
	return e1 > e2 || e1 == e2;
}


struct list { edge data; list* next; };

list* cons(edge e, list* p) {
	return new list({e,p});
}

struct tree { edge data; tree* left; tree* right; };

tree* node(edge e, tree* tl, tree* tr) {
	return new tree({ e, tl, tr });
}

list* append(list* l1, list* l2) {
	if (l1 == NULL) return l2;

	return cons(l1->data, append(l1->next, l2));
}

list* inorder(tree* t) {
	if (t == NULL) return NULL;

	list* l1 = inorder(t->left);
	list* l2 = inorder(t->right);
	return append(l1, cons(t->data, l2));
}

edge minBST(tree* t) {
	if (t == NULL) return {INT_MAX, INT_MAX};
	tree* p = t;
	while (p->left) p = p->left;
	return p->data;
}

edge maxBST(tree* t) {
	if (t == NULL) return {INT_MIN,INT_MIN};
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
}*/

int searchBST(edge e, tree* t) { // 반복문으로 작성
	while (t) // t!=NULL
	{
		if (e == t->data) return 1; // 있다

		if (e < t->data)
			t = t->left;
		else t = t->right;
	}
	return 0;
}

// 자습: 반복문으로 바꿔보기 (제출은 안해도 됨)
tree* insertBST(edge e, tree* t) {
	if (t == NULL) return node(e, NULL, NULL);

	if (e < t->data) {
		if (t->left == NULL)
			t->left = node(e, NULL, NULL);
		else
			insertBST(e, t->left);

		return t;
	}

	if (e > t->data) {
		if (t->right == NULL)
			t->right = node(e, NULL, NULL);
		else
			insertBST(e, t->right);

		return t;
	}

	// if (n == t->data)
	return t;
}

tree* deleteBST(edge e, tree* t) {
	if (t == NULL) return t;

	if (e == t->data) { // root를 지움
		if (t->right) { // 오른쪽의 최소값 가져오기
			edge m = minBST(t->right);
			tree* rt = deleteBST(m, t->right);
			return node(m, t->left, rt);
		}
		else if (t->left) { // 왼쪽 최대값 가져오기
			edge m = maxBST(t->left);
			tree* lt = deleteBST(m, t->left);
			return node(m, lt, t->right);
		} // t->left == NULL && t->right == NULL
		else return NULL;
	}
	else if (e < t->data) {
		t->left = deleteBST(e, t->left);
		return t;
	}
	else if (e > t->data) {
		t->right = deleteBST(e, t->right);
		return t;
	}
}

struct Set {
	tree* t;
	int t_size;
	int size() { return t_size; }
	edge max() { return maxBST(t); }
	edge min() { return minBST(t); }
	int member(edge e) { return searchBST(e, t); }
	int insert(edge e) {
		if (searchBST(e, t)) return 0;
		t = insertBST(e, t);
		++t_size;
		return 1;
	}
	int remove(edge e) {
		if (!searchBST(e, t)) return 0;
		t = deleteBST(e, t);
		--t_size;
		return 1;
	}
	// Set을 inorder 리스트로 변환해주는 함수
	list* to_list() { return inorder(t); }
};

// Set union(Set a, Set b); // 합집합
// Set intersect(Set a, Set b); // 교집합
// Set minus(Set a, Set b); // 차집합


int main()
{
	Set e = { NULL, 0 };
	e.insert({ 1,2 });
	e.insert({ 2,3 });
	e.insert({ 3,1 });

	Set et = { NULL, 0 }; // Et는 E의 원소 포함
	et.insert({ 1,2 });
	et.insert({ 2,3 });
	et.insert({ 3,1 });

	while (1) {
		int old_size = et.size();
		// 모든 E의 (u,v)에 대해서
		for (list* p = e.to_list(); p; p = p->next) {
			int u = p->data.x;
			int v = p->data.y;

			// w를 V의 범위에 대해서 for
			for (int w = 1; w <= 3; ++w) {
				// Et에 (v,w)가 있으면
				// Et에 (u,w) 추가
				if (et.member({ v, w }))
					et.insert({ u, w });
			}
		}
		if (old_size == et.size()) break;
	}


	cout << "Printing Et" << endl;
	for (list* p = et.to_list(); p; p = p->next) {
		cout << "(" << p->data.x
			<< "," << p->data.y << ") ";
	}
	cout << endl;
	cout << et.size() << endl;

	getchar();
	return 0;

	/*
	Set e1 = { NULL, 0 };
	e1.insert({ 1,2 });
	e1.insert({ 2,3 });
	e1.insert({ 3,1 });

	cout << "Printing E1" << endl;
	for (list* p = e1.to_list(); p; p = p->next) {
		cout << "(" << p->data.x

			<< "," << p->data.y << ") ";
	}
	cout << endl;
	cout << e1.size() << endl;


	Set e2 = { NULL, 0 };
	// e1의 원소를 모두 포함
	e2.insert({ 1,2 });
	e2.insert({ 2,3 });
	e2.insert({ 3,1 });

	// 모든 E1의 (u,v)에 대해서
	for (list* p = e1.to_list(); p; p = p->next) {
		int u = p->data.x;
		int v = p->data.y;

		// w를 V의 범위에 대해서 for
		for (int w = 1; w <= 3; ++w) {
			// E1에 (v,w)가 있으면 E2에 (u,w) 추가
			if (e1.member({ v, w }))
				e2.insert({ u, w });
		}
	}

	cout << "Printing E2" << endl;
	for (list* p = e2.to_list(); p; p = p->next) {
		cout << "(" << p->data.x

			<< "," << p->data.y << ") ";
	}
	cout << endl;
	cout << e2.size() << endl;


	Set e3 = { NULL, 0 };
	// e2의 원소를 모두 포함
	e3.insert({ 1,2 });
	e3.insert({ 2,3 });
	e3.insert({ 3,1 });
	e3.insert({ 1,3 });
	e3.insert({ 2,1 });
	e3.insert({ 3,2 });

	// 모든 E1의 (u,v)에 대해서
	for (list* p = e1.to_list(); p; p = p->next) {
		int u = p->data.x;
		int v = p->data.y;

		// w를 V의 범위에 대해서 for
		for (int w = 1; w <= 3; ++w) {
			// E2에 (v,w)가 있으면 E3에 (u,w) 추가
			if (e2.member({ v, w }))
				e3.insert({ u, w });
		}
	}

	cout << "Printing E3" << endl;
	for (list* p = e3.to_list(); p; p = p->next) {
		cout << "(" << p->data.x

			<< "," << p->data.y << ") ";
	}
	cout << endl;
	cout << e3.size() << endl;

	getchar();
	return 0;
	*/
}

