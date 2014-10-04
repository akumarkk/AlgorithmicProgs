/*
 * Check for Children Sum Property in a Binary Tree.
 * Given a binary tree, write a function that returns true if the tree satisfies below property.
 *
 * For every node, data value must be equal to sum of data values in left and right children. 
 * Consider data value as 0 for NULL children. Below tree is an example.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_ 
{
    int data;
    struct node_ *left;
    struct node_ *right;
}tree_t;


int
check_sum_property(tree_t *root)
{
    int sum=0, left=0, right=0;

    if((root == NULL) || (root->left == NULL &&(root->right == NULL)))
	return 1;

    sum = (root->left ?root->left->data :root->right->data) +
		(root->right ? root->right->data : root->left->data);
    printf("Sum = %d  \tdata = %d\n", sum, root->data);
    
    if(sum == root->data)
    {
	right = check_sum_property(root->left);
	left = check_sum_property(root->right);
    }
    else
	return 0;
    
    if(right && left)
	return 1;
    else
	return 0;
}


tree_t *
get_node(int data)
{
    tree_t *tmp = malloc(sizeof(tree_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}


int
main()
{
    tree_t *root = get_node(50);

    root->left = get_node(20);
    root->right = get_node(30);

    root->left->left = get_node(10);
    root->left->right = get_node(10);
    root->left->right->left = get_node(5);
    root->left->right->right = get_node(5);

    root->left->left->left = get_node(6);
    root->left->left->right = get_node(4);

    if(check_sum_property(root))
	printf("Property satisfied for all the nodes !!!\n");
    else
	printf("Property not satisfied !!!\n");

    return 0;
}


