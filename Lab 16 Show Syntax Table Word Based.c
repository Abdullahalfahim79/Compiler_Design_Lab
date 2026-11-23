#include <stdio.h>

int main()
{
    char in[1000];
    char word[100];

    int i = 0;
    int j = 0;
    int start;

    printf("Enter the string (# to finish):\n");
    scanf("%[^#]", in);

    printf("\nInput String: %s\n", in);

    printf("\n================================================\n");
    printf("| Index | Word       | Type          | Length |\n");
    printf("================================================\n");

    while (in[i] != '\0')
    {
        /* Skip spaces */
        while (in[i] == ' ' || in[i] == '\n' || in[i] == '\t')
        {
            i++;
        }

        if (in[i] == '\0')
            break;

        start = i;
        j = 0;

        /* Collect a word */
        while (in[i] != ' ' &&
               in[i] != '\n' &&
               in[i] != '\t' &&
               in[i] != '\0')
        {
            word[j++] = in[i++];
        }

        word[j] = '\0';

        /* Identify word type */
        if (word[0] >= '0' && word[0] <= '9')
        {
            printf("| %5d | %-10s | Number        | %6d |\n",
                   start, word, j);
        }
        else if ((word[0] >= 'A' && word[0] <= 'Z') ||
                 (word[0] >= 'a' && word[0] <= 'z'))
        {
            printf("| %5d | %-10s | Identifier    | %6d |\n",
                   start, word, j);
        }
        else if (word[0] == '+' || word[0] == '-' ||
                 word[0] == '*' || word[0] == '/')
        {
            printf("| %5d | %-10s | Arithmetic Op | %6d |\n",
                   start, word, j);
        }
        else
        {
            printf("| %5d | %-10s | Symbol        | %6d |\n",
                   start, word, j);
        }
    }

    printf("================================================\n");

    return 0;
}
