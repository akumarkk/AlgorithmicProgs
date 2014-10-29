#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int		  data;
    struct node_ *left;
    struct node_ *right;
}node_t;

void
print_morris(node_t *root)
{
    node_t  *tmp=NULL;

    while(root != NULL)
    {
	//printf("Processing node : %d\n", root->data);

	if(root->left == NULL)
	{
	    printf("#[%d]   ", root->data);
	    root = root->right;
	}
	else
	{
	    tmp = root->left;
	    while(tmp->right != NULL && (tmp->right != root))
	    {
		tmp = tmp->right;
	    }

	    if(tmp->right == NULL)
	    {
		tmp->right = root;
		root = root->left;
	    }
	    else if(tmp->right == root)
	    {
		printf("[%d]   ", root->data);
		tmp->right = NULL;
		root = root->right;
	    }
	}
    }

    printf("[NULL]\n");
}

int first = 1;

int 
largest_ind_set(node_t *root)
{
    int count = 0;
    
    if(first)
    {
	count++;
	first = 0;
    }

    if(root->left == NULL && (root->right == NULL))
	return 1;

    if(root->left && (root->left->left))
    {
	count++;
	count+=largest_ind_set(root->left->left);
    }
    else if(root->left)
	count++;

    if(root->right && (root->right->right))
    {
	count++;
	count+=largest_ind_set(root->right->right);
    }
    else if(root->right)
	count++;

    return count;
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(struct node_ ));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int
main()
{
    node_t *root = get_node(10);
    root->left = get_node(20);
    root->right = get_node(30);
	root->right->right = get_node(60);
	root->right->right->left = get_node(160);
	root->right->right->right = get_node(260);
	root->right->right->right->left = get_node(360);

	root->left->left = get_node(40);
	root->left->right = get_node(50);
	root->left->right->left = get_node(70);
	root->left->right->right = get_node(80);

    printf("Given TREE :\n");
    print_morris(root);

    printf("LIS = %d\n", largest_ind_set(root));
    return 0;
}

