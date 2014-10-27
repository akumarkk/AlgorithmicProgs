#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int		data;
    struct node_ *left;
    struct node_ *right;
}node_t;


node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void
print_inorder_morris(node_t *root)
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
	    if(tmp->right == NULL)
	    {
		tmp->right = root;
		root = root->left;
	    }
	    else
	    {
		printf("[%d]   ", root->data);
		tmp->right = NULL;
		root = root->right;
	    }
	}
    }
    printf("[NULL]\n");
}


int
main()
{
    node_t *root = get_node(10);
    root->left = get_node(20);
    root->right = get_node(30);

    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->left->left->left  = get_node(8);
    root->left->left->right  = get_node(9);
    root->right->left = get_node(6);
    root->right->right = get_node(7);

    print_inorder_morris(root);
    return 0;
}


