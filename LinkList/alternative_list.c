#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int data;
    struct node_ *next;
}node_t;


node_t *
alternative_list(node_t *root)
{
    node_t *tmp1, *tmp2, *first, *second;
    if(root == NULL)
	return NULL;

    if(root->next == NULL)
	return root;

    first = tmp1 = root;
    second = tmp2 = root->next;

    while(tmp1->next != NULL && (tmp2->next != NULL))
    {
	//printf("tmp1 = %d tmp2=%d\n",tmp1->data, tmp2->data); 
	tmp1->next = tmp2->next;
	tmp1 = tmp1->next;
	tmp2->next = tmp1->next;
	tmp2 = tmp2->next;
    }
	tmp1->next = second;

    return first;
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
    return;
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
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);

    print_list(root);
    root = alternative_list(root);
    print_list(root);

    node_t *tmp = get_node(5);
    tmp->next = root;
    print_list(tmp);
    tmp = alternative_list(tmp);
    print_list(tmp);

    return 0;
}
