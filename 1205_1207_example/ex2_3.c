#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char name[20];
	int price;
	struct Node* next;
};

struct Node* create_node(const char* name, const int price) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(new_node->name, name);
	new_node->price = price;
	new_node->next = NULL;
	
	return new_node;
}


void print_LL(struct Node* head) {
	struct Node* tmp = head;
	for (tmp; tmp->next != NULL; tmp = tmp->next) {
		printf("%s : %d -> ", tmp->name, tmp->price);
	}
	printf("%s : %d\n", tmp->name, tmp->price);
	return;
}

struct Node* insert_node(struct Node* input, struct Node* head) {
	struct Node* prev = NULL;
	struct Node* curr = head;
	struct Node* next = head->next;
	
	if (input->price < head->price) {
		input->next = head;
		head = input;
	}
	else {
		while (1) {
			if (curr->next == NULL){
				curr->next = input;
				break;
			}
			else {
				if (input->price > next->price) {
					prev = curr;
					curr = next;
					next = next->next;
				}
				else if (input->price == next->price) {
					if (strcmp(input->name, next->name) > 0) {
						prev = curr;
						curr = next;
						next = next->next;
						curr->next = input;
						input->next = next;
						break;
					}
					else {
						curr->next = input;
						input->next = next;
						break;
					}
				}
				else {
					curr->next = input;
					input->next = next;
					break;
				}
			}
		}
	}

	return head;
}


struct Node* ascend_in_name(struct Node* head, int node_cnt) {
	struct Node* i = head;

	int iter = 0;

	while (iter < node_cnt) {
		struct Node* j = head;
		struct Node* prev = head;

		while (j->next) {
			struct Node* temp = j->next;
			if (strcmp(j->name, temp->name) > 0) {
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

void save_txt(struct Node* head) {
	FILE* wfp = fopen("name.txt", "w");
	
	for (struct Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		fprintf(wfp, "%s : %d\n", tmp->name, tmp->price);
	}
	fclose(wfp);

	return;
}

int main(void) {

	struct Node* head = create_node("americano", 1500);
	struct Node* input = create_node("apple_juice", 2500);
	head->next = input;
	input = create_node("yogurt", 4500);
	head->next->next = input;

	int node_cnt = 3;

	print_LL(head);

	FILE* rfp = fopen("drink.txt", "r");
	while (!feof(rfp)) {
		char line[100] = { 0, };
		fgets(line, 100, rfp);
		char* name = strtok(line, "\t");
		int price = atoi(strtok(NULL, "\n"));

		input = create_node(name, price);
		head = insert_node(input, head);

		print_LL(head);
		node_cnt++;
	}
	fclose(rfp);

	head = ascend_in_name(head, node_cnt);
	save_txt(head);

}