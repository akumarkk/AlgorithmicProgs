#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int		data;
    struct node_ *left;
    struct node_ *right;
}node_t;


void
traverse_leaves(node_t *root)
{
    if(root == NULL)
	return;
    if(root->left == NULL || root->right == NULL)
	printf("#[%d]    ", root->data);

    traverse_leaves(root->left);
    traverse_leaves(root->right);
}


void
traverse_right(node_t *root)
{
    if(root && root->right)
    {
	traverse_right(root->right);
	printf("[%d]    ", root->data);
    }
}

void
boundary_traversal(node_t *root)
{
    node_t *tmp=root, *tmp1=root;
    
    while(tmp->left != NULL)
    {
	printf("[%d]   ", tmp->data);
	tmp = tmp->left;
    }

    traverse_leaves(root);
    
    /* This is going to print tree right nodes in clock wise direction which is not required.
     * so using traverse_right(node_t *root) which will print right nodes in anti-clockwise 
     * direction.
     */
    /*
    while(tmp1->right != NULL)
    {
	printf("[%d]    ", tmp1->data);
	tmp1 = tmp1->right;
    }
    */
    traverse_right(tmp1);

    printf("[NULL]\n");
    return;
}


node_t *
get_node(int data)
{
    node_t *tmp= malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}



int
main()
{
    node_t *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    
    root->right->left = get_node(6);
    root->right->right = get_node(7);
    root->right->right->left = get_node(13);
    root->right->right->right = get_node(12);

    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->left->right->right = get_node(11);
    root->left->right->left = get_node(10);
    root->left->right->left->left = get_node(14);
    root->left->right->left->right = get_node(15);
    root->left->left->left = get_node(8);
    root->left->left->right = get_node(9);
    root->left->left->right->left = get_node(16);

    printf("BOUNDARY TRAVERSAL : \n");
    boundary_traversal(root);
    printf("END...\n");
    return 0;
}
