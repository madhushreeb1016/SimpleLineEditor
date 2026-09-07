#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char *lines[MAX_LINES];
int lineCount = 0;

void insertLine()
{
    if (lineCount >= MAX_LINES)
    {
        printf("Document is full. Cannot insert more lines.\n");
        return;
    }

    char text[MAX_LENGTH];

    printf("Enter line: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    lines[lineCount] = malloc(strlen(text) + 1);

    if (lines[lineCount] == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(lines[lineCount], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}
void deleteLine()
{
    if (lineCount == 0)
    {
        printf("Document is empty. Nothing to delete.\n");
        return;
    }

    int lineNumber;

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    free(lines[lineNumber - 1]);

    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- Document -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}
void searchText()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    char search[MAX_LENGTH];
    int found = 0;

    printf("Enter text to search: ");
    fgets(search, MAX_LENGTH, stdin);

    search[strcspn(search, "\n")] = '\0';

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}
void countLinesAndWords()
{
    int wordCount = 0;

    for (int i = 0; i < lineCount; i++)
    {
        int inWord = 0;

        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] != ' ' && lines[i][j] != '\t')
            {
                if (inWord == 0)
                {
                    wordCount++;
                    inWord = 1;
                }
            }
            else
            {
                inWord = 0;
            }
        }
    }

    printf("Number of lines: %d\n", lineCount);
    printf("Number of words: %d\n", wordCount);
}
void freeMemory()
{
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }
}
int main()
{
    int choice;

    printf("===== Simple Line Editor =====\n");

    while (1)
    {
        printf("\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Search\n");
        printf("5. Line Count / Word Count\n");
        printf("6. Exit\n"); 
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;
            case 4:
                searchText();
                break;
            case 5:
                countLinesAndWords();
                break;
            case 6:
                freeMemory();
                printf("Exiting editor...\n");
                return 0;
            

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}