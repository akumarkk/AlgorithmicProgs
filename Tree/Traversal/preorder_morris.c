#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int		  data;
    struct node_ *left;
    struct node_ *right;
}node_t;

void
print_preorder_morris(node_t *root)
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
	    /* This node is already processed, just break the link between
	     * Inorder predessor and the current node in question and 
	     * move to left;
	     */
	    if(tmp->right == root)
	    {
		tmp->right = NULL;
		root = root->right;
	    }
	    else
	    {
		/* This is the first time, we are visiting this node.
		 * So link inorder predessor to current in order to know where to return 
		 * return once left subtree is processed.
		 */
		tmp->right = root;
		printf("[%d]   ", root->data);
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

    print_preorder_morris(root);
    return 0;
}

