#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node_
{
    int		    data;
    struct  node_   *next;
}node_t;


node_t *
reverse_list(node_t *root)
{
    node_t *tmp=NULL, *curr=NULL, *prev=NULL;

    if(root == NULL || root->next == NULL)
	return root;

    tmp = root->next;
    root->next = NULL;
    prev = root;
    while(tmp != NULL)
    {
	curr = tmp;
	tmp = tmp->next;
	curr->next = prev;
	prev = curr;
    }

    return curr;
}

node_t *get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

bool
check_palindrome(node_t *root)
{
    node_t  *root2=NULL, *mid=NULL, *fast=NULL, *prev=NULL;

    if(root==NULL || root->next == NULL)
	return TRUE;


    mid = root;
    fast = root;
    while(fast && fast->next)
    {
	prev = mid;
	mid = mid->next;
	fast = fast->next->next;
    }

    /* If there are odd number of nodes, we dont have to consider the exact mid one */
    if(fast != NULL)
    {
	prev = mid;
	mid = mid->next;
    }

    print_list(mid);
    mid = reverse_list(mid);
    root2 = mid;
    print_list(mid);
    while(mid != NULL)
    {
	if(mid->data != root->data)
	{
	    root2 = reverse_list(root2);
	    prev->next = root2;
	    return FALSE;
	}
	mid = mid->next;
	root = root->next;
    }

    root2 = reverse_list(root2);
    prev->next = root2;
    
    return TRUE;
}


void 
print_list(node_t *root)
{
    while(root!=NULL)
    {
	printf("[%d]-->", root->data);
	root = root->next;
    }
    printf("[NULL]\n");
}

int
main()
{
    bool rcode;
    node_t *root= get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(50);
    root->next->next->next = get_node(20);
    root->next->next->next->next = get_node(10);
    
    print_list(root);
    rcode = check_palindrome(root);
    if(rcode == TRUE)
	printf("\n\t\tPALINDROME\n");
    else
	printf("\n\t\tNON PALINDROME\n");

    print_list(root);

    printf("\n\t\tSecond test :\n");
    root->next->next->next->next->next = get_node(10);
    
    print_list(root);
    rcode = check_palindrome(root);
    if(rcode == TRUE)
	printf("\n\t\tPALINDROME\n");
    else
	printf("\n\t\tNON PALINDROME\n");

    print_list(root);
    return 0;
}
