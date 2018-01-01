#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "htest.h"

void test_001_init() {
	DDList ddlist;
	ddlist_init(&ddlist, sizeof(int));

	htest_equal((int)ddlist.esize, (int)sizeof(int));
	htest_equal((int)ddlist.size, 0);
	htest_equal((int)ddlist.front, (int)NULL);
	htest_equal((int)ddlist.back, (int)NULL);
}

void test_002_macros() {
	DDList ddlist;
	ddlist_init(&ddlist, sizeof(int));

	htest_equal(ddlist_size(&ddlist), 0);
	htest_equal(ddlist_front(&ddlist), 0);
	htest_equal(ddlist_back(&ddlist), 0);

	ddlist.size = 3;
	ddlist.front = 4;
	ddlist.back = 5;

	htest_equal(ddlist_size(&ddlist), 3);
	htest_equal(ddlist_front(&ddlist), 4);
	htest_equal(ddlist_back(&ddlist), 5);
}	

void test_003_ins_next() {
	DDList ddlist;
	ddlist_init(&ddlist, sizeof(int));

	int n35 = 35;

	ddlist_ins_next(&ddlist, NULL, &n35);

	htest_equal(ddlist_size(&ddlist), 1);
	htest_equal(*ddlist_next(ddlist_front(&ddlist)), NULL);
	htest_equal(*ddlist_prev(ddlist_front(&ddlist)), NULL);
	htest_equal(ddlist_front(&ddlist), ddlist_back(&ddlist));
	htest_equal(*(int*)ddlist_data(ddlist_front(&ddlist)) , n35);

	int n99 = 99;
	ddlist_ins_next(&ddlist, NULL, &n99);

	htest_equal(ddlist_size(&ddlist), 2);
	htest_equal(*ddlist_next(ddlist_front(&ddlist)), NULL);
	htest_equal(*ddlist_prev(ddlist_front(&ddlist)), NULL);
	htest_equal(*(int*)ddlist_data(ddlist_back(&ddlist)), 99);

	htest_equal(*(int*)ddlist_data(ddlist_next(ddlist_front(&ddlist))), n99);
}
	
int main() {
	htest_init();

	test_001_init();
	test_002_macros();
	test_003_ins_next();

	htest_stop();
}
