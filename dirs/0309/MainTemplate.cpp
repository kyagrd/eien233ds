// 콘솔 응용 프로그램 진입점 정의

#include "stdafx.h" // Visual C++에서 생성해주는 헤더

#include <stdio.h>

int main(void)
{
	printf("hello world");

#ifdef _MSC_VER // 윈도우즈 명령창이 닫혀서 쓰는 꼼수
	printf("\n\nPress any key to exit ...");
	getchar();
#endif

	return 0;
}
