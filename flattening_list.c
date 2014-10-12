#include <stdio.h>
#include <stdlib.h>

typedef struct list_
{
    int		    data;
    struct  list_   *next;  //It should be named as down, which makes more sense.
    struct  list_   *right;
}node_t;


/* Merge two list and return the root to them */
node_t *
merge_lists(node_t *list1, node_t *list2)
{
    node_t  *list=NULL, *root=NULL;

    if(list1 == NULL || list2==NULL)
	return NULL;
    
    if(list1->data < list2->data)
    {
	list = list1;
	list1 = list1->next;
    }
    else
    {
	list = list2;
	list2 = list2->next;
    }
    root = list;

    while(list1 != NULL && (list2!=NULL))
    {
	if(list1->data < list2->data)
	{
	    list->next = list1;
	    list1 = list1->next;
	}
	else
	{
	    list->next = list2;
	    list2 = list2->next;
	}

	list = list->next;
    }
    if(list1 != NULL)
    {
	list->next = list1;
    }
    else
	list->next = list2;
    
    return root;
}

node_t *
flatten_list(node_t *un_list)
{
    node_t *root=NULL;

    root = un_list;
    un_list = un_list->right;

    while(un_list != NULL)
    {
	root = merge_lists(root, un_list);
	un_list = un_list->right;
    }

    return root;
}

void
print_list(node_t *root)
{
    if(root == NULL)
	return;
    while(root!=NULL)
    {
	printf("[%d]-->", root->data);
	root = root->next;
    }
    printf("NULL\n");
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    tmp->right = NULL;
    return tmp;
}

int
main()
{
    node_t *root = get_node(0);
    root->next = get_node(7);
    root->next->next = get_node(8);
    root->next->next->next = get_node(30);

    root->right = get_node(10);
    root->right->next = get_node(20);

    root->right->right = get_node(19);
    root->right->right->next = get_node(22);
    root->right->right->next->next = get_node(50);

    root->right->right->right = get_node(28);
    root->right->right->right->next = get_node(35);
    root->right->right->right->next->next = get_node(40);
    root->right->right->right->next->next->next = get_node(45);

    node_t *tmp = root;
    while(tmp != NULL)
    {
	print_list(tmp);
	tmp = tmp->right;
    }

    printf("FLATTENED LIST : \n");
    root= flatten_list(root);
    print_list(root);
    printf("Done....\n");

    return 0;
}

