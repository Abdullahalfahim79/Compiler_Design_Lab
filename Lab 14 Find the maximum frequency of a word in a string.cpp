#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[1000];
    char words[100][100];

    int i, j = 0, k = 0;
    int stringLength;
    int totalWords = 0;
    int currentFrequency;
    int maximumFrequency = 0;
    int maximumWordIndex = 0;

    printf("Enter a multiline string (end input with #):\n");
    scanf("%[^#]", inputString);

    stringLength = strlen(inputString);

    /* Separate the string into words */
    for (i = 0; i <= stringLength; i++)
    {
        if (inputString[i] != ' ' &&
            inputString[i] != '\n' &&
            inputString[i] != '\0')
        {
            words[j][k] = inputString[i];
            k++;
        }
        else
        {
            if (k > 0)
            {
                words[j][k] = '\0';

                j++;
                totalWords++;
                k = 0;
            }
        }
    }

    /* Compare every word with every other word */
    for (i = 0; i < totalWords; i++)
    {
        currentFrequency = 0;

        for (j = 0; j < totalWords; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                currentFrequency++;
            }
        }

        if (currentFrequency > maximumFrequency)
        {
            maximumWordIndex = i;
            maximumFrequency = currentFrequency;
        }
    }

    printf("\nMaximum Frequency Word: %s\n",
           words[maximumWordIndex]);

    printf("Frequency: %d\n",
           maximumFrequency);

    return 0;
}
