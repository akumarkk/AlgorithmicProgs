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
    node_t  *tmp = malloc(sizeof(node_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}

int
sum_of_nodeSequence(node_t *root, int val)
{
    int value=0;
    int left=0, right=0;

    val = val*10 + root->data;
    if(root->left == NULL && (root->right == NULL))
    {
	printf("leaf(%d) sequence = %d\n", root->data, val);
	return val;
    }

    if(root->left == NULL || (root->right == NULL))
    {
	value = root->left ?root->left->data : root->right->data;
	val = val *10 + value;
	printf("leaf(%d) sequence = %d\n", value, val);
	return val;
    }

    left = sum_of_nodeSequence(root->left, val);
    right = sum_of_nodeSequence(root->right, val);

    return left+right;
}


int
main()
{
    int sum=0;
    node_t *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->left->left = get_node(8);
    root->left->right = get_node(5);

    root->right = get_node(3);
    root->right->left = get_node(7);
    root->right->right = get_node(9);
    root->right->left->right = get_node(6);

    sum = sum_of_nodeSequence(root, 0);
    printf("Sum = %d\n", sum);
    return 0;
}

