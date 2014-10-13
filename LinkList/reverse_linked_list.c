#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int		    data;
    struct node_    *next;
}node_t;

node_t *
reverse_list(node_t *root)
{
    node_t *tmp=NULL, *curr=NULL, *prev=NULL;\
    tmp = root;

    if(root == NULL || root->next== NULL)
	return root;

    tmp = tmp->next;
    root->next = NULL;
    prev = root;

    while(tmp != NULL)
    {
	curr = tmp;
	tmp = tmp->next;
	curr->next = prev;
	prev = curr;
    }

    return curr;
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
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);

    print_list(root);
    root = reverse_list(root);
    printf("Reversed list :\n");
    print_list(root);

    return 0;
}

