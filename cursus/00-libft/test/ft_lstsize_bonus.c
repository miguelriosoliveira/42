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
		t_list *lst = ft_lstnew("great");
		lst->next = ft_lstnew("captain");
		lst->next->next = ft_lstnew("usopp");

		int expected = 3;
		int received = ft_lstsize(lst);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_lstsize(\n", result);
				printf("\t");
				print_list(lst);
			printf(")\n");
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}
	{
		t_list *lst = NULL;

		int expected = 0;
		int received = ft_lstsize(lst);

		int passed = expected == received;
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_lstsize(\n", result);
				printf("\t");
				print_list(lst);
			printf(")\n");
			printf("expected: %d\n", expected);
			printf("received: %d\n", received);
			return 1;
		}
	}

	printf("✅ ft_lstsize\n");
}
