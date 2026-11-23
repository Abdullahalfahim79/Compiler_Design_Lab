#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /* table of C keywords used for comparison */
    char keyword[20][20] = {"int","float","const","short","struct",
        "signed","unsigned","double","break","long","char","for","if",
        "switch","else","while","void","typedef","goto","enum"};
    char a[1000];
    int i, flag = 0;

    printf("Enter a word (type ~ then press Enter to stop):\n");
    scanf(" %[^~]", a);

    /* step 1: check whether the word is a keyword */
    for (i = 0; i < 20; i++)
        if (strcmp(keyword[i], a) == 0)
            flag = 1;

    if (flag == 1)
    {
  printf("\n%s is a Keyword\n", a);
        return 0;
    }

    /* step 2: check identifier rules */
    flag = 0;
    if (a[0] == '_' || isalpha(a[0]))   /* first char: letter or '_' */
    {
        for (i = 1; a[i] != '\0'; i++)  /* rest: letter, digit or '_' */
            if (!isalnum(a[i]) && a[i] != '_')
                flag = 1;
    }
    else
        flag = 1;

    if (flag == 0)
        printf("\n%s is a valid Identifier\n", a);
    else
        printf("\n%s is Not a valid Identifier\n", a);
    return 0;
}
