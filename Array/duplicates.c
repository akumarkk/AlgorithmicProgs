/* This is going to work only when the elements in the array are in the range 1 to n.
 * An arbitrary array of random values can not be solved using the below solution
 */

#include <stdio.h>
#include <stdlib.h>
 
void printRepeating(int arr[], int size)
{
  int i;
  printf("The repeating elements are: \n");
  for (i = 0; i < size; i++)
  {
    if (arr[abs(arr[i])] >= 0)
    {
	printf("Index %d    negative %d\n", i, arr[abs(arr[i])]);
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    else
      printf(" %d ", abs(arr[i]));
  }
}
 
int main()
{
  int arr[] = {1, 2, 3, 1, 3, 6, 6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  printf("\n---- END ----\n");
  return 0;
}
