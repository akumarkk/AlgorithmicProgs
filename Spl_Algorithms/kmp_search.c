/* KMP Algorithm :
 *
 *	    - If there is no match, there is no need to go back to i-j positions and start freshly
 *	    - If there is no match 
 *		    o Example : pattern = P A R T I C I P A T E
 *				text    = P A R T I C I P A Y E P A R T I C I P A T E
 *		      IN THIS CASE, THERE IS A MIS MATCH AT (T) AND (Y). SINCE "PA" IS A PREFIX OF PATTERN,
 *		      WHICH IS THE SUFFIX IN TEXT ENDING AT POSITION i-1, J HAVE TO GO BACK TO j = t[j] + 1
 *		      TO START COMPARING.
 *	    - KMP uses this technique to reduce number of comparisions.
 *	    - Worst-case effificiency is 2*sizeof(text)
 *	    - Worst-case efficiency of brute-force is sizeof(pattern)*sizeof(text)
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t[100];

int
build_kmp_table(int *t, char *pattern)
{   
    int len= strlen(pattern);

    t[0] = -1;
    t[1] = 0;
    int pos = 2, cnd = 0;
    while(pos < len)
    {
	if(pattern[pos - 1] == pattern[cnd])
	{
	    cnd++;
	    t[pos] = cnd;
	    pos++;
	}
	else if(cnd > 0) // After some matching sub sequence
	{
	    printf("cnd>0 is hit for comparision (%c) == (%c)\n", pattern[pos - 1], pattern[cnd]);
	    // Not sure about the below statement
	    cnd = t[cnd];
	    t[pos] = 0;
	    pos++;
	}
	else
	{
	    t[pos] = 0;
	    pos++;
	}
    }
    return 0;
}

char *
kmp_search(char *text, char *pattern)
{
    int i,j;
    int len1 = strlen(text);
    int len2 = strlen(pattern);

    for(i=0,j=0; i<len1 && j<len2 ; i++)
    {
	while((j>=0) && text[i] != pattern[j])
	    j = t[j];
	j++;
    }
    if(j == len2)
	return text+i-j;

    return text;
}

int
main()
{
    char *ptr = NULL;
    char text[1024], pattern[100];
    
    printf("text :");
    scanf("%s", text);

    printf("Pattern : ");
    scanf("%s", pattern);

    printf("text : %s\nPattern : %s\n", text, pattern);

    build_kmp_table(t, pattern);

    printf("KMP Lookup Table :\n");
    for(int i=0; i<strlen(pattern); i++)
	printf("%d   ", t[i]);
    printf("\n");

    ptr = kmp_search(text, pattern);
    printf("Found : %s\n", ptr);
    return 0;
}
