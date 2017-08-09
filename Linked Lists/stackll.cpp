#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	struct node *next;
};


int pop(struct node **head)
{
	if (*head != NULL)
	{
		struct node *temp;
		int ret_val = (*head)->data;
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return ret_val;
	}
	else {
		printf("Empty Stack\n");
		return -1;
	}
}

int push(struct node **head, int data)
{
	struct node * temp;
	temp = (struct node*)calloc(1, sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
	return 0;
}

void print_stackll(struct node *head)
{
	struct node *temp = head;
	while (temp)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int test_main1()
{
	int push_pop = -1;

	struct node *head = NULL;

	do {
		push_pop = rand() % 10;

		if (push_pop<5)
		{
			int input_num = rand() % 100;
			push(&head, input_num);
		}
		else {
			pop(&head);
		}
		print_stackll(head);
		printf("Do u want to continue\n");
		scanf("%d", &push_pop);
	} while (push_pop != -1);

	return 0;
}


