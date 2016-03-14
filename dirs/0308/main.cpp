// Sorting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h> // C의 표준입출력
#include <iostream> // C++의 표준입출력
#include <vector> // 배열과 거의 같은 인터페이스 제공
using namespace std; // C++ 표준라이브러리를 전역으로 사용하겠다

int main() {
  int array[10] = { 1,2,3,23 };
  printf("%d\n", array[3]); // index 연산자 [ ]

  vector<int> vec(10);
  vec[3] = 23;
  printf("%d\n", vec[3]);


  printf("\n\n프로그램이 끝났습니다. 엔터 키를 눌러서 종료하세요.");
  getchar();
  return 0;

}

/*
  {
  // int a;
  // bool b;

  // O(n) 알고리듬의 예
  int a[10] = {1,2,3} ; // 정수 10개 배열 a[0], a[1], ..., a[9]
  for (int i = 0; i < 10; ++i) {
    printf("%d, ", a[i]);
    // cout << a[i] << ", ";
  }
  printf("\n=====================\n");

  const int N = 10;
  // O(n^2) 정렬 알고리듬
  int b[N] = { 3,2,5,7,2,9,0,4,7,8 };
  // i 번째와 j 번째를 비교해서 더 작은 걸 앞으로 보낸다
  // 단 i < j
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (b[i] > b[j]) {
        int t = b[i];
        b[i] = b[j];
        b[j] = t;
      }
    }
  }
  // 결과를 출력
  for (int i = 0; i < N; ++i) {
    printf("%d, ", b[i]);
    // cout << a[i] << ", ";
  }

  printf("\n\n프로그램이 끝났습니다. 엔터 키를 눌러서 종료하세요.");
  getchar();
  return 0;
}

*/
