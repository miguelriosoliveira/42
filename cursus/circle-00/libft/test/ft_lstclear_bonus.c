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

t_list *alloc_word(char *str) {
	char *word = ft_calloc(sizeof(str), sizeof(char));
	int i = 0;
	while (str[i]) {
		word[i] = str[i];
		i++;
	}
	t_list *node = ft_lstnew(word);
	return node;
}

void del(void* content) {
	free(content);
}

int main() {
	{
		t_list *lst = alloc_word("great");
		lst->next = alloc_word("captain");
		lst->next->next = alloc_word("usopp");

		t_list *expected = NULL;

		ft_lstclear(&lst, del);
		t_list *received = lst;

		int passed = compare_lists(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			t_list *n1 = alloc_word("great");
			n1->next = alloc_word("captain");
			n1->next->next = alloc_word("usopp");
			printf("%s ft_lstclear(\n", result);
				printf("\t");
				print_list(n1);
				printf("\t");
				printf("void (*del)(void*)\n");
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

		ft_lstclear(&lst, del);
		t_list *received = lst;

		int passed = compare_lists(expected, received);
		if (!passed) {
			char *result = passed ? "✅" : "❌";
			t_list *n1 = NULL;
			printf("%s ft_lstclear(\n", result);
				printf("\t");
				print_list(n1);
				printf("\t");
				printf("void (*del)(void*)\n");
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

	printf("✅ ft_lstclear\n");
}
