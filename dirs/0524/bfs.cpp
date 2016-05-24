// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list { int data; list* next; };

list* cons(int n, list* p) {
	return new list({ n,p });
}

struct List {
	list* begin;
	list* end;
	int empty() { return begin == end; }
	int pop_front() {
		if (empty()) {
			cout << "List empty" << endl;
			return INT_MIN;
		}
		int n = begin->data;
		begin = begin->next;
		return n;
	}
	void push_front(int n) {
		begin = cons(n, begin);
	}
	void push_back(int n) {
		list* newend = cons(0, NULL); // 새로운 end 를 만든다
		end->data = n;
		end->next = newend;
		end = newend;
	}
};

struct Queue {
	List lis;
	int empty() { return lis.empty(); }
	void addq(int n) {
		return lis.push_back(n);
	}
	int deleteq() {
		return lis.pop_front();
	}
};

// 점이 N개인 그래프에서 점 v부터 BFS
// (worker function)
void bfs(list* a[], int N, int* visit, int v) {
	list* l = cons(0, NULL);
	List lis = { l, l }; // 빈 List
	Queue q = { lis }; // 빈 큐

	cout << v << " ";
	visit[v] = 1;
	q.addq(v);

	while (!q.empty()) {
		int u = q.deleteq();
		// u에서부터 갈 수 있는 w중에서
		// 아직 방문안한 모든 점 w출력
		list* l = a[u];
		for (list* p = l; p != NULL; p = p->next) {
			int w = p->data;
			if (!visit[w]) {
				cout << p->data << " ";
				visit[w] = 1; // 방문 기록
				q.addq(w);
			}
		}
	}
}

// 점이 N개인 그래프에서 점 v부터 BFS
// (drivier funcion)
void BFS(list* a[], int N, int v) {
	// 방문했는지 기록하는 배열 동적 할당
	int* visit = new int[N];
	for (int i = 0; i < N; ++i) {
		visit[i] = 0; // 0으로 초기화
	}

	bfs(a, N, visit, v); // 여기서 주로 일을
}

int main(void)
{
	// adjacency list 인접 리스트 표현
	list* a[5] = {
		// 0 에서부터 연결된 점들
		cons(1,cons(2,cons(4,NULL))),
		// 1 에서부터 연결된 점들
		cons(2,NULL),
		// 2 에서부터 연결된 점들
		cons(3,NULL),
		// 3 에서부터 연결된 점들
		cons(0,cons(1,NULL)),
		// 4 에서부터 연결된 점들
		cons(3,NULL)
	};

	int N = 5;

	BFS(a, N, 0);
	// 0 1 2 4 3
	cout << endl;

	BFS(a, N, 1);
	cout << endl;

	getchar();
	return 0;
}

