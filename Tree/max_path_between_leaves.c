#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int		 data;
    struct node_ *left;
    struct node_ *right;
}node_t;

void
print_morris(node_t *root)
{
    node_t *tmp = NULL;
    while(root != NULL)
    {
	if(root->left == NULL)
	{
	    printf("[%d]   ", root->data);
	    root = root->right;
	}
	else
	{
	    tmp = root->left;
	    while(tmp->right != NULL && (tmp->right != root))
		tmp = tmp->right;
	    if(tmp->right == root)
	    {
		printf("[%d]  ", root->data);
		tmp->right = NULL;
		root = root->right;
	    }
	    else if(tmp->right == NULL)
	    {
		tmp->right = root;
		root = root->left;
	    }
	}
    }

    printf("[NULL]\n");
}

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
get_max_path_between_leaves(node_t *root, int *max)
{
    int	left=0, right=0;

    if(root == NULL)
	return 0;
    if(root->left == NULL && (root->right == NULL))
	return root->data;

    left = get_max_path_between_leaves(root->left, max);
    right = get_max_path_between_leaves(root->right, max);

    if( (left + right + root->data) > *max)
	*max = (left + right + root->data);

    if(left > right)
	return (left + root->data);
    else
	return (right + root->data);
}


void
test()
{
    int	max=-99999, max_leaf=0;
    node_t *root = get_node(-15);

    root->right = get_node(6);
    root->left = get_node(5);
    root->left->right = get_node(1);
    root->left->left = get_node(-8);
    root->left->left->left = get_node(2);
    root->left->left->right = get_node(6);

    root->right->left = get_node(3);
    root->right->right = get_node(9);
    //root->right->right->left = get_node(9);
    root->right->right->right = get_node(0);
    root->right->right->right->left = get_node(4);
    root->right->right->right->right = get_node(-1);
    root->right->right->right->right->left = get_node(10);

    printf("Given Tree	:\n");
    print_morris(root);

    max_leaf = get_max_path_between_leaves(root, &max);
    printf("\nMax leaf	:   %d\nMax path    :	%d\n", max, max_leaf);
    return ;
}

int
main()
{
    test();
    return 0;
}

