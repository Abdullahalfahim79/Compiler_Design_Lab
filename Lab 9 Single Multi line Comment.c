#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000], singleLine[1000], multiLine[1000];
    int len, k, i, j = 0, m = 0;
    printf("Enter text/code (type ~ then press Enter to stop):\n");
    scanf(" %[^~]", a);
    len = strlen(a);
    for (k = 0; k < len - 1; k++)
    {
        if (a[k] == '/' && a[k + 1] == '/')
        {
            k += 2;
            while (k < len && a[k] != '\n')
                singleLine[j++] = a[k++];
        }
    }
    singleLine[j] = '\0';
    for (i = 0; i < len - 1; i++)
    {
        if (a[i] == '/' && a[i + 1] == '*')
        {
            i += 2;
            while (i < len - 1 && !(a[i] == '*' && a[i + 1] == '/'))
                multiLine[m++] = a[i++];
        }
    }
    multiLine[m] = '\0';
    printf("\nSingle line comment: %s\n", singleLine);
    printf("Multiple line comment: %s\n", multiLine);
    return 0;
}
