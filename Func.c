#include "Func.h"
list* fill_list() {
	list* p = malloc(sizeof(list));
	list* start = NULL;
	char str[len];
	char* limits = "|";
	char* pw;
	FILE* f1 = fopen("in.txt", "rt");
	do {
		fgets(str, len, f1);
		pw = strtok(str, limits);
		strcpy(p->data.author, pw);
		pw = strtok(NULL, limits);
		strcpy(p->data.name, pw);
		pw = strtok(NULL, limits);
		p->data.year = atoi(pw);
		pw = strtok(NULL, limits);
		p->data.pages = atoi(pw);
		pw = strtok(NULL, limits);
		p->data.price = atof(pw);
		if (!start) {
			start = p;
		}
		list* pp = malloc(sizeof(list));
		p->next = pp;
		p = pp;
	} while (!feof(f1));
	p->next = NULL;
	p = start;
	fclose(f1);
	return p;
}


void print_list(list* head) {
	list* p = head;
	while (p->next != NULL) {
		printf("|%s|%s|%d|%3d|%.2lf|\n", p->data.author, p->data.name, p->data.year, p->data.pages, p->data.price);
		p = p->next;
	};
}
void print_list_file(list* head, char str[len]) {
	list* p = head;
	FILE* f = fopen("output.txt", "at");
	fprintf(f, "%s", str);
	while (p->next != NULL) {
		fprintf(f,"|%s|%s|%d|%3d|%.2lf|\n", p->data.author, p->data.name, p->data.year, p->data.pages, p->data.price);
		p = p->next;
	};
	fclose(f);
}
void Swap(list* a, list* b) {
	books temp = a->data;
	a->data = b->data;
	b->data = temp;
}
list* sort_list(list* head) {
	list* q = head;
	while (q->next) {
		list* p = q->next;

		while (p->next)
		{
			if (q->data.year >p->data.year)
			{
				Swap(p, q);
			}
			p = p->next;
		}

		q = q->next;
	}
	return head;
}

list* remove_from(list* head) {
	list* curr = head;
	char str[300];
	list* temp = head;
	while (curr->next) {
		list* next = curr->next;
		strcpy(str, next->data.author);
		
			for (int i = 0; i < 300; i++) {
				if (str[i] == 'Y' && str[i + 1] == 'a') {
					list* temp = curr->next;
					curr->next = curr->next->next;
					free(temp);
				}
			}
		curr = curr->next;
	}

	return head;
}
void least_pages(list* head) {
	FILE* f = fopen("output.txt", "a+");
	fprintf(f, "3 books with least amount of pages:\n");
	list* p = head;
	list* min1=head;
	list* min2=head;
	list* min3=head;
	int firstmin = head->data.pages;
	int secmin = head->data.pages;
	int thirdmin = head->data.pages;
	while(p->next)
	{
		if (p->data.pages < firstmin) {
			firstmin = p->data.pages;
		}
		p = p->next;
	}
	p = head;
	while (p->next) {
		if (p->data.pages < secmin&&p->data.pages!=firstmin) {
			secmin = p->data.pages;
		}
		p = p->next;
	}
	p = head;
	while (p->next) {
		if (p->data.pages < thirdmin && p->data.pages != firstmin&& p->data.pages != secmin) {
			thirdmin = p->data.pages;
		}
		p = p->next;
	}
	p = head;
	while (p->next) {
		if (p->data.pages == firstmin) min1->data = p->data;
		p = p->next;
	}
	fprintf(f,"|%s|%s|%d|%3d|%.2lf|\n", min1->data.author, min1->data.name, min1->data.year, min1->data.pages, min1->data.price);
	p = head;
	while (p->next) {
		if (p->data.pages == secmin) min2->data = p->data;
		p = p->next;
	}
	fprintf(f,"|%s|%s|%d|%3d|%.2lf|\n", min2->data.author, min2->data.name, min2->data.year, min2->data.pages, min2->data.price);
	p = head;
	while (p->next) {
		if (p->data.pages == thirdmin) min3->data = p->data;
		p = p->next;
	}
	fprintf(f,"|%s|%s|%d|%3d|%.2lf|\n", min3->data.author, min3->data.name, min3->data.year, min3->data.pages, min3->data.price);
}
list* add_to(list* head) {
	list* NewNode = malloc(sizeof(list));
	char author[len];
	printf("Enter the author's name: ");
	gets(author);
	strcpy(NewNode->data.author, author);
	char book[len];
	printf("Enter the book name: ");
	gets(book);
	strcpy(NewNode->data.name, book);
	char years[len];
	printf("Enter the year of publication: ");
	gets(years);
	NewNode->data.year = atoi(years);
	char page[len];
	printf("Enter the number of pages: ");
	gets(page);
	NewNode->data.pages = atoi(page);
	char prices[len];
	printf("Enter the price of a book: ");
	gets(prices);
	NewNode->data.price = atof(prices);
	

	list* p = NewNode;
	p->next = head;
	head = p;
	
	sort_list(p);
	return head;
}