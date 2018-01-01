#include "list.h"

int ddlist_init(DDList *ddlist, int e) {
	ddlist->esize = e;
	ddlist->size = 0;
	ddlist->front = NULL;
	ddlist->back = NULL;
	return 0;
}

int ddlist_ins_next(DDList *ddlist, void *given, void *data) {
	void *new_element;
	if ((new_element = (void*)malloc(sizeof(void*) * 2 + ddlist->esize)) == NULL)
		return -1;

	void **new_next = new_element + sizeof(void*);
	void **new_prev = new_element;

	memcpy(new_element + 2 * sizeof(void*), data, ddlist->esize);

	if (ddlist_size(ddlist) == 0) {
		ddlist->front = new_element;
		ddlist->back = new_element;
		*new_next = NULL;
		*new_prev = NULL;
	}
	else {
		if (given == ddlist_front(&ddlist)) {

		}
	}
	++ddlist_size(ddlist);	 
	return 0;
}
