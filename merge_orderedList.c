#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int		    data;
    struct node_    *next;
}node_t ;


node_t *
merge_orderedList(node_t *list1, node_t *list2)
{
    node_t *root=NULL, *tmp=NULL;
    
    if(list1->data < list2->data)
    {
	root = list1;
	list1 = list1->next;
    }
    else
    {
        root = list2;
	list2 = list2->next;
    }
    
    tmp = root;
   
    while(list1 !=NULL && (list2 != NULL))
    {
	if(list1->data < list2->data)
	{
	    tmp->next = list1;
	    list1 = list1->next;
	}
	else
	{
	    tmp->next = list2;
	    list2 = list2->next;
	}
	tmp = tmp->next;

    }
    if(list1 != NULL)
    {
	tmp->next = list1;
    }
    else
	tmp->next = list2;

    return root;
}

node_t *get_node(int data)
{
    node_t *tmp = malloc(sizeof(struct node_));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void
print_list(node_t *list)
{
    while(list != NULL)
    {
	printf("[%d]-->", list->data);
	list = list->next;
    }
    printf("NULL\n");
    return;
}

int
main()
{
    node_t *list1=NULL, *list2= NULL;
    list1 = get_node(10);
    list1->next = get_node(20);
    list1->next->next = get_node(30);
    list1->next->next->next = get_node(40);
    list1->next->next->next->next = get_node(750);

    list2 = get_node(5);
    list2->next = get_node(15);
    list2->next->next = get_node(21);
    list2->next->next->next = get_node(36);
    list2->next->next->next->next = get_node(39);
    list2->next->next->next->next->next = get_node(200);

    print_list(list1);
    print_list(list2);

    node_t *merge = merge_orderedList(list1, list2);
    print_list(merge);

    return 0;
}
