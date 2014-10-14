#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int	    data;
    struct node_    *next;
}node_t;

void
print_list(node_t *root)
{
    while(root != NULL)
    {
	printf("[%d]-->", root->data);
	root = root->next;
    }
    printf("[NULL]\n");
}

node_t *
add_list(node_t *list1, node_t *list2, int *carry)
{
    node_t *tmp=NULL;
    if(list1 == NULL)
	return NULL;

    tmp = malloc(sizeof(node_t));
    tmp->next = add_list(list1->next, list2->next, carry);
    tmp->data = (list1->data + list2->data + *carry) % 10;
    *carry = (list1->data + list2->data + *carry) / 10;
    return tmp;
}

int diff;
node_t *add_remaining(node_t *list, node_t *sum, int *carry)
{
    static int count;
    node_t *tmp = NULL;

    if(count == diff)
	return sum;

    count ++;
    tmp = malloc(sizeof(node_t));
    tmp->next = add_remaining(list->next, sum, carry);
    tmp->data = (list->data + *carry) % 10;
    *carry = (list->data + *carry) / 10;

    return tmp;
}

node_t *
add_two_lists(node_t *list1, node_t *list2)
{
    node_t  *tmp=NULL;
    int	    size1=0, size2=0;
    node_t  *sum=NULL;
    node_t  *first=NULL, *second=NULL;
    int	    carry=0;
    int	    count=0;


    tmp = list1;
    while(tmp!=NULL)
    {
	size1++;
	tmp = tmp->next;
    }

    tmp = list2;
    while(tmp != NULL)
    {
	size2++;
	tmp = tmp->next;
    }

    if(size1 == size2)
	sum = add_list(list1, list2, &carry);
    else
    {
	diff = abs(size1 - size2);
	printf("Diff = %d\n", diff);

	if(size1 < size2)
	{
	    first = list1;
	    second = list2;
	    tmp = list2;
	}
	else
	{
	    first = list2;
	    second = list1;
	    tmp = list1;
	}

	while(count != diff)
	{
	    count++;
	    tmp = tmp->next;
	}

	sum = add_list(first, tmp, &carry);
	sum = add_remaining(second, sum, &carry);
    }

    if(carry)
    {
	tmp = malloc(sizeof(node_t));
	tmp->data = carry;
	tmp->next = sum;
	sum = tmp;
    }

    return sum;
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


int
main()
{
    node_t  *sum = NULL;
    node_t  *list1 = get_node(9);
    list1->next = get_node(8);
    list1->next->next = get_node(9);
    list1->next->next->next = get_node(8);

    node_t  *list2 = get_node(1);
    list2->next = get_node(2);
    list2->next->next = get_node(3);
    list2->next->next->next = get_node(4);

    sum = add_two_lists(list1, list2);
    printf("List1 :\n");
    print_list(list1);

    printf("List2 :\n");
    print_list(list2);

    printf("Sum List :\n");
    print_list(sum);

    printf("\t\t\t SECOND TEST\n");
    list2->next->next->next->next = get_node(5);
    list2->next->next->next->next->next = get_node(6);
    print_list(list2);
    sum = add_two_lists(list1, list2);
    
    printf("List1 :\n");
    print_list(list1);

    printf("List2 :\n");
    print_list(list2);

    printf("Sum List :\n");
    print_list(sum);

    return 0;
}

