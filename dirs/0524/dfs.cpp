// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list { int data; list* next; };

list* cons(int n, list* p) {
	return new list({ n,p });
}

// 점이 N개인 그래프에서 점 v부터 DFS
// (worker function)
void dfs(list* a[],
	     int N,
	     int* visit,
	     int v) {
	cout << v << " "; // v 출력
	visit[v] = 1; // v를 방문했다고 기록

	// v에서부터 연결된 u들 중에서
	list* l = a[v];
	for (list* p = l; p != NULL; p = p->next) {
		int u = p->data;
		// 아직 방문하지 않은 것에 대해서만
		if (!visit[u]) {
            // u로부터 각각 dfs 재귀 호출
			dfs(a, N, visit, u);
		}
	}
}


// 점이 N개인 그래프에서 점 v부터 DFS
// (drivier funcion)
void DFS(list* a[], int N, int v) {
	// 방문했는지 기록하는 배열 동적 할당
	int* visit = new int[N];
	for (int i = 0; i < N; ++i) {
		visit[i] = 0; // 0으로 초기화
	}

	dfs(a, N, visit, v); // 여기서 주로 일을
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

	DFS(a, N, 1);
	// 1 2 3 0 4
	cout << endl;

	DFS(a, N, 0);
	// 0 1 2 3 4
	cout << endl;

	getchar();
	return 0;
}

