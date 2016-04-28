# EIEN233(02) 데이타구조 (2016년 1학기)

수업 외 면담이 필요할 경우 교수 홈페이지 참조
http://kyagrd.github.io/

교과서는 교내 서점에서 구입
* 한국어판 - C로 쓴 자료구조론 - 2/E
* 영문원서 - Fundamentals of Data Structures in C (2nd ed.)

학점 평가 방침: 출석/퀴즈 25%, 과제 25%, 중간 25%, 기말 25%


## 실습환경 안내
프로그래밍 실습은 주로 C/C++를 활용하며
화요일 농심관 컴퓨터실 수업에서는 컴퓨터실에 설치된 Visual Studio를 활용하고,
노트북 등 개인 컴퓨터에서는 Visual Studio Express (무료버전)을 설치해서 사용.
https://www.visualstudio.com/ko-kr/products/visual-studio-express-vs.aspx

Mac OS X 사용자는 XCode를 이용해도 무방하며
리눅스/유닉스 사용자는 뭘 쓰든 알아서 잘 하겠지만
첫 프로그래밍 과제 제출 전에 교수와 상담.

## 과제
* 과제1 (제출기한: 2016-03-21 월요일 밤) - 다음 프로그램을 완성하시오 [hw1.cpp](https://github.com/kyagrd/eien233ds/blob/master/dirs/hw1/hw1.cpp) 
* 과제2 (제출기한: 2016-03-28 월요일 밤) - 다음 프로그램을 완성하시오 [hw2.cpp](https://github.com/kyagrd/eien233ds/blob/master/dirs/hw2/hw2.cpp)
* 과제3 (제출기한: 2016-04-11 월요일 밤) - 다음 프로그램을 완성하시오 [hw3.cpp](https://github.com/kyagrd/eien233ds/blob/master/dirs/hw3/hw3.cpp)

## 강의노트
강의 전후로 업데이트 예정

* [2016-03-08 수업진행 및 기본개념](https://slides.com/kyagrd/ds2016spring0308) (수업시간에 다룬 [예제 소스코드](https://github.com/kyagrd/eien233ds/tree/master/dirs/0308))
* [2016-03-09 보강: C/C++ 프로그래밍 기초](https://github.com/kyagrd/eien233ds/tree/master/dirs/0309)
* 2016-03-11 배열과 포인터의 기본 및 리스트 맛보기 (소스코드 http://ideone.com/WhffEO , http://ideone.com/Gjy2KV  )
* [2016-03-15 배열, 포인터, 동적할당, 귀납적 정의, 리스트, 트리](https://slides.com/kyagrd/ds2016spring0315) (수업시간에 다룬 [예제 소스코드](https://github.com/kyagrd/eien233ds/tree/master/dirs/0315) )
* 2016-03-18: 과제에 대하 설명, 질문 답변 및 배열과 리스트 for문 돌리기 (수업시간에 다룬 [예제 소스코드](https://github.com/kyagrd/eien233ds/tree/master/dirs/0318) )
* [2016-03-22 배열과 리스트 공통점과 차이점](https://slides.com/kyagrd/ds2016spring0322)
* [2016-03-25 귀납적 정의와 재귀(순환, 되돌기)](https://slides.com/kyagrd/ds2016spring0325)
* [2016-03-29 과제1 풀이, 퀴즈2 풀이](http://slides.com/kyagrd/ds2016spring0329)
* 2016-04-01 list에 대한 포인터 2개로 만든 맨앞과 맨뒤 삽입 모두 O(1)인 추상 데이타 타입 List
  * List 예제 소스코드 http://ideone.com/8hsygE
* 2016-04-05 [binomial coefficient 재귀함수](https://github.com/kyagrd/eien233ds/blob/master/dirs/0405/choose.cpp)
* 2016-04-08 list로 만든 스택([소스코드](http://ideone.com/5FQ2y5))과 List로 만든 큐([소스코드](http://ideone.com/wTAb3T))
* 2016-04-12 [과제2 관련 Destructive Update vs Persistent Data](https://slides.com/kyagrd/ds2016spring0412), 스택으로 괄호 매칭 검사 ([소스코드](https://github.com/kyagrd/eien233ds/blob/master/dirs/0412/parenmatch.cpp))
* 2016-04-19 [중간고사 안내, 이진 트리 관련 정의](https://slides.com/kyagrd/ds2016spring0419)
  * level order 와 minBST, maxBST, isBST [소스코드](https://github.com/kyagrd/eien233ds/blob/master/dirs/0419/LevelOrder_isBST.cpp)

## C/C++ 프로그래밍 유투브 강좌 시리즈 (보충 참고자료)
프로그래밍에 익숙한 정도가 개개인별로 달라서 너무 쉽다고 느끼는 분들이 있을수도
있고 또 반대로 스스로 C/C++ 프로그래밍에 대한 기초가 부족하다고 느끼거나
Visual Studio가 너무 생소하다 이런 분들도 있을겁니다. 진도를 나가기 위해서는
너무 기초적인 부분만 반복할 수는 없으니 좀 기초 문법 같은 자세한 설명이 필요하다
싶은 분들을 위해 도움이 될만한 유투브에 올라온 무료 공개 강좌가 있습니다.
다 볼 필요는 없고 필요하고 도움이 된다고 판단되는 부분만 찾아서 보면 될 것 같습니다.

https://youtu.be/yTKARbseZKY?list=PLlJhQXcLQBJqywc5dweQ75GBRubzPxhAk

수업에서 제가 진행하는 것과 사소한 차이점도 있긴 한데 기초를 익히는 데는 도움이 될 것 같습니다.
(예를 들면 Visual C++ Win32 콘솔 애플리케이션을 만들 때 저는
그냥 새 프로젝트 만들기 누르고 바로 기본 설정으로 프로젝트를 만들었고,
저 강좌에서는 빈 프로젝트 만들기를 체크하고 프로젝트를 만듭니다.
어떤 분들이 1학년 수업 들을 때는 빈 프로젝트 체크하고 만들기로 했다고 하더군요)
