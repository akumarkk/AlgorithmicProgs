/* A Product Array Puzzle
 * Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator and in O(n).
 *
 * Example:
 * arr[] = {10, 3, 5, 6, 2}
 * prod[] = {180, 600, 360, 300, 900}
 *
 * Algorithm:
 * 1) Construct a temporary array left[] such that left[i] contains product of all elements on left of arr[i] excluding arr[i].
 * 2) Construct another temporary array right[] such that right[i] contains product of all elements on on right of arr[i] excluding arr[i].
 * 3) To get prod[], multiply left[] and right[].
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prod[1024];

void
build_product_array(int *array, int n)
{
    int i=0, tmp=1;

    for(i=0; i<n; i++)
    {
	printf("prod[%d] = %d \n", i, tmp);
	prod[i] = tmp;
	tmp = tmp * array[i];
	
    }

    tmp = 1;
    for(i=n-1; i>=0; i--)
    {
	printf("prod[%d] = %d \n", i, tmp);
	prod[i] = prod[i] * tmp;
	tmp = tmp * array[i];
    }

}

void
print_array(int *array, int n)
{
    for(int i=0; i<n; i++)
	printf("%d   ", array[i]);
    printf("\n        END \n");
}

int
main()
{
    int i,n, array[100];

    printf("# of elements : ");
    scanf("%d", &n);

    printf("Elements : ");
    for(i=0; i<n; i++)
    {
	scanf("%d", &array[i]);
    }

    build_product_array(array, n);

    print_array(prod, n);
    return 0;
}
