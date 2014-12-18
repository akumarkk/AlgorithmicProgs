#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int data;
    struct node_ *next;
}node_t;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void
print_list(node_t *node)
{
    while(node != NULL)
    {
	printf("[%d]-->", node->data);
	node = node->next;
    }
    printf("[NULL]\n");
    return;
}


node_t *
pairwise_swap(node_t *node)
{
    node_t *prev = NULL;
    node_t *tmp, *first=node, *second;

    if(node == NULL || node->next == NULL)
	return node;

    node_t *root = second = node->next;


    while(first != NULL || second != NULL )
    {
	tmp = second->next;
	second->next = first;
	prev = first;
	first = tmp;
	second = first?first->next:NULL;
	prev->next = second;
	printf("first = %d	second = %d\n", first?first->data:9999, second?second->data:9999);
    }

    return root;
}

int
main()
{
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);

    print_list(root);
    root = pairwise_swap(root);
    print_list(root);

    return 0;
}
