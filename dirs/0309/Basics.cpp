#include <stdio.h> // C 표준입출력 printf, scanf 등

#include <iostream> // C++ 표준입출력 cout, cin 등
using namespace std; // C++ 표준라이브러리를 쓰기 위해서 ...


// int main(int argc, char **argv)
int main(void)
{
 // C의 기본 타입
 int n = 3; // 새로운 정수 타입 변수. 3으로 초기화
 float x1 = 3.14; // 부동 소수점 수 1.3423
 // double x2 = 3.14; // 부동 소수점 수 (float의 두배 정확도?)
 
 char c = 'y'; // 문자
 
 /*
 // C 방식 입력
 scanf("%d", &n); // n의 주소를 넘겨 정수값을 입력받아 n에 저장
 // C 방식 출력
 printf("%d, %f, %c \n\n\n\n newline 4 times\n", n, x1, c);
 
 // C++ 방식 입력
 cin >>n;
 // C++ 방식 출력
 cout <<n <<", " <<x1 <<", " <<c <<"\n\n\n" <<endl;
 */
 
 cout<< "sizeof(n) = " << sizeof(n) <<endl; // int는 4바이트
 cout<< "sizeof(c) = " << sizeof(c) <<endl; // char는 1바이트
 cout<< "sizeof(x1) = " << sizeof(x1) <<endl; // float 4바이트
 
 // 배열
 int int_array[4]; // 초기값 없음
 int int_array2[4] = { 5, 6, 7, 8 }; // 초기값 정의
 int int_array3[] = { 5, 6, 7, 8 }; // 초기값 정의
 
 // C문자열은 char 타입의 배열 (또는 포인터)
 // 단 맨 끝의 값은 NULL (정수값으로 변환하면 0)
 
 char s1[] = { 'h','e','l','l','o', NULL };
 
 printf("%s\n", s1);
 
 cout <<s1 <<endl;
 
 /* 여러 줄
 주석 */
 
 // printf("hello world\n");
 
 return 0;
}
