#include "list.h"

#include <stdlib.h>
#include <string.h>


#define INITIAL_CAPACITY 8

#define list_at(list, idx) ( (list)->data + idx * (list)->dataSize )


void list_create(List *this, size_t dataSize) {
	memcpy((void*)&this->dataSize, &dataSize, sizeof(dataSize));

	this->size = 0;
	this->capacity = 0;
	this->data = NULL;
};

void list_destroy(List *this) {
	free(this->data);
};



void list_move(List *restrict dest, List *restrict src) {
	memcpy((void*)&dest->dataSize, &src->dataSize, sizeof(src->dataSize));

	dest->size = src->size;
	dest->capacity = src->capacity;
	dest->data = src->data;

	src->size = 0;
	src->capacity = 0;
	src->data = NULL;
};

void list_copy(List *restrict dest, const List *restrict src) {
	memcpy((void*)&dest->dataSize, &src->dataSize, sizeof(src->dataSize));

	dest->size = src->size;
	dest->capacity = src->capacity;

	size_t memSize = src->capacity * src->dataSize;
	dest->data = malloc(memSize);
	memcpy(dest->data, src->data, memSize);
};



void list_expand(List *this, size_t capacity) {
	if(this->capacity >= capacity) return;

	if(this->capacity == 0) this->capacity = INITIAL_CAPACITY;
	while(this->capacity < capacity) this->capacity <<= 1;

	this->data = realloc(this->data, this->capacity * this->dataSize);
};

void list_clear(List *this) {
	this->size = 0;
};



void list_insert(List *restrict this, ListIndex index, const void *restrict data) {
	if(index > this->size) return;

	if(this->size == this->capacity) list_expand(this, this->size + 1);

	if(index < this->size) {
		size_t elements = this->size - index;
		memmove(list_at(this, index+1), list_at(this, index), elements * this->dataSize);
	};
	memcpy(list_at(this, index), data, this->dataSize);

	++this->size;
};

void list_remove(List *restrict this, ListIndex index, void *restrict data) {
	if(index >= this->size) return;

	if(data) memcpy(data, list_at(this, index), this->dataSize);

	--this->size;

	if(index < this->size) {
		size_t elements = this->size - index;
		memcpy(list_at(this, index), list_at(this, index+1), elements * this->dataSize);
	};
};

void list_set(List *restrict this, ListIndex index, const void *restrict data) {
	if(index >= this->size) return;

	memcpy(list_at(this, index), data, this->dataSize);
};

void list_get(const List *restrict this, ListIndex index, void *restrict data) {
	if(index >= this->size) return;

	memcpy(data, list_at(this, index), this->dataSize);
};



void list_push(List *restrict this, const void *restrict data) {
	if(this->size == this->capacity) list_expand(this, this->size + 1);

	memcpy(list_at(this, this->size), data, this->dataSize);
	++this->size;
};

void list_pop(List *restrict this, void *restrict data) {
	if(this->size == 0) return;

	--this->size;

	if(data) memcpy(data, list_at(this, this->size), this->dataSize);
};



bool list_empty(const List *this) {
	return this->size == 0;
};



void list_foreach(List *restrict this, void(*f)(void*, void*), void *restrict context) {
	for(ListIndex i = 0; i < this->size; ++i) {
		f(context, list_at(this, i));
	};
};
