#include <stdio.h>
#include <string.h>

int
main()
{
    char str[200] = "";
    int  i,j;
    printf("Enter String: ");
    scanf("%s", str);

    i=0;
    j=strlen(str);

    while(i < j)
    {
	/* Basically we have to swap first and last items */
	str[j] = str[i];
	str[i] = str[j-1];
	i++; j--;
    }

    printf("Reversed String : %s\n", str);
    return 0;
}
