#include <list.h>

#include <stdio.h>

static void listiter_print(void*, void *item_) {
	int *item = item_;
	printf("  %d\n", *item);
};

int main(void) {
	List list;
	list_create(&list, sizeof(int));

	int a = 7;
	list_push(&list, &a);
	a = 5;
	list_insert(&list, 0, &a);
	a = 3;
	list_insert(&list, 2, &a);

	puts("List Contents");
	list_foreach(&list, listiter_print, NULL);

	a = 1;
	list_set(&list, 1, &a);

	list_get(&list, 1, &a);
	printf("Index 1: %d\n", a);

	list_pop(&list, &a);
	printf("Last index: %d\n", a);

	list_remove(&list, 0, &a);
	printf("First index: %d\n", a);

	list_destroy(&list);

	return 0;
}
