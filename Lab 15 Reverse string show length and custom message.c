#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];

    printf("Enter a string to reverse (type ~ then press Enter to stop):\n");
    scanf(" %[^~]", s);

    int len = strlen(s);                /* length is taken before reversing */
    strrev(s);                          /* reverse the string in place */

    printf("\nReverse of the string: %s\n", s);
    printf("Length = %d\n", len);
    return 0;
}

