#include <stdio.h>
#include <string.h>
#include "../libft.h"

int compare_nodes(t_list *node1, t_list *node2) {
	return strcmp(node1->content, node2->content) == 0;
}

int compare_lists(t_list *l1, t_list *l2) {
	t_list *current1 = l1;
	t_list *current2 = l2;
	while (current1 || current2) {
		if (!compare_nodes(current1, current2))
			return 0;
		current1 = current1->next;
		current2 = current2->next;
	}
	return 1;
}

void print_list(t_list *list) {
	t_list *current = list;
	while (current) {
		printf("\"%s\" ➡ ", (char *)current->content);
		current = current->next;
	}
	printf("∅\n");
}

int main() {
	{
		t_list *first = ft_lstnew("great");
		t_list *second = ft_lstnew("captain");
		t_list *last = ft_lstnew("usopp");
		first->next = second;
		second->next = last;

		t_list *expected = last;
		t_list *received = ft_lstlast(first);

		int passed = compare_lists(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_lstlast(\n", result);
				printf("\t");
				print_list(first);
			printf(")\n");
			printf(">>>>> expected <<<<<\n\n");
			print_list(expected);
			printf("\n");
			printf(">>>>> received <<<<<\n\n");
			print_list(received);
			printf("\n");
			return 1;
		}
	}
	{
		t_list *lst = NULL;

		t_list *expected = NULL;
		t_list *received = ft_lstlast(lst);

		int passed = compare_lists(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_lstlast(\n", result);
				printf("\t");
				print_list(lst);
			printf(")\n");
			printf(">>>>> expected <<<<<\n\n");
			print_list(expected);
			printf("\n");
			printf(">>>>> received <<<<<\n\n");
			print_list(received);
			printf("\n");
			return 1;
		}
	}

	printf("✅ ft_lstlast\n");
}
