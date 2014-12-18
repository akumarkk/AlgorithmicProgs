#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int data;
    struct node_ *next;
}node_t;

node_t *
merge_list(node_t *tmp1, node_t *tmp2)
{
    node_t *root, *tmp;
    root = tmp1;

    if(tmp1 == NULL)
	return NULL;
    if(tmp2 == NULL)
	return NULL;

    root = tmp = tmp1;
    tmp1 = tmp1->next;
    tmp->next = tmp2;
    tmp = tmp->next;
    tmp2 = tmp2->next;

    printf("%d  %d  %d\n", root->data, root->next->data, tmp?tmp->data:9999);

    while(tmp1 != NULL && tmp2!= NULL)
    {
	tmp->next = tmp1;
	tmp1 = tmp1->next;
	tmp = tmp->next;
	
	tmp->next = tmp2;
	tmp = tmp->next;
	tmp2 = tmp2->next;
	printf("tmp1 = %d     tmp2 = %d\n", tmp1?tmp1->data:9999, tmp2?tmp2->data:9999);
    }

    if(tmp1)
	tmp->next = tmp1;
    else
	tmp->next = tmp2;

    return root;
}

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

    node_t *root1 = get_node(101);
    root1->next = get_node(201);
    root1->next->next = get_node(301);
    print_list(root1);

    root = merge_list(root, root1);
    print_list(root);

    return 0;
}

