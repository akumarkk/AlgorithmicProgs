/*
 * Sort a linked list of 0s, 1s and 2s :
 *
 *  1. Count number of 0, 1, 2 using count[]
 *  2. Fill first count[0] with zero and count[1] nodes with 1 etc
 *
 *  Another Solution :
 *  1. MOve 0 nodes to front 
 *  2. Move 2's nodes to rear end
 *
 *  My Solution :
 *  Implemented one is my solution.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_
{
    int	    data;
    struct node_ *next;
}node_t;

node_t *
sort_012_nodes(node_t *root)
{
    node_t *zero_front=NULL, *zero_rear=NULL;
    node_t *one_front=NULL, *one_rear=NULL;
    node_t *two_front=NULL, *two_rear=NULL;

    while(root != NULL)
    {
	printf("root = (%d)\n", root->data);

	if(root->data == 0)
	{
	    if(zero_front == NULL)
	    {
		printf("ZERO : zero front = %d\n", root->data);
		zero_front = zero_rear = root;
	    }
	    else
	    {
		zero_rear->next = root;
	       zero_rear = zero_rear->next;
		printf("ZERO : zero rear = %d\n", zero_rear->data);
	    }
	}
	else if(root->data == 1)
	{
	    if(one_front == NULL)
	    {
		one_front = one_rear = root;
		printf("ONE : zero front = %d\n", one_rear->data);
	    }
	    else
	    {
		one_rear->next = root;
		one_rear = one_rear->next;
		printf("ONE : one rear = %d\n", one_rear->data);
	    }
	}
	else
	{
	    if(two_front == NULL)
	    {
		two_front = two_rear = root;
		printf("TWO :  front = %d\n", two_rear->data);
	    }
	    else
	    {
		two_rear->next = root;
		two_rear = two_rear->next;
		printf("TWO :  rear = %d\n", two_rear->data);
	    }
	}
	root = root->next;
    }

    zero_rear->next = one_front?one_front : two_front;
    if(one_rear)
	one_rear->next = two_front;
    if(two_rear)
	two_rear->next = NULL;

    return zero_front;
}

void
print_list(node_t *root)
{
    while(root != NULL)
    {
	printf("[%d]-->", root->data);
	root = root->next;
    }
    printf("[NULL]\n");
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
	

int
main()
{
    node_t *root = get_node(2);
    root->next = get_node(0);
    root->next->next = get_node(0);
    root->next->next->next = get_node(2);
    root->next->next->next->next = get_node(0);
    root->next->next->next->next->next = get_node(2);

    print_list(root);
    node_t *ptr = sort_012_nodes(root);
    print_list(ptr);

    root = get_node(2);
    root->next = get_node(0);
    root->next->next = get_node(0);
    root->next->next->next = get_node(2);
    root->next->next->next->next = get_node(0);
    root->next->next->next->next->next = get_node(2); 
    root->next->next->next->next->next->next = get_node(1);
    root->next->next->next->next->next->next->next = get_node(2);
    root->next->next->next->next->next->next->next->next = get_node(1);

    printf("\t\t SECOND TEST\n");
    print_list(root);
    root = sort_012_nodes(root);
    print_list(root);
    return 0;
}
    
