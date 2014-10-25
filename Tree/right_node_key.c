#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_
{
    int	    data;
    struct node_ *left;
    struct node_ *right;
}node_t;


typedef struct queue_
{
    void    **items;
    int	    size;
    int	    front;
    int	    rear;
    int	    q_type;
}queue_t;



int
is_empty(queue_t    *q)
{
    if(q==NULL)
    {
	printf("Invalid Queue!!!\n");
	return 0;
    }

    if(q->rear < 0)
	return 1;
    return 0;
}

void *
get_front(queue_t *q)
{
    if(is_empty(q))
	return NULL;

    return q->items[q->front];
}

int
enqueue(queue_t *q, void *data)
{
    if(q->rear >= q->size)
    {
	printf("Queue has reached its maximum size\n");
	return -1;
    }

    q->rear++;
    q->items[q->rear] = data;

    print_queue(q);
    return 0;
}

int
dequeue(queue_t	*q)
{
    if(is_empty(q))
    {
	printf("Dequeue failed!!! Queue is already empty.\n");
	return -1;
    }
    
    q->front++;
    if(q->front > q->rear)
    {
	q->front = 0;
	q->rear = -1;
    }
    return 0;
}

int
init_queue(queue_t *q, int datatype)
{
    q->front = 0;
    q->rear = -1;
    q->q_type = datatype;

    if(datatype == 1)
	q->items = malloc(sizeof(int *) * q->size);
    else
	q->items = malloc(sizeof(node_t *) * q->size);
    return 0;
}


int
print_queue(queue_t *q)
{
    if(is_empty(q))
    {
	printf("Queue is empty!!!\n");
	return -1;
    }

    printf("\n------------ START Q -------------\n");

    if(q->q_type == 1)
    {
	for(int i=q->front; i<q->rear; i++)
	    printf("%d\t", *(int *)(q->items[i]));
    }
    else
    {
	for(int i=q->front; i<= q->rear; i++)
	    printf("%d\t", ((node_t *)(q->items[i]))->data);
    }
    printf("\n---------- Q END -----------------\n");
    
    return 0;
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left =	NULL;
    tmp->right = NULL;
    return tmp;
}


node_t *
get_right_key(queue_t *q, node_t *root, int key)
{
    node_t *tmp=NULL;
    node_t *marker = get_node(-9999);

    enqueue(q, root);
    enqueue(q, marker);
    while(!is_empty(q))
    {
	tmp = get_front(q);
	dequeue(q);
	printf("Processing node	    :	%d\n", tmp->data);

	/*If Queue is empty and last node is marker,
	 * then there are no nodes to process.
	 * Return NULL.
	 */
	if(tmp== marker && is_empty(q))
	{
	    return NULL;
	}
	else if (tmp == marker)
	{
	    printf("Reached Marker ...\n");
	    enqueue(q, marker);
	    continue;
	}

	if(tmp->data == key)
	{
	    node_t *tmp1 = get_front(q);
	    printf("Returning node  :	%d\n", tmp1->data);

	    if(tmp1 != NULL && (tmp1 == marker))
		return NULL;
	    return tmp1;
	}

	if(tmp->left)
	{
	    enqueue(q, tmp->left);
	    printf("\tEnqueing	:   %d\n", tmp->left->data);
	}

	if(tmp->right)
	{
	    enqueue(q, tmp->right);
	    printf("\tEnqueing	:   %d\n", tmp->right->data);
	}
    }

    return NULL;
}


void
print_tree(node_t *root)
{
    if(root == NULL)
	return ;
    print_tree(root->left);
    printf("[%d]   ", root->data);
    print_tree(root->right);
}

int
main()
{
    queue_t *q = malloc(sizeof(queue_t));
    init_queue(q, 2);
    q->size = 50;

    node_t *root = get_node(10);
    root->right = get_node(30);
    root->right->left = get_node(80);
    root->right->right = get_node(90);
    root->right->right->right = get_node(100);

    root->left = get_node(20);
    root->left->left = get_node(40);
    root->left->right = get_node(50);
    root->left->right->left = get_node(60);
    root->left->right->right = get_node(70);

    print_tree(root);

    printf("\n Getting Key...\n");
    node_t  *tmp = get_right_key(q, root, 70);
    if(tmp == NULL)
	printf("No Right Key found\n");
    else
	printf("Right Key   :	%d\n", tmp->data);

    return 0;
}
