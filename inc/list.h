#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>
#include <stdbool.h>

typedef size_t ListIndex;
typedef struct List {
	const size_t dataSize;

	size_t size;
	size_t capacity;
	void *data;
} List;

void list_create(List*, size_t);
void list_destroy(List*);

void list_move(List *restrict, List *restrict);
void list_copy(List *restrict, const List *restrict);

void list_expand(List*, size_t);
void list_clear(List*);

void list_insert(List *restrict, ListIndex, const void *restrict);
void list_remove(List *restrict, ListIndex, /*optional*/ void *restrict);
void list_set(List *restrict, ListIndex, const void *restrict);
void list_get(const List *restrict, ListIndex, void *restrict);

void list_push(List *restrict, const void *restrict);
void list_pop(List *restrict, /*optional*/ void *restrict);

bool list_empty(const List*);

void list_foreach(List *restrict, void(*)(void*, void*), void *restrict); // (context, element)

#endif
