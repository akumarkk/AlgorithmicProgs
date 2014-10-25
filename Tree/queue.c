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


int
main()
{
    int	data=0, op=0;
    queue_t *q = malloc(sizeof(queue_t));
    printf("Size of Queue :");
    scanf("%d", &q->size);

    init_queue(q, 2);

    while(1)
    {
	printf("Enqueue	    -	1 \nDequeue	-   2 \nExit	-   3\n");
	scanf("%d", &op);

	switch(op)
	{
	    case 1: 
	    {
		node_t *node = malloc(sizeof(node_t));
		 printf("Data :");
		scanf("%d", &data);
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		enqueue(q, node);

		print_queue(q);
		break;
	    }

	    case 2: 
	    {
		node_t *node = get_front(q);
		if(node == NULL)
		    printf("Empty Queue\n");
		dequeue(q);
		printf("Dequeing node : %d\n", node?node->data:0);
		break;
	    }

	    case 3: 
	    {
		print_queue(q);
		exit(0);
	    }
	}
    }
    return 0;
}




