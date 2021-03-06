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

	void **extra;
	void **extra2;

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
		extra = given + sizeof(void*);
		*extra = new_element;
		if (given == ddlist_back(ddlist)) {
			ddlist->back = new_element;	
		}
		else {
			/* get loc of the current next after given */
			//extra = given + sizeof(void*);
			extra = ddlist_next(given);
			
			/* get the loc of the pointer to the next node of
			 * the new element and set it to extra */
			extra2 = new_element + sizeof(void*);
			*extra2 = extra;

			/* change the value of extra (the next pointer
			 * in the given node) to the new node. */
			*extra = new_element;
		}

	}
	++ddlist_size(ddlist);	 
	return 0;
}
