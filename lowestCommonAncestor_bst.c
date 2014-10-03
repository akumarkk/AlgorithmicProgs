#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	node_
{
    int		    data;
    struct  node_   *left;
    struct  node_   *right;
}node_t;


node_t *
lowest_common_ancestor(node_t *root, int n1, int n2)
{
    node_t *tmp = NULL;

    if(root == NULL)
	return NULL;

    tmp = root;
    while(tmp != NULL)
    {
	if(((tmp->data < n1) && (tmp->data > n2)) ||
	    ((n1 < tmp->data) && (n2 >tmp->data)))
	{
	    return tmp;
	}
	else if((tmp->data == n1) || (tmp->data == n2))
	    return tmp;
	else if((n1 < tmp->data) && (n2 < tmp->data))
	    tmp = tmp->left;
	else if((n1 > tmp->data) && (n2 > tmp->data))
	    tmp = tmp->right;
    }

    // Normally we should not reach here.
    return root;
}


node_t *get_node(int data)
{
    node_t *tmp = malloc(sizeof(struct node_));
    tmp->left = NULL;
    tmp->right = NULL;
	tmp->data = data;
    return tmp;
}

int
main()
{
    int n1=0, n2=0;
    node_t *root = get_node(20);
    node_t *tmp = NULL;

    root->left = get_node(8);
    root->right = get_node(22);
    root->left->left = get_node(4);
    root->left->right = get_node(12);
    root->left->right->left = get_node(10);
    root->left->right->right = get_node(14);

    printf("n1 and n2:");
    scanf("%d%d", &n1, &n2);

    tmp = lowest_common_ancestor(root, n1, n2);
    printf("LCA = %d\n", tmp->data);

    return 0;
}
	    
