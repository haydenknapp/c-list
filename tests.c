#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "htest.h"

void test_001_init_ddlist() {
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

int main() {
	htest_init();

	test_001_init_ddlist();
	test_002_macros();

	htest_stop();
}
