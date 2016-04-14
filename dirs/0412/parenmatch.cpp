#include "stdafx.h"
#include <iostream>
using namespace std;

struct list { int data; list* next; };
list* cons(int n, list* p) {
	return new list({ n,p });
}

struct Stack {
	list* l;
	int empty() { return l == NULL; } // 스택이 비었는지 검사
	void push(int n) { l = cons(n, l); }
	int pop() {
		if (empty()) {
			cout << "stack empty" << endl;
			return INT_MIN;
		}
		int n = l->data;
		l = l->next;
		return n;
	}
};

int match(char c2, char c) {
	switch (c2) {
	case '[': return c == ']';
	case '{': return c == '}';
	case '(': return c == ')';
	default: return 0;
	}
}
int main() {
	Stack s = { NULL };
	char str[] = "a[asd(asdf{bb)aaa}zz]a";
	for (char* p = str; *p != '\0'; ++p) {
		char c = *p; char c2;
		switch (c) {
		case '[': case '{': case '(':
			s.push(c);
			cout << "push " << c <<endl;
			break;
		case ']': case '}': case ')':
			if (s.empty()) {
				cout << "stack empty ";
				cout << "cannot match " << c << endl;
				getchar();
				return -1;
			}
			c2 = s.pop();
			cout << "pop " <<c2 <<", c=" <<c << endl;
			if ( ! match(c2, c) ) {
				cout << "cannot match "
					<< c2 <<"," <<c << endl;
				getchar();
				return -1;
			}
			break;
		default: break;
		}
	}

	cout << "match" << endl;

	getchar();
	return 0;
}
