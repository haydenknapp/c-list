/* Hayden Knapp
 *
 * This is a special yet not so special testing library that should provide more
 * insight than just simple assertions.
 */

#include <stdio.h>

int htest_failed;
int htest_total;

void htest_init() {
	htest_failed = 0;
	htest_total = 0;
	printf("=================================================================\n\n");
	printf("Beginning tests.\n\n");
}

void htest_stop() {
	printf("\nTests complete:\n"
		"\t%d test(s) failed.\n"
		"\t%d test(s) passed.\n"
		"\t%d test(s) ran.\n\n", htest_failed, htest_total - htest_failed, htest_total);
	printf("=================================================================\n\n");
}

/* a is the variable, b is the expected value which should probably be held constant. */
#define htest_equal(a, b) {\
	if (a != b) {\
		printf("Test at line %d failed in %s:\n\tExpected %d but found %d.\n\n", __LINE__, __func__,  (int)b, (int)a);\
		++htest_failed;\
	}\
	else {\
		printf("Test at line %d passed.\n", __LINE__);\
	}\
	++htest_total;\
}
