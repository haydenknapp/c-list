#include "htest.h"

int main() {
	htest_init();

	htest_equal(1, 0);
	htest_equal(1, 1);
	htest_equal(1, 2);

	htest_stop();
}
