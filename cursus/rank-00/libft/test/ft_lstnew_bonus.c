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
		printf("\"%s\"", (char *)current->content);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\"%p\"\n", current);
}

int main() {
	{
		char *content = "great captain usopp";

		t_list *expected = malloc(sizeof(t_list));
		expected->content = content;
		expected->next = NULL;
		t_list *received = ft_lstnew(content);

		int passed = compare_lists(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			printf("%s ft_lstnew(\"%s\")\n", result, content);
			printf(">>>>> expected <<<<<\n\n");
			print_list(expected);
			printf("\n");
			printf(">>>>> received <<<<<\n\n");
			print_list(received);
			printf("\n");
			return 1;
		}
		free(expected);
	}

	printf("✅ ft_lstnew\n");
}
