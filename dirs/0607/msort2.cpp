// insertion sort

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list { int data; list* next; };
struct list_ { list* data_; list_* next_; };

list* cons(int d, list* p) { return new list({d,p}); }
list_* cons_(list* d, list_* p) { return new list_({d,p}); }

list* merge(list* l1, list* l2) {
	if (l1==NULL) return l2;
	if (l2==NULL) return l1;

	if (l1->data <= l2->data)
		return cons(l1->data, merge(l1->next, l2));
	else
		return cons(l2->data, merge(l1, l2->next));
}

list_* lift(list* l) {
	if (l==NULL) return NULL;

	return cons_(cons(l->data,NULL), lift(l->next));
}

list_* merge(list_* ll) {
	if (ll==NULL) return NULL;
	if (ll->next_==NULL) return ll;

	return cons_(merge(ll->data_, ll->next_->data_), merge(ll->next_->next_));
}

list* msort(list* l) {
	if(l==NULL) return NULL;

	list_* ll = lift(l);

	while (ll->next_) { ll = merge(ll); }

	return ll->data_;
}

void print_list(list* l) {
	for (list* p=l; p; p=p->next) cout <<p->data <<" ";

	cout <<endl;
}

int main()
{
	list* l = cons(3,cons(5,cons(4,cons(2,cons(1,NULL)))));

	print_list(l);

	print_list(msort(l));

	getchar();
	return 0;
}

