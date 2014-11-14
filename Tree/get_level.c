#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int	    data;
    struct node_ *left;
    struct node_ *right;
}node_t;


typedef struct queue_
{
    node_t  **items;
    int	    size;
    int	    front;
    int	    rear;
}queue_t;


queue_t *
init_queue()
{
    queue_t *q = malloc(sizeof(queue_t));
    q->front = 0;
    q->rear = -1;
    q->size = 20;

    q->items = malloc(sizeof(node_t *) * 20);
    return q;
}


int
is_empty(queue_t *q)
{
    if((q->rear < 0) || (q->front > q->rear))
	return 1;
    return 0;
}


node_t *
get_front(queue_t *q)
{
    if(is_empty(q))
	return NULL;
    return q->items[q->front];
}


int
enqueue(queue_t *q, node_t *node)
{
    if(q->rear >= q->size)
	return -1;
    q->rear++;
    q->items[q->rear] = node;

    return 0;
}

int 
dequeue(queue_t *q)
{
    if(is_empty(q))
	return -1;
    q->front++;
    if(q->front > q->rear)
    {
	q->front = 0;
	q->rear = -1;
    }
    return 0;
}

void
print_queue(queue_t *q)
{
    if(q == NULL)
    {
	printf("Invalid queue\n");
	return ;
    }

    if(is_empty(q))
    {
	printf("Empty queue...\n");
	return ;
    }
    for(int i=q->front; i<=q->rear; i++)
	printf("[%d]   ", ((node_t *)(q->items[i]))->data);
    printf("NULL\n");

    return;
}

int
test()
{
    int	    op=0;
    node_t *tmp= NULL;
    int	    value;
    queue_t *q = init_queue();

    while(1)
    {
	printf("1. Enqueue \t2. Dequeue \t3.Get Front \t4.exit\n");
	scanf("%d", &op);

	switch(op)
	{
	    case 1: printf("Node value : ");
		    scanf("%d", &value);
		    node_t *tmp = malloc(sizeof(node_t));
		    tmp->data = value;
		    tmp->left = NULL;
		    tmp->right = NULL;
		    enqueue(q, tmp);
		    print_queue(q);
		    break;

	    case 2: tmp = get_front(q);
		    printf("Dequeing [%d]...\n", tmp?tmp->data:9999);
		    dequeue(q);
		    print_queue(q);
		    break;

	    case 3: tmp = get_front(q);
		    printf("Front node : [%d] \n", tmp?tmp->data:9999);
		    break;

	    case 4: print_queue(q);
		    exit(0);
	}
    }
}


int
get_level(node_t *root, int key)
{
    int level = 1;
    node_t  *tmp=NULL;
    node_t *marker = malloc(sizeof(node_t));
    marker->left = NULL;
    marker->right = NULL;

    queue_t *q = init_queue();
    enqueue(q, root);
    enqueue(q, marker);

    while(is_empty(q) == 0)
    {
	tmp = get_front(q);
	dequeue(q);

	printf("Processing node : %d\n", tmp->data);
	if(tmp->data == key)
	    return level;

	if(tmp == marker)
	{
	    if(is_empty(q))
		return level;

	    level++;
	    enqueue(q, marker);
	    continue;
	}

	if(tmp->left)
	    enqueue(q, tmp->left);
	if(tmp->right)
	    enqueue(q, tmp->right);
    }

    return level;
}

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
main()
{
    int given_node = 0, level=0;
    node_t *root = get_node(1);

    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->left->right->left = get_node(8);
    root->left->right->right = get_node(9);

     root->right->left = get_node(6);
     root->right->right = get_node(7);

     printf("Enter node for its level : ");
     scanf("%d", &given_node);

    level = get_level(root, given_node);
    printf("Level of [%d] = %d\n", 8, level);
    return 0;
}
