#include "list.h"

int ddlist_init(DDList *ddlist, int e) {
	ddlist->esize = e;
	ddlist->size = 0;
	ddlist->front = NULL;
	ddlist->back = NULL;
	return 0;
}
