#ifndef DDLIST_H_
#define DDLIST_H_

#include <stdlib.h>

typedef struct DDList_ {
	int size;
	unsigned long long int esize;
	char *front, *back;
} DDList;

/* Initialize the Direct Data List given a pointer to the list and the size
 * of the data in each element in bytes. There is no destroy function, as the
 * data stored in each element should be direct.
 * In the function, the front and back pointers are set to NULL, the size to
 * 0 and the element size set to whatever is given to the function.
 * Return -1 if unssuccesful and 0 if successful.
 */

int init_ddlist(DDList *ddlist, int esize);

/* Destroy the list. Free all memory. */

void ddlist_destroy(DDList *ddlist);

/* Insert another element into the list. Takes a pointer to an element, Insert
 * after the given element. This Should increase the DDList size. Return 0 if
 * successful and -1 otherwise.
 */

int ddlist_ins_next(DDList *ddlist, void *data);

/* Insert another element into the list. Takes a pointer to an element, Insert
 * before the given element. This Should increase the DDList size. Return 0 if
 * successful and -1 otherwise.
 */

int ddlist_ins_prev(DDList *ddlist, void *data);

/* Remove the given element. Takes a pointer to the element that is being removed
 * and a pointer. The pointer will be set to the address of the data of the element
 * that is being removed. 0 if remove was succesful and -1 otherwise.
 */

int ddlist_remove(DDList *ddlist, void **data);

/* Macro that returns the size of a given list. */

#define ddlist_size(ddlist) (ddlist->size)

/* Macro that returns the front node of a given list. */
#define ddlist_front(ddlist) (ddlist->front)

/* Macro that returns the back node of a given list. */
#define ddlist_back(ddlist) (ddlist->back)


