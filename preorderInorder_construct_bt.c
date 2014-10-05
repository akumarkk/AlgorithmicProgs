#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int	    data;
    struct  node_   *left;
    struct  node_   *right;
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


int
find(int *array, int start, int end, int key)
{
    int i = 0;
    for(i=start; i<=end; i++)
    {
	if(array[i] == key)
	    return i;
    }
    return -1;
}

node_t *
construct_tree(int *inorder, int in_start, int in_end, int *preorder)
{
    static int pre_index = 0;
    int in_index = 0;

    if(pre_index > 12)
	return NULL;

    /* This is when there is no right sub-tree for a given node.
     * When there is no right sub-tree, in_index+1 goes beyond in_end.
     */
    if(in_start > in_end)
	return NULL;

    node_t *root = get_node(preorder[pre_index++]);
    
    printf("in_start=%d \tin_end=%d\n", in_start, in_end);
    printf("node :%d(%c) pre_index :%d \n", root->data, root->data, pre_index);   
    if(in_start == in_end)
    {
	printf("\n");
       return root;
    }

    in_index = find(inorder, in_start, in_end, root->data);
    printf("in_index = %d \tleft =(%d, %d) \tright=(%d, %d)\n\n", in_index, in_start, in_index-1, in_index+1, in_end);
    root->left = construct_tree(inorder, in_start, in_index-1, preorder);
    root->right = construct_tree(inorder, in_index+1, in_end, preorder);

    return root;
}

void
print_inorder(node_t *root)
{
    if(root == NULL)
	return;
    print_inorder(root->left);
    printf("%c   ", root->data);
    print_inorder(root->right);
    return;
}

void
print_preorder(node_t *root)
{
    if(root == NULL)
	return;
    printf("%c   ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
    return;
}


int
main()
{
    int inorder[] = { 'c', 'a', 'd', 'n','e', 'b','m', 'f', 'o', 'h', 'g', 'j', 'h'};
    int preorder[] = {'m', 'n', 'a', 'c','d', 'b','e', 'o', 'f', 'g', 'h', 'j', 'h'};

    node_t *root = construct_tree(inorder, 0, 12, preorder);

    print_inorder(root);
    printf("\n");
    print_preorder(root);
    printf("\n");

    return 0;
}
