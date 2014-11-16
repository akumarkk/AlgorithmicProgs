#include <stdio.h>
#include <string.h>

int
sort(int *a, int n)
{
    int tmp=0;
    int i = 0;
    build_heap_tree(a, n);
    
    printf("------------ START --------------\n");
    for(i=n-1; i>0; i--)
    {
	tmp = a[0];
	a[0] = a[i];
	a[i] = tmp;
	heapify(a, 0, i);
    }
    return 0;
}

int
build_heap_tree(int *a, int n)
{
    int i=0;

    for(i=(n/2)-1; i>=0; i--)
    {
	printf("\nFirst Parent : [%d]\n", a[i]);
	heapify(a, i, n);
	printf("First Parent : [%d]\n", a[i]);
    }

    printf("Heap Tree : ");
    for(i=0; i<n; i++)
	printf("%d   ", a[i]);

    printf("\n");

    return 0;
}

    
int
heapify(int *a, int start, int n)
{
    int largest=0, tmp=0, lchild=0, rchild=0;
    int end = (n/2) - 1;

    printf("start = [%d]  \tend = [%d]\n", a[start], a[end]);

    while(start <= end)
    {
	lchild = 2*start + 1;
	rchild = 2*start + 2;
	if(rchild <= n-1)
	{
	    if(a[rchild] > a[lchild])
		largest = rchild;
	    else
		largest = lchild;
	}
	else
	    largest = lchild;
	if(a[start] < a[largest])
	{
	    printf("Swapping [%d] and [%d]\n", a[start], a[largest]);
	    tmp = a[start];
	    a[start] = a[largest];
	    a[largest] = tmp;
	    start = largest;
	}
	else
	    break;
    }
    return 0;
}

int
main()
{
    int a[100], n, i;
    printf("Enter # of elements   : ");
    scanf("%d", &n);

    printf("Elements : ");
    for(i=0; i<n; i++)
	scanf("%d", a+i);

     printf("\nBefore Sorting elements : ");
     for(i=0; i<n; i++)
	 printf("%d   ", a[i]);

    sort(a, n);
    
    printf("\nSorted elements : ");
    for(i=0; i<n; i++)
	printf("%d   ", a[i]);
    
    printf("\n");
    return 0;
}


