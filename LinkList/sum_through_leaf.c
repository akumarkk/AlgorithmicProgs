#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int		data;
    struct  node_   *left;
    struct  node_   *right;
}node_t;

#if 0
    void
print_list(node_t *root)
{
    while(root!=NULL)
    {
	printf("[%d]-->", root->data);
	root= root->next;
    }
    printf("[NULL]\n");
}
#endif

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int
sum_through_leaf(node_t *root, int sum)
{
    if(root == NULL)
	return 0;

    if(root->left == NULL && (root->right == NULL))
    {
	printf("Leaf(%d) sum = %d\n", root->data, root->data+sum);
	return 0;
    }

    sum_through_leaf(root->left, root->data + sum);
    sum_through_leaf(root->right, root->data + sum);
    return 0;
}

int
main()
{
    node_t *root = get_node(10);
    root->left = get_node(6);
    root->left->left = get_node(1);
    root->left->right = get_node(2);
    root->left->left->left = get_node(9);

    root->right = get_node(7);
    root->right->left = get_node(3);
    root->right->right = get_node(4);
    root->right->left->right = get_node(7);

    sum_through_leaf(root, 0);
    return 0;
}

