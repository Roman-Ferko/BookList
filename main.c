#include "Func.h"
int main()
{
	list* p = fill_list();
	printf("Unsorted list:\n");
	print_list(p);
	print_list_file(p,"Unsorted list\n");
	sort_list(p);
	printf("\nSorted list:\n");
	print_list_file(p, "\nSorted List:\n");
	printf("\nList with some elements removed:\n");
	remove_from(p);
	print_list_file(p, "\nList with some elements removed : \n");
	least_pages(p);
}