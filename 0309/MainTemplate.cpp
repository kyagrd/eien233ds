// 콘솔 응용 프로그램 진입점 정의

#include "stdafx.h" // Visual C++에서 자동으로 생성해주는 녀석

int Main(void) // 이걸 메인함수라고 생각하고 프로그래밍하면 됨
{ 
	printf("hello world");
	return 0;
}

int main(void)
{
	int ret = Main();

#ifdef WIN32 // 윈도우즈 명령창이 지맘대로 닫혀서 쓰는 꼼수
	printf("\n\nPress any key to exit ...");
	getchar();
#endif
	return ret;
}
