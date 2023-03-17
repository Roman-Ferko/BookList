#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 75

typedef struct book {
	char author[len];
	char name[len];
	int year;
	int pages;
	double price;
}books;

typedef struct booklist {
	books data;
	struct booklist* next;
}list;

list* fill_list();
void print_list(list* head);
void Swap(list* a, list* b);
list* sort_list(list* head);
list* remove_from(list* head);
list* add_to(list* head);
void least_pages(list* head);
void print_list_file(list* head, char str[]);