#include <stdio.h>
#include <string.h>

char a[100];

int
maximum(int a, int b)
{
    if(a > b)
	return a;
    else
	return b;
}


int
longest_pal_subsequence(int len)
{
    int i=0, j=0;
    int lps[len][len];
    int row=0, col=0;
    
    memset(lps, 0, sizeof(int)*len*len);
    /* Every char is a palindrome of itself. So setting it to 1 */
    for(i=0; i<len; i++)
    	lps[i][i] = 1;

    for(i=1; i<len; i++)
    {
	/* Here j<i, becaue if we take lps(3,4) , we compare till fourth 
	 * element. That is the end.
	 */
	for(j=0; j<(len-i); j++)
	{
	    row = j;
	    col = i + j;

	    if((a[row] == a[col]) && (i==1))
		lps[row][col] = 2;
	    else if(a[row] == a[col])
		lps[row][col] = lps[row+1][col-1] + 2;
	    else
		lps[row][col] = maximum(lps[row+1][col], lps[row][col-1]);
	}

    }

    for(i=0; i<len; i++)
    {
	printf("\n");
	for(j=0; j<len; j++)
	    printf("(%d, %d) = %10d     ", i, j, lps[i][j]);
    }
    printf("\n-------- END OF MATRIX ---------\n");

    return lps[0][len-1];
}


int
main()
{
    printf(" String : ");
    scanf("%s", a);

    printf("Longest palindrome subsequence(%s) = %d\n", a, longest_pal_subsequence(strlen(a)));

    return 0;
}
