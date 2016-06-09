// insertion sort

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
struct list { T data; list* next; };

template <typename T>
list<T>* nil(void) { return NULL; }

template <typename T>
list<T>* cons(T d, list<T>* p) { return new list<T>({d,p}); }

template <typename T>
list<T>* merge(list<T>* l1, list<T>* l2) {
	if (l1==NULL) return l2;
	if (l2==NULL) return l1;

	if (l1->data <= l2->data)
		return cons(l1->data, merge(l1->next, l2));
	else
		return cons(l2->data, merge(l1, l2->next));
}

template <typename T>
list<list<T>*>* lift(list<T>* l) {
	if (l==NULL) return NULL;

	return cons(cons(l->data,nil<T>()), lift(l->next));
}

template <typename T>
list<T>* merge(list<T>* ll) {
	if (ll==NULL) return NULL;
	if (ll->next==NULL) return ll;

	return cons(merge(ll->data, ll->next->data), merge(ll->next->next));
}

template <typename T>
list<T>* msort(list<T>* l) {
	if(l==NULL) return NULL;

	list<list<T>*>* ll = lift(l);

	while (ll->next) { ll = merge(ll); }

	return ll->data;
}

template <typename T>
void print_list(list<T>* l) {
	for (list<T>* p=l; p; p=p->next) cout <<p->data <<" ";

	cout <<endl;
}

int main()
{
	list<int>* l = cons(3,cons(5,cons(4,cons(2,cons(1,nil<int>())))));

	print_list(l);

	print_list(msort(l));

	getchar();
	return 0;
}

