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
	int n99 = 99;
	int n10 = 10;

	ddlist_ins_next(&ddlist, NULL, &n35);

	htest_equal(ddlist_size(&ddlist), 1);
	htest_equal(ddlist_next(ddlist_front(&ddlist)), NULL);
	htest_equal(ddlist_prev(ddlist_front(&ddlist)), NULL);
	htest_equal(ddlist_next(ddlist_back(&ddlist)), NULL);
	htest_equal(ddlist_prev(ddlist_back(&ddlist)), NULL);
	htest_equal(ddlist_front(&ddlist), ddlist_back(&ddlist));
	htest_equal(*(int*)ddlist_data(ddlist_front(&ddlist)) , n35);

	ddlist_ins_next(&ddlist, ddlist_front(&ddlist), &n99);

	htest_equal(ddlist_size(&ddlist), 2);
	htest_equal(ddlist_next(ddlist_back(&ddlist)), NULL);
	htest_equal(ddlist_prev(ddlist_back(&ddlist)), NULL);

	/* access the data from the back node and ensure it is == 99 */
	htest_equal(*(int*)ddlist_data(ddlist_back(&ddlist)), n99);

	/* test to see if the the front's next has a value of 99. */
	htest_equal(*(int*)ddlist_data(ddlist_next(ddlist_front(&ddlist))), n99);

	/* assert to see if the front's next is the back */
	htest_equal(ddlist_next(ddlist_front(&ddlist)), ddlist_back(&ddlist));

	/* test inserting in between the front and the back */
	void *prev_front = ddlist_front(&ddlist);
	void *prev_back = ddlist_back(&ddlist);

	ddlist_ins_next(&ddlist, ddlist_front(&ddlist), &n10);

	htest_equal(ddlist_size(&ddlist), 3);

	/* test to make sure the previous front and back are both unchanged. */
	htest_equal(ddlist_front(&ddlist), prev_front);
	htest_equal(ddlist_back(&ddlist), prev_back);

	/* assert that we can reach the back from the front by */
	htest_equal(ddlist_next(ddlist_next(ddlist_front(&ddlist))), ddlist_back(&ddlist));

	/* get the next until at the back and ensure it is equal to n10 */
	htest_equal(*(int*)ddlist_data(ddlist_next(ddlist_next(ddlist_front(&ddlist)))), n10);

	/* make a list of in order digits then go back through the list
	 * and ensure that they are correct.
	 */
	DDList in_order;
	ddlist_init(&in_order, sizeof(int));
#define N1 1024
	for (int i = 0; i < N1; ++i) {
		ddlist_ins_next(&in_order, ddlist_back(&in_order), &i);
	}
	void *current = ddlist_front(&in_order);
	for (int i = 0; i < N1; ++i) {
		htest_equal(*(int*)ddlist_data(current), i);
		current = ddlist_next(current);
	}
	/* go back backwards. */
	current = ddlist_back(&in_order);
	for (int i = ddlist_size(&in_order) - 1; i >= 0; --i) {
		htest_equal(*(int*)ddlist_data(current), i);
		current = ddlist_prev(current);
	}
}
	
int main() {
	htest_init();

	test_001_init();
	test_002_macros();
	test_003_ins_next();

	htest_stop();
}

