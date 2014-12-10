#include <stdio.h>
#include <string.h>

char str1[100];
char str2[100];

int
maximum(int a, int b)
{
    if(a > b)
	return a;
    else
	return b;
}


    
int
longest_common_subsequence(int end1, int end2)
{
    int i=0, j=0;
    int LCS[end1+1][end2+1];

    for(i=0; i<=end1; i++)
    {
	for(j=0; j<=end2; j++)
	{
	    if(i==0 || j==0)
		LCS[i][j] = 0;
	    /* here (i-1)(j-1) indicates the position of current elements.
	     * When ever there is a case lcs(0,0), it goes to (lcs(0, -1), lcs(-1, 0)). To avoid this boundary condition, we need to have extra row and extra column.
	     *
	     * here [i,j] is the memory position where [i-1,j-1] are stored.
	     */
	    else if(str1[i-1] == str2[j-1])
		LCS[i][j] = LCS[i-1][j-1] + 1;
	    else
		LCS[i][j] = maximum(LCS[i][j-1], LCS[i-1][j]);
	}
    }
    return LCS[end1][end2];
}

int
main()
{
    printf("String #1 : ");
    scanf("%s", str1);

    printf("String #2  : ");
    scanf("%s", str2);

    int len = longest_common_subsequence(strlen(str1), strlen(str2));
    printf("Longest common subsequence(%s, %s) = %d\n", str1, str2, len);
    return 0;
}
