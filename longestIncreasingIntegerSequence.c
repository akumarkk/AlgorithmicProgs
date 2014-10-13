#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef struct subsequence_
{
    int	    *ptr[50];
    int	    len[50];
} seq_info;


int
get_max(int *a, int n)
{
    int i=1;
    int max=a[0];
    int pos=0;

    for(int k=0; k<n; k++)
	printf("%d - ", a[k]);
    printf("\n");
    while(i<n)
    {
	if(a[i] > max)
	{
	    max = a[i];
	    pos = i;
	}
	i++;
    }
    printf("max = %d \tpos = %d\n", max, pos);
    return pos;
}

int
longest_increasing_sequence(int *a, int n)
{
    int	    i=0;
    bool    first = TRUE;
    int	    j=0;
    int	    *ptr = NULL;
    seq_info *seq = malloc(sizeof(seq_info));

    while( i<n )
    {
	while(a[i] <= a[i+1] && (i<n))
	{
	    if(first)
	    {
		seq->ptr[j] = a+i;
		first = FALSE;
		printf("Start : %d\n", a[i]);
	    }
	    seq->len[j]++;
	    i++;
	}
	i++;
	if(i<n)
	    seq->len[j]++;
	j++;
	first = TRUE;
    }

    i = get_max(seq->len, j+1);
    ptr = seq->ptr[i];
    printf("Longest sub-sequence :\n");
    for(j=0; j<seq->len[i]; j++)
    {
	printf("%d\t", ptr[j]);
    }
    printf("\n");

    return 0;
}

	    
int
main()
{
    int a[] = {10, 20, 30, 3, 4, 5, 6, 9, 1, 2, 3, 4, 5 };

    for(int i=0; i<13; i++)
	printf("%d  ", a[i]);
    printf("\n");
    longest_increasing_sequence(a, 13);
    return 0;
}

