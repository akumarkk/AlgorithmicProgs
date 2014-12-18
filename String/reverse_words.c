#include <stdio.h>
#include <string.h>

void
print_word(char *str)
{
    char *str1=NULL;

    //printf("String : #%s#\n", str);

    if(str[0] == '\0')
	return;

    if((str1=strchr(str, ' ')) != NULL)
    {
	str1[0] = '\0';
	str1 = str1 + 1;
	print_word(str1);
	printf("%s ", str);
    }
    else
	printf("%s ", str);
    return;
}

int
main()
{
    char str[] = "HEllo, Welcome to Washington!";
    printf("GIVEN : %s\n", str);
    print_word(str);

    printf("\n------- END -------\n");
    return 0;
}


