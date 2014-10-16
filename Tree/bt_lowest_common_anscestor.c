#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int		data;
    struct node_ *left;
    struct node_ *right;
}node_t;

node_t *
bt_get_lowest_common_anscestor(node_t *root, int *ancestor, int data1, int data2)
{
    int	    my_ancestor=0;
    node_t *tmp = NULL;
    node_t *left=NULL, *right=NULL;

    if(root == NULL)
	return NULL;
    if(root->left == NULL && root->right == NULL)
    {
	if(root->data == data1 || root->data ==data2)
	    return root;
	else 
	    return NULL;
    }
    printf("Processing node [%d]...\n", root->data);

    left = bt_get_lowest_common_anscestor(root->left, &my_ancestor, data1, data2);
    if(left)
	printf("LEFT at (%d) = %d\n", root->data, left->data);
    
    if(my_ancestor)
    {
	printf("(%d) From left of [%d]  ancestor = %d\n", __LINE__, root->data, left->data);
	*ancestor = 1;
	return left;
    }


    if(left && (left->data == data1 || left->data == data2))
    {
	if(root->data == data1 || root->data == data2)
	{
	    printf("(%d) At [%d]  ancestor = %d\n", __LINE__, root->data, root->data);
	    *ancestor = 1;
	    return root;
	}
    }

    right = bt_get_lowest_common_anscestor(root->right, &my_ancestor, data1, data2);
    if(right)
	printf("RIGHT at (%d) = %d\n", root->data, right->data);

    if(my_ancestor)
    {
	printf("(%d) From right of [%d]  ancestor = %d\n", __LINE__, root->data, right->data);
	*ancestor = 1;
	return right;
    }

    if(right && (right->data == data1 || right->data == data2))
    {
	if(root->data == data1 || root->data == data2)
	{
	    printf("(%d) At [%d]  ancestor = %d\n", __LINE__, root->data, root->data);
	    *ancestor = 1;
	    return root;
	}
	else if(left && (left->data == data1 || left->data == data2))
	{
	    printf("(%d) At [%d]  ancestor = %d<---left_right \n", __LINE__, root->data, root->data);
	    *ancestor = 1;
	    return root;
	}
    }

    tmp = left?left : right;
    if(tmp)
	return tmp;

    return NULL;
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

void
print_tree(node_t *root)
{
    if(root == NULL)
	return;
    printf("[%d]   ", root->data);

    print_tree(root->left);
    print_tree(root->right);
}


int
main()
{
    int ancestor = 0;
    int data1, data2;
    node_t *root = get_node(1);

    root->left = get_node(2);
    root->right = get_node(3);
    
    root->left->left = get_node(4);
    root->left->left->left = get_node(6);
    root->left->left->right = get_node(7);
    
    root->left->right = get_node(5);
    root->left->right->left = get_node(8);
    root->left->right->right= get_node(9);

    print_tree(root);
    printf("\ndata1 and data2 : ");
    scanf("%d%d", &data1, &data2);
    
    node_t *ptr = bt_get_lowest_common_anscestor(root, &ancestor, data1, data2);
    if(ancestor)
	printf("\nLowest common ancestor (6) and (7) : %d\n", ptr->data);
    else 
	printf("\nEither of the node is not present !!! - (%d)\n", ptr?ptr->data:-1);

    return 0;
}
