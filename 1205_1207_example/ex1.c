#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int num;
	struct Node* next;
};

struct Node* create_node(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->num = data;
	new_node->next = NULL;
	
	return new_node;
}

struct Node* insert_node(struct Node* input, struct Node* head) {
	if (head == NULL) {
		head = input;
	}
	else {
		struct Node* tmp = head;
		for (tmp; tmp->next != NULL; tmp = tmp->next);
		tmp->next = input;
	}
	return head;
}

void print_LL(struct Node* head) {
	struct Node* tmp = head;
	for (tmp; tmp->next != NULL; tmp = tmp->next) {
		printf("%d -> ", tmp->num);
	}
	printf("%d\n", tmp->num);
}

struct Node* delete_node(struct Node* head, int data) {
	struct Node* prev = NULL;
	struct Node* curr = head;

	while (curr) {
		if (curr->num == data)
			break;
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	if (curr == NULL) {
		printf("Node doesn't exist.\n");
		return NULL;
	}
	else if (curr == head) {
		head = curr->next;
		free(curr);
		return head;
	}
	else {
		prev->next = curr->next;
		free(curr);
		return head;
	}
}

struct Node* ascend(struct Node* head, int node_cnt) {
	struct Node* i = head;

	int iter = 0;

	while (iter < node_cnt) {
		struct Node* j = head;
		struct Node* prev = head;

		while (j->next) {
			struct Node* temp = j->next;
			if (j->num > temp->num) {
				if (j == head) {
					j->next = temp->next;
					temp->next = j;
					prev = temp;
					head = prev;
				}
				else {
					j->next = temp->next;
					temp->next = j;
					prev->next = temp;
					prev = temp;
				}
				continue;
			}
			prev = j;
			j = j->next;
		}
		iter++;
	}
	
	return head;
}

struct Node* descend(struct Node* head, int node_cnt) {
	struct Node* i = head;

	int iter = 0;

	while (iter < node_cnt) {
		struct Node* j = head;
		struct Node* prev = head;

		while (j->next) {
			struct Node* temp = j->next;
			if (j->num < temp->num) {
				if (j == head) {
					j->next = temp->next;
					temp->next = j;
					prev = temp;
					head = prev;
				}
				else {
					j->next = temp->next;
					temp->next = j;
					prev->next = temp;
					prev = temp;
				}
				continue;
			}
			prev = j;
			j = j->next;
		}
		iter++;
	}

	return head;
}

int main(void) {

	struct Node* head = NULL;
	int node_cnt = 0;

	while (1) {
		printf("Input number (0 to end) >> ");
		int a = 0;
		scanf("%d", &a);

		if (a == 0) {
			break;
		}
		else {
			struct Node* input = create_node(a);
			head = insert_node(input, head);
			node_cnt++;
		}
	}
	printf("Linked List Result >> ");
	print_LL(head);

	while (1) {
		printf("Delete number (0 to end) >> ");
		int b = 0;
		scanf("%d", &b);

		if (b == 0) {
			break;
		}
		else {
			head = delete_node(head, b);
		}
	}
	printf("Linked List Delete Result >> ");
	print_LL(head);

	while (1) {
		char input[10] = { 0, };
		printf("ascend? descend? ");
		scanf("%s", input);

		if (!strcmp(input, "ascend")) {
			head = ascend(head, node_cnt);
			break;
		}
		else if (!strcmp(input, "descend")) {
			head = descend(head, node_cnt);
			break;
		}
		else {
			printf("Wrong input!\n");
		}
	}

	printf("Linked List Sort Result >> ");
	print_LL(head);
	return 0;
}