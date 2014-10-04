#include <stdio.h>
#include <stdlib.h>

typedef struct tree_
{
    int		    data;
    struct  tree_   *left;
    struct  tree_   *right;
}tree_t;

/* SumTree() : Return Sum of left subtree and right subtree
 *	       if all the subtrees have satisfied teh rule.
 */

int
SumTree(tree_t *root)
{
    int left=0;
    int	right=0;

    printf("root = %d\n", root?root->data : 0);

    if(root == NULL)
	return 0;
    if(root->left == NULL && (root->right == NULL))
	return root->data;

    left = SumTree(root->left);
    //if(left != root->left->data)
    //	return 0;
    right = SumTree(root->right);
    //if(right != root->right->data)
    //	return 0;

    int sum = right + left;
    printf("left=%d \tright=%d \tsum=%d\n", left, right, sum);
    if(root->data == sum)
	return (sum + root->data);

    return -1;
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
    tree_t *root = get_node(70);

    root->left = get_node(20);
    root->left->left = get_node(12);
    root->left->right = get_node(8);

    root->right = get_node(15);
    root->right->left = get_node(7);
    root->right->right = get_node(7);

    int sum = SumTree(root);
    if(sum != -1)
	printf("It is Sum tree.. Sum=%d\n", sum);
    else
	printf("Not a Sun Tree\n");

    root  = get_node(26);
    root->left         = get_node(10);
    root->right        = get_node(3);
    root->left->left   = get_node(4);
    root->left->right  = get_node(6);
    root->right->right = get_node(3);
	sum = SumTree(root);
    if(sum != -1)
	printf("It is Sum tree.. Sum=%d\n", sum);
    else
	printf("Not a Sun Tree\n");

    return 0;
}


