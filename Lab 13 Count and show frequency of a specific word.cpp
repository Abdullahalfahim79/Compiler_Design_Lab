#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[1000];
    char targetWord[100];

    int wordEndPositions[1000];
    int wordCount = 0;

    int i, j, k, wordLength;
    int frequency = 0;
    int matchCount;

    printf("Enter a multiline string (end input with #):\n");
    scanf("%[^#]", inputString);

    /* Clear the newline left by scanf */
    getchar();

    printf("Enter the word to check its frequency:\n");
    scanf("%s", targetWord);

    /* Store the positions of spaces and newlines */
    for (i = 0; inputString[i] != '\0'; i++)
    {
        if (inputString[i] == ' ' || inputString[i] == '\n')
        {
            wordEndPositions[wordCount++] = i;
        }
    }

    /* Store the position of the end of the string */
    wordEndPositions[wordCount++] = i;

    j = 0;

    /* Check each word */
    for (i = 0; i < wordCount; i++)
    {
        wordLength = wordEndPositions[i] - j;

        if (wordLength == strlen(targetWord))
        {
            matchCount = 0;

            for (k = 0; k < wordLength; k++)
            {
                if (inputString[j + k] == targetWord[k])
                {
                    matchCount++;
                }
            }

            if (matchCount == strlen(targetWord))
            {
                frequency++;
            }
        }

        j = wordEndPositions[i] + 1;
    }

    printf("\nFrequency of the word '%s' = %d\n",
           targetWord, frequency);

    return 0;
}
