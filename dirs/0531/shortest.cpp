#include "stdafx.h"
#include <limits.h>
#include <iostream>
using namespace std;

int min(int x, int y) { return (x < y)? x : y; }

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

struct entry { edge key; int value; };

struct list { entry* data; list* next; };

list* cons(entry* e, list* p) {
	return new list({e,p});
}

struct tree { entry* data; tree* left; tree* right; };

tree* node(entry* e, tree* tl, tree* tr) {
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

	if (t->left && maxBST(t->left) >= t->data) return 0;

	if (t->right && minBST(t->right) <= t->data) return 0;

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

entry* searchBST(edge e, tree* t) { // 반복문으로 작성
	while (t) // t!=NULL
	{
		if (e == t->data->key) return t->data; // 있다

		if (e < t->data->key)
			t = t->left;
		else /* if (e > t->data->key) */
		       	t = t->right;
	}
	return NULL;
}

// 자습: 반복문으로 바꿔보기 (제출은 안해도 됨)
tree* insertBST(entry* e, tree* t) {
	if (t == NULL) return node(e, NULL, NULL);

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

tree* deleteBST(edge e, tree* t) {
	if (t == NULL) return t;

	if (e == t->data->key) { // root를 지움
		if (t->right) { // 오른쪽의 최소값 가져오기
			entry* m = minBST(t->right);
			tree* rt = deleteBST(m->key, t->right);
			return node(m, t->left, rt);
		}
		else if (t->left) { // 왼쪽 최대값 가져오기
			entry* m = maxBST(t->left);
			tree* lt = deleteBST(m->key, t->left);
			return node(m, lt, t->right);
		} // t->left == NULL && t->right == NULL
		else return NULL;
	}
	else if (e < t->data->key) {
		t->left = deleteBST(e, t->left);
		return t;
	}
	else /*if (e > t->data->key)*/ {
		t->right = deleteBST(e, t->right);
		return t;
	}
}

struct Map {
	tree* t;
	entry* find(edge k) { return searchBST(k, t); }
	entry* update(edge k, int v) {
		entry* p = find(k);
		if (p) p->value = v;
		else {
			p = new entry({k,v});
			t = insertBST(p, t);
		}
		return p;
	}
	// Map을 inorder 리스트로 변환해주는 함수
	list* to_list() { return inorder(t); }
};

int main()
{
	int N = 3; // V의 크기

	Map m = { NULL };
	m.update({0,1}, 1);
	m.update({1,2}, 2);
	m.update({0,2}, 1);

	list* e = m.to_list(); // 그래프의 원래 edge 기억

	for (int k=1; k<N; ++k) {
		// 모든 E의 (u,v)에 대해서
		for (list* p = e; p; p = p->next) {
			int u = p->data->key.x;
			int v = p->data->key.y;
			if (u==v) continue;
			int n1 = p->data->value;

			// w를 V의 범위에 대해서 for
			for (int w = 0; w < N; ++w) {
				if (u==w || v==w) continue;

				entry* e2 = m.find({ v, w });
				if (e2==NULL) continue;
				int n2 = e2->value;

				entry* e3 = m.find({ u, w });
				if (e3) {
					int n3 = e3->value;
					m.update({ u, w }, min(n1+n2, n3));
				} else // if (e3==NULL)
					m.update({ u, w }, n1+n2);
			}
		}
	}


	cout << "Printing m" << endl;
	for (list* p = m.to_list(); p; p = p->next) {
		cout << "(" << p->data->key.x
			<< "," << p->data->key.y << ")->"
		       	<<p->data->value <<" ";
	}
	cout << endl;

	getchar();
	return 0;

}

